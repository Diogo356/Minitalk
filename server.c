/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/04 18:44:09 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define SEGMENT_SIZE 8

static void	p_error_s(char *message)
{
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

static void	receive_message(int signal, siginfo_t *info, void *ucontext)
{
	static int	shift_bits;
	static char	letter;

	(void)ucontext;
	if (signal == SIGUSR1)
		letter += (0b00000001 << shift_bits);
	if (shift_bits == 7)
	{
		if (letter)
			ft_putchar_fd(letter);
		else
		{
			if (kill(info->si_pid, SIGUSR2))
				p_error_s("Failed to send signal");
		}	
		letter = 0;
		shift_bits = 0;
	}
	else
		shift_bits++;
	if (kill(info->si_pid, SIGUSR1))
		p_error_s("Failed to send signal");
}

int main(void) {
    struct sigaction action;
    action.sa_sigaction = receive_message;
    action.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &action, NULL) == -1 || sigaction(SIGUSR2, &action, NULL) == -1)
        p_error_s("sigaction");
    printf("Listening for messages...%d\n", (int)getpid());
    while (1)
        pause();
    return EXIT_SUCCESS;
}
