/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:17:49 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/14 00:57:45 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//useful from libft
int		ft_atoi(const char *nptr);
void	ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(char *s);
int		ft_isdigit(char c);
void	ft_putnbr(int n);

//functions client;
void	validate_inputs(int argc, char **argv);
void	message_transmit(pid_t pid, char *message);

typedef struct s_char
{
	int		bits_counter;
	char	received_char;
}			t_char;

#endif
