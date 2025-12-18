/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:20:56 by julauren          #+#    #+#             */
/*   Updated: 2025/12/16 13:28:50 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_error(int err)
{
	if (err == 0)
		ft_printf("Number greater than INT_MAX.\n");
	else if (err == 1)
		ft_printf("Number smaller than INT_MIN.\n");
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
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
