/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:51:43 by julauren          #+#    #+#             */
/*   Updated: 2025/12/12 15:37:42 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_type(va_list param, const char *str, int *i)
{
	int	len;

	len = -1;
	*i = *i + 1;
	if (str[*i] == 'c')
		len = ft_putchar_fd(va_arg(param, int), 1);
	if (str[*i] == 's')
		len = ft_putstr_fd(va_arg(param, char *), 1);
	if (str[*i] == 'p')
		len = ft_putnbr(va_arg(param, size_t), 16, 1, 1);
	if (str[*i] == 'd' || str[*i] == 'i')
		len = ft_putnbr(va_arg(param, int), 10, 0, 0);
	if (str[*i] == 'u')
		len = ft_putnbr(va_arg(param, unsigned int), 10, 0, 0);
	if (str[*i] == 'x')
		len = ft_putnbr(va_arg(param, unsigned int), 16, 0, 1);
	if (str[*i] == 'X')
		len = ft_putnbr(va_arg(param, unsigned int), 16, 0, 0);
	if (str[*i] == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		i;
	int		len;
	int		tmp;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(param, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			tmp = ft_type(param, str, &i);
		else
			tmp = ft_putchar_fd(str[i], 1);
		if (tmp == -1)
			return (-1);
		len += tmp;
		i++;
	}
	va_end(param);
	return (len);
}
