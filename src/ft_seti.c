/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:42:36 by julauren          #+#    #+#             */
/*   Updated: 2026/01/17 17:20:54 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

static void	ft_exit(char **bin, pid_t pid)
{
	if (*bin)
		free(*bin);
	kill(pid, 12);
	exit(EXIT_FAILURE);
}

static void	ft_malloc(char **bin, pid_t pid)
{
	char	*tmp;
	int		i;

	if (!(*bin))
	{
		*bin = malloc(sizeof(**bin) * 65);
		if (!(*bin))
			ft_exit(&*bin, pid);
		*bin[64] = '\0';
	}
	else
	{
		tmp = malloc(sizeof(*tmp) * (65 + ft_strlen(*bin)));
		if (!tmp)
			ft_exit(&*bin, pid);
		i = 0;
		while (*bin[i])
		{
			tmp[i] = *bin[i];
			i++;
		}
		tmp[64 + ft_strlen(*bin)] = '\0';
		free(*bin);
		*bin = tmp;
	}
}

static void	ft_signal(char **bin, t_var var, int *count)
{
	if (var.signal == 10)
	{
		*bin[var.i] = '0';
		if ((var.i) % 8 == 0 || count > 0)
			(*count)++;
	}
	else if (var.signal == 12)
	{
		*bin[var.i] = '1';
		count = 0;
	}
	else if (var.signal == 2 || var.signal == 3)
		ft_exit(&*bin, var.pid);
	kill(var.pid, 10);
}

static void	ft_sigaction(int signal, siginfo_t *info, void *none)
{
	static int	i;
	static char	*bin;
	static int	count;
	t_var		var;

	none = NULL;
	if (!bin || (i > 0 && i % 64 == 0 && bin[i] == '\0'))
		ft_malloc(&bin, info->si_pid);
	var.i = i;
	var.signal = signal;
	var.pid = info->si_pid;
	ft_signal(&bin, var, &count);
	i++;
	if (count == 8)
	{
		bin[i] = '\0';
		ft_decode(&bin);
		i = 0;
		count = 0;
		bin = NULL;
	}
}

void	ft_seti(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_sigaction = &ft_sigaction;
	act.sa_flags = SA_SIGINFO;
	sigaction(2, &act, NULL);
	sigaction(3, &act, NULL);
	sigaction(10, &act, NULL);
	sigaction(12, &act, NULL);
}
