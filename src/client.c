/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:11 by julauren          #+#    #+#             */
/*   Updated: 2026/01/11 16:35:04 by julauren         ###   ########.fr       */
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
	if (av[1][i] == '+')
		i++;
	if (ft_isdigit(av[1][i]))
		num++;
	while (ft_isdigit(av[1][i]))
		i++;
	while (ft_isspace(av[1][i]))
		i++;
	if ((av[1][i] == '\0' && num == 0) || av[1][i] != '\0')
	{
		ft_printf("Only one positive integer is allowed for PID.\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	ft_error(ac, av);
	pid = ft_atoi_mt(av[1]);
	if (pid == 0)
	{
		ft_printf("Only one positive integer is allowed for PID.\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("PID : %d\nSTR : %s\n", pid, av[2]);
	str = ft_binary(av[2]);
	ft_printf("%s\n", str);
	// kill(pid, 12);
	// kill(pid, 10);
	// kill(pid, 12);
	free(str);
	return (0);
}
