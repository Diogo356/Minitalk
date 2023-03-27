/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:17:49 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/03/26 22:04:37 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//useful from libft
int	    ft_atoi(const char *nptr);
void	ft_putchar(char c);
int	ft_putstr(char *s);
size_t	ft_strlen(char *s);
int	ft_isdigit(char c);

#endif
