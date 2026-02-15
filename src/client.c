/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:11 by julauren          #+#    #+#             */
/*   Updated: 2026/01/22 17:13:55 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static void	ft_error_args(int ac, char **av)
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

static void	ft_error(void)
{
	ft_printf("Number greater than INT_MAX.\n");
	exit(EXIT_FAILURE);
}

static int	ft_atoi_mt(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		if (num > INT_MAX)
			ft_error();
		i++;
	}
	return (num);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*bin;

	ft_error_args(ac, av);
	pid = ft_atoi_mt(av[1]);
	if (pid == 0)
	{
		ft_printf("Only one positive integer is allowed for PID.\n");
		exit(EXIT_FAILURE);
	}
	bin = ft_binary(av[2]);
	ft_message_in_the_bottle(bin, pid);
	free(bin);
	return (0);
}
