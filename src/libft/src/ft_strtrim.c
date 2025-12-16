/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:16:25 by julauren          #+#    #+#             */
/*   Updated: 2025/12/12 15:32:46 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	len;
	char	*dest;

	if (!s1 || !set || set[0] == '\0')
	{
		if (!s1)
			dest = NULL;
		if (!set || set[0] == '\0')
			dest = ft_strdup(s1);
		return (dest);
	}
	len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	len = len - 1;
	while (ft_strrchr(set, s1[len]) && len > start)
		len--;
	dest = ft_substr(s1, start, len - start + 1);
	return (dest);
}
