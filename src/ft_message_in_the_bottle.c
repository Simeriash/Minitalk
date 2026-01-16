/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_in_the_bottle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:28 by julauren          #+#    #+#             */
/*   Updated: 2026/01/16 12:27:31 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static char	*ft_itoa_2(int c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(*str) * 9);
	if (!str)
		return (NULL);
	str[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		str[i] = (c % 2) + 48;
		c /= 2;
		i--;
	}
	while (i >= 0)
	{
		str[i] = '0';
		i--;
	}
	return (str);
}

static void	ft_b2b(char *bin, char *c)
{
	static int	i;
	int			j;

	j = 0;
	while (c[j] != '\0')
	{
		bin[i] = c[j];
		i++;
		j++;
	}
}

static char	*ft_binary(char *str)
{
	int		i;
	int		len;
	char	*bin;
	char	*tmp;

	len = ft_strlen(str) + 1;
	bin = malloc(sizeof(*bin) * (8 * len + 1));
	if (!bin)
		exit(EXIT_FAILURE);
	bin[8 * len] = '\0';
	i = 0;
	while (i < len)
	{
		tmp = ft_itoa_2(str[i]);
		if (!tmp)
		{
			free(bin);
			exit(EXIT_FAILURE);
		}
		ft_b2b(bin, tmp);
		free(tmp);
		i++;
	}
	return (bin);
}

static void	ft_set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	sigaction(10, &act, NULL);
}

void	ft_message_in_the_bottle(char *str, pid_t pid)
{
	int		i;
	char	*bin;

	bin = ft_binary(str);
	i = 0;
	while (bin[i] != '\0')
	{
		if (bin[i] == '0')
			kill(pid, 10);
		else
			kill(pid, 12);
		ft_set_signal_action();
		pause();
		i++;
	}
	free(bin);
}
