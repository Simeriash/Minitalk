/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:11 by julauren          #+#    #+#             */
/*   Updated: 2025/12/17 09:17:01 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static void	ft_error(int ac, char **av)
{
	int	i;
	int	num;

	if (ac != 3)
	{
		ft_printf("Incorrect number of argument(s).\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	num = 0;
	while (ft_isspace(av[1][i]))
		i++;
	if (ft_isdigit(av[1][i]))
		num++;
	while (ft_isdigit(av[1][i]))
		i++;
	while (ft_isspace(av[1][i]))
		i++;
	if ((av[1][i] == '\0' && num == 0) || av[1][i] != '\0')
	{
		ft_printf("Only one positive integer not equal to \
zero are allowed for PID.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	ft_error(ac, av);
	pid = ft_atoi(av[1]);
	str = av[2];
	ft_printf("PID : %d\nSTR : %s\n", pid, str);
	kill(pid, 10);
	return (0);
}
