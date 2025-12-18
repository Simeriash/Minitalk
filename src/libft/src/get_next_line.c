/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:05:40 by julauren          #+#    #+#             */
/*   Updated: 2025/12/17 17:46:52 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_be_free(char **buffer, char *new_buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(new_buffer);
	new_buffer = NULL;
}

static ssize_t	ft_full_buffer(int fd, char **buffer)
{
	ssize_t	nb_read;
	char	*new_buffer;
	char	*tmp;

	new_buffer = malloc(sizeof (*new_buffer) * (BUFFER_SIZE + 1));
	if (!new_buffer)
		return (-1);
	nb_read = read(fd, new_buffer, BUFFER_SIZE);
	if (nb_read == -1 || nb_read == 0)
	{
		ft_be_free(&*buffer, new_buffer);
		return (nb_read);
	}
	new_buffer[nb_read] = '\0';
	tmp = ft_strjoin_gnl(*buffer, new_buffer);
	if (*buffer)
		free(*buffer);
	free(new_buffer);
	if (!tmp)
		return (-1);
	*buffer = tmp;
	return (nb_read);
}

static char	*ft_print_line(char **buffer, int *i)
{
	char	*line;
	char	*tmp;

	*i = *i + 1;
	line = ft_substr(*buffer, 0, *i);
	if (!line)
	{
		free(*buffer);
		return (NULL);
	}
	tmp = ft_substr(*buffer, *i, ft_strlen(*buffer) - *i);
	free(*buffer);
	if (!tmp)
		return (NULL);
	*buffer = tmp;
	return (line);
}

static char	*ft_no_n(int fd, char **buffer)
{
	ssize_t	nb_read;
	char	*line;

	line = NULL;
	nb_read = ft_full_buffer(fd, &*buffer);
	if (nb_read == -1)
		return (NULL);
	if (nb_read == 0 && *buffer)
	{
		line = ft_substr(*buffer, 0, ft_strlen(*buffer) + 1);
		if (*buffer)
			free(*buffer);
		return (line);
	}
	if (nb_read == 0 && !*buffer)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
		if ((ft_full_buffer(fd, &buffer)) <= 0)
			return (NULL);
	i = -1;
	while (i == -1)
	{
		if (!buffer)
			return (NULL);
		i = ft_strchr_gnl(buffer);
		if (i >= 0)
			line = ft_print_line(&buffer, &i);
		else
			line = ft_no_n(fd, &buffer);
	}
	return (line);
}
