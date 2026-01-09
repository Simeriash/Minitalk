/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:36:39 by julauren          #+#    #+#             */
/*   Updated: 2026/01/09 13:42:41 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static void	ft_error(int err)
{
	if (err == 0)
		ft_printf("Number greater than INT_MAX.\n");
	else if (err == 1)
		ft_printf("Number smaller than INT_MIN.\n");
	exit(EXIT_FAILURE);
}

int	ft_atoi_mt(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (num > INT_MAX && sign == 1)
			ft_error(0);
		if (((num * sign) < INT_MIN) && sign == -1)
			ft_error(1);
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (sign * num);
}
