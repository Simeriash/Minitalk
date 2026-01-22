/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:37:01 by julauren          #+#    #+#             */
/*   Updated: 2026/01/22 11:57:04 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../src/libft/libft.h"

typedef struct s_var	t_var;
struct	s_var
{
	int		signal;
	int		i;
	pid_t	pid;
};

void	ft_seti(void);
void	ft_decode(char *bin);

#endif
