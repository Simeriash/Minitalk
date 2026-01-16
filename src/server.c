/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:57 by julauren          #+#    #+#             */
/*   Updated: 2026/01/16 12:57:03 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

static void	ft_exit(char *bin)
{
	if (bin)
		free(bin);
	exit(EXIT_FAILURE);
}

static void	ft_malloc(char *bin)
{
	char	*tmp;

	if (!bin)
	{
		bin = malloc(sizeof(*bin) * 64);
		if (!bin)
			exit(EXIT_FAILURE);
		return ;
	}
	else
	{
		tmp = malloc(sizeof(*tmp) * (64 + ft_strlen(bin)));
		if (!tmp)
			ft_exit(bin);
	}
}

static void	ft_handler(int signal)
{
	// static int	count;
	static int	i;
	static char	*bin;

	if (!bin)
	{
		ft_malloc(bin);
		i = 0;
	}
	if (signal == 10)
		bin[i] = '0';
	else if (signal == 12)
		bin[i] = '1';
	else if (signal == 2 || signal == 3)
		ft_exit(bin);
	i++;
}

static void	ft_set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &ft_handler;
	sigaction(2, &act, NULL);
	sigaction(3, &act, NULL);
	sigaction(10, &act, NULL);
	sigaction(12, &act, NULL);
}

int	main(void)
{
	pid_t	pid;
	int		i;

	i = 0;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		ft_set_signal_action();
		ft_printf("%d\n", i);
		pause();
		i++;
	}
	ft_printf("%d\n", i);
	return (0);
}
