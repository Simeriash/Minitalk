/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_in_the_bottle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:52:28 by julauren          #+#    #+#             */
/*   Updated: 2026/01/16 16:00:08 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	ctrl;

static void	ft_handler(int signal)
{
	if (signal == 12 || signal == 2 || signal == 3)
		ctrl = 1;
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

void	ft_message_in_the_bottle(char *bin, pid_t pid)
{
	int		i;

	i = 0;
	while (bin[i] != '\0')
	{
		if (ctrl == 1)
			break ;
		if (bin[i] == '0')
			kill(pid, 10);
		else
			kill(pid, 12);
		ft_set_signal_action();
		pause();
		i++;
	}
}
