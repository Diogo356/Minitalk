/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:02:02 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/11 20:32:17 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	g_char;

void	init_char(void)
{
	g_char.bits_shifted_counter = 0;
	g_char.assembled_char = '\0';
}

void	print_pid(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	print_character(int signal)
{
	if (signal == SIGUSR1)
		g_char.assembled_char += (0b00000001 << g_char.bits_shifted_counter);
	if (g_char.bits_shifted_counter == 7)
	{
		ft_putchar(g_char.assembled_char);
		init_char();
		return ;
	}
	g_char.bits_shifted_counter++;
}

void	send_signals(void)
{
	signal(SIGUSR1, print_character);
	signal(SIGUSR2, print_character);
	while (1)
		pause();
}

int	main(void)
{
	init_char();
	print_pid();
	send_signals();
	return (0);
}