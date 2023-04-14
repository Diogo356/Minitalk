/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/14 15:09:16 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	g_char;

void	init_struct(void)
{
	g_char.bits_counter = 0;
	g_char.received_char = '\0';
}

void	received_message(int signal, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	if (signal == SIGUSR1)
		g_char.received_char |= (0b00000001 << g_char.bits_counter);
	if (g_char.bits_counter == 7)
	{
		ft_putchar(g_char.received_char);
		init_struct();
		return ;
	}
	g_char.bits_counter++;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sig.sa_handler = NULL;
	sig.sa_mask = sigset;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = received_message;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	init_struct();
	ft_putstr("Server Initializing...\n");
	ft_putstr("server started...\n");
	ft_putstr("waiting for process print... \n");
	ft_putstr("Server Process: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
