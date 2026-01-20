/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:57 by julauren          #+#    #+#             */
/*   Updated: 2026/01/20 12:59:41 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int	main(void)
{
	pid_t	pid;
	int		i;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	i = 0;
	while (1)
	{
		ft_seti();
		pause();
		ft_printf("%d", i);
		i++;
	}
	return (0);
}
