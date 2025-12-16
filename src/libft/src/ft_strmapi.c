/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:50:00 by julauren          #+#    #+#             */
/*   Updated: 2025/12/12 15:32:46 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*t;

	if (!s || !f)
		return (NULL);
	t = (char *)s;
	str = malloc(sizeof (*str) * (ft_strlen(t) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (t[i] != '\0')
	{
		str[i] = (f)(i, t[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
