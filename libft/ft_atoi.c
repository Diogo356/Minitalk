/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:55:13 by dbelarmi          #+#    #+#             */
/*   Updated: 2023/04/04 15:05:18 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h" 

int	ft_atoi(const char *nptr)
{
	long	num;
	int		i;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' || \
	nptr[i] == '\f' || nptr[i] == '\v' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}
