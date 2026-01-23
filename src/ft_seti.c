/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:42:36 by julauren          #+#    #+#             */
/*   Updated: 2026/01/23 07:51:36 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

char	*g_bin;

static void	ft_exit(int kill_client, pid_t pid)
{
	if (g_bin)
		free(g_bin);
	if (kill_client)
		kill(pid, 12);
	exit(EXIT_FAILURE);
}

static void	ft_malloc(pid_t pid)
{
	char	*tmp;
	int		i;

	if (!g_bin)
	{
		g_bin = malloc(sizeof(*g_bin) * 65);
		if (!g_bin)
			ft_exit(1, pid);
		g_bin[64] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(*tmp) * (65 + ft_strlen(g_bin)));
		if (!tmp)
			ft_exit(1, pid);
		i = 0;
		while (g_bin[i])
		{
			tmp[i] = g_bin[i];
			i++;
		}
		tmp[64 + ft_strlen(g_bin)] = '\0';
		free(g_bin);
		g_bin = tmp;
	}
}

static void	ft_signal(t_var var, int *count)
{
	if (var.signal == 10)
	{
		g_bin[var.i] = '0';
		if (*count > 0 || (var.i) % 8 == 0)
			(*count)++;
	}
	else if (var.signal == 12)
	{
		g_bin[var.i] = '1';
		*count = 0;
	}
	else if (var.signal == 2 || var.signal == 3)
		ft_exit(0, var.pid);
	kill(var.pid, 10);
}

static void	ft_sigaction(int signal, siginfo_t *info, void *none)
{
	static int	i;
	static int	count;
	t_var		var;

	none = NULL;
	if (!g_bin || (i > 0 && i % 64 == 0 && g_bin[i] == '\0'))
		ft_malloc(info->si_pid);
	var.i = i;
	var.signal = signal;
	var.pid = info->si_pid;
	ft_signal(var, &count);
	i++;
	if (count == 8)
	{
		g_bin[i] = '\0';
		ft_decode(g_bin);
		i = 0;
		count = 0;
		free(g_bin);
		g_bin = NULL;
	}
}

void	ft_seti(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_sigaction;
	sigaction(2, &act, NULL);
	sigaction(3, &act, NULL);
	sigaction(10, &act, NULL);
	sigaction(12, &act, NULL);
}
