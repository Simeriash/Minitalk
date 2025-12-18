/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:07:21 by julauren          #+#    #+#             */
/*   Updated: 2025/12/17 17:43:43 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strchr_gnl(const char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len_1;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len_1 = ft_strlen(s1);
	else
		len_1 = 0;
	if (s2)
		len_2 = ft_strlen(s2);
	else
		len_2 = 0;
	dest = malloc(sizeof (*dest) * (len_1 + len_2 + 1));
	if (!dest)
		return (NULL);
	if (s1)
		ft_strlcpy(dest, s1, len_1 + 1);
	if (s2)
		ft_strlcpy(&dest[len_1], s2, len_2 + 1);
	return (dest);
}
