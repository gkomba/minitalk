/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:38:45 by gildo             #+#    #+#             */
/*   Updated: 2024/07/27 13:44:30 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//#include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_get_signal(int signal, siginfo_t *info, void *context);
void	ft_send_bit(pid_t pid, unsigned char chr);
void	ft_send_signal(pid_t pid, char *str);
void	ft_recived(int signal);

#endif