/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:18:15 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/14 15:07:17 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error(char *message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

void	validate_inputs(int argc, char **argv)
{
	int	len;
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		error("Usage: ./client <PID> <Message>\n");
	len = ft_strlen(argv[1]);
	pid = ft_atoi(argv[1]);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			error("Error: PID Invalid (PID is not a digit)\n");
		else if (pid <= 0)
			error("Error: PID Invalid (PID too small)\n" \
			"PID 0 is reserved by the kernel\n");
		else if (len > 7)
			error("Error: PID Invalid (PID too big)\n");
		i++;
	}
}

void	message_transmit(int pid, char *message)
{
	int	i;
	int	count_bits;
	int	kill_status;

	i = 0;
	while (message[i] != '\0')
	{
		count_bits = 0;
		while (count_bits < 8)
		{
			if ((message[i] >> count_bits) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
				error("ERROR: Kill.\n");
			count_bits++;
			usleep(5000);
		}
		i++;
	}
}

void	received_message(int signal)
{
	(void)signal;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	validate_inputs(argc, argv);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, received_message);
	signal(SIGUSR2, received_message);
	message_transmit(pid, message);
	message_transmit(pid, "\n");
	return (0);
}
