/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:35:26 by julauren          #+#    #+#             */
/*   Updated: 2026/01/16 12:19:21 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "../src/libft/libft.h"

int		ft_atoi_mt(const char *str);
void	ft_message_in_the_bottle(char *str, pid_t pid);

#endif
