/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:57 by julauren          #+#    #+#             */
/*   Updated: 2025/12/21 16:04:16 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

static void	ft_handler(int signal)
{
	ft_printf("Sig : %d\n", signal);
}

static void	ft_set_signal_action(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_handler = &ft_handler;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_set_signal_action();
	pause();
	return (0);
}
