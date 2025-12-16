/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:11 by julauren          #+#    #+#             */
/*   Updated: 2025/12/16 10:51:57 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static void	ft_error(int ac, char **av)
{
	int	i;

	if (ac != 3)
	{
		ft_printf("Incorrect number of argument(s).\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (av[1][i] != '\0')
	{
		while (ft_isspace(av[1][i]))
			i++;
		if (!(ft_isdigit(av[1][i])))
		{
			ft_printf("Only positive integer not equal to zero are allowed for PID.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	ft_error(ac, av);
	pid = ft_atoi(av[1]);
	ft_printf("PID : %d\n", pid);
	return (0);
}
