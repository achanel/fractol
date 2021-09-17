/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achanel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:13:58 by achanel           #+#    #+#             */
/*   Updated: 2021/09/13 10:13:59 by achanel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		if ((((res * 10) + (*str - '0')) < res) && (neg == 1))
			return (-1);
		else if ((((res * 10) + (*str - '0')) < res) && (neg == -1))
			return (0);
		res = (res * 10) + *str - '0';
		++str;
	}
	res *= neg;
	return ((int)res);
}
