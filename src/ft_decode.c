/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:55:08 by julauren          #+#    #+#             */
/*   Updated: 2026/01/22 12:58:30 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <stdlib.h>

static int	ft_power(int nb, int power)
{
	int	i;
	int	result;

	if (power == 0)
		return (1);
	i = 1;
	result = 1;
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

static void	ft_itoa_10(char *bin, char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		str[i] = 0;
		while (j < 8)
		{
			str[i] += (bin[8 * i + j] - 48) * ft_power(2, 7 - j);
			j++;
		}
		i++;
	}
}

void	ft_decode(char *bin)
{
	char	*str;
	int		len;

	len = (ft_strlen(bin)) / 8 - 1;
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
	{
		free(bin);
		exit(EXIT_FAILURE);
	}
	str[len] = '\0';
	ft_itoa_10(bin, str, len);
	ft_printf("\n%s\n", str);
	free(str);
}
