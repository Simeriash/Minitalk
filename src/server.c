/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:57 by julauren          #+#    #+#             */
/*   Updated: 2026/01/09 15:13:51 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

static void	ft_handler(int signal)
{
	if (signal == 10)
		ft_printf("Yoo\n");
	if (signal == 12)
		ft_printf("Yee\n");
}

static void	ft_set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &ft_handler;
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
	while (i < 3)
	{
		ft_set_signal_action();
		pause();
		i++;
	}
	return (0);
}
