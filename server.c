/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/14 01:58:01 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	g_char;

void	init_struct(void)
{
	g_char.bits_counter = 0;
	g_char.received_char = '\0';
}

void	received_message(int signal)
{
	if (signal == SIGUSR1)
		g_char.received_char |= (0b00000001 << g_char.bits_counter);
	if (g_char.bits_counter == 7)
	{
		ft_putchar(g_char.received_char);
		init_struct();
		return ;
	}
	g_char.bits_counter++;
}

int	main(void)
{
	init_struct();
	ft_putstr("Server Initializing...\n");
	ft_putstr("server started...\n");
	ft_putstr("waiting for process print... \n");
	ft_putstr("Server Process: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, received_message);
	signal(SIGUSR2, received_message);
	while (1)
		pause();
	return (0);
}
