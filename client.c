/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:18:15 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/04 13:29:14 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(char *message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

void	validate_inputs(int argc, char **argv)
{
	int	aux;
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		print_error("Usage: ./client <PID> <Message>\n");
	aux = ft_strlen(argv[1]);
	pid = ft_atoi(argv[1]);
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			print_error("Error: PID Invalid (PID is not a digit)\n");
		else if (pid <= 0)
			print_error("Error: PID Invalid (PID too small)\n" \
			"PID 0 is reserved by the kernel\n");
		else if (aux > 7)
			print_error("Error: PID Invalid (PID too big)\n");
		i++;
	}
}

void	message_transmit(pid_t pid, char *message)
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
				print_error("ERROR: Kill.\n");
			count_bits++;
			usleep(500);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;
    char	*message;

	validate_inputs(argc, argv);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	message_transmit(pid, message);
	return (0);
}
