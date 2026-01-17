/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:57 by julauren          #+#    #+#             */
/*   Updated: 2026/01/17 15:00:59 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int	main(void)
{
	pid_t	pid;
	int		i;

	i = 0;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		ft_seti();
		pause();
	}
	return (0);
}
