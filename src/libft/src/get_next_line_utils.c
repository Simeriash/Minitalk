/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:07:21 by julauren          #+#    #+#             */
/*   Updated: 2025/12/12 15:38:17 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strchr(const char *s)
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	slen;
	char	*dest;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		size = 0;
	else if (len > slen - start)
		size = slen - start;
	else
		size = len;
	dest = malloc(sizeof (*dest) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
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
