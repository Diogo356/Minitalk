/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:30:16 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/11 20:34:34 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr(int n)
{
	unsigned int	aux_n;

	aux_n = 0;
	if (n < 0)
	{
		ft_putchar ('-');
		aux_n = -(n);
	}
	else
		aux_n = n;
	if (aux_n >= 10)
		ft_putnbr (aux_n / 10);
	ft_putchar (aux_n % 10 + '0');
}
