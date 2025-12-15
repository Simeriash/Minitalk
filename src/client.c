/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:33:11 by julauren          #+#    #+#             */
/*   Updated: 2025/12/15 18:04:31 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

static void	ft_error(int err)
{
	if (err == 0)
	{
		ft_printf("Incorrect number of argument(s).\n");
		exit(0);
	}
	if (err == 1)
	{
		ft_printf("Only numbers are allowed for PID.\n");
		exit(0);
	}
	if (err == 2)
	{
		ft_printf("Only printable are charaters allowed.\n");
		exit(0);
	}
}

static void	ft_ctrl_arg(int ac, char **av)
{
	int	i;
	
	if (ac != 3)
		ft_error(0);
	i = 0;
	while (av[1][i] != '\0')
	{
		if (!(ft_isdigit(av[1][i])))
			ft_error(1);
		i++;
	}
	i = 0;
	while (av[2][i] != '\0')
	{
		if (!(ft_isprint(av[2][i])))
			ft_error(2);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	ft_ctrl_arg(ac, av);
	ft_printf("OK\n");
	return (0);
}
