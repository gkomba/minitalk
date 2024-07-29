/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:18:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 17:18:37 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_get_signal(int signal, siginfo_t *info, void *context);
void	ft_send_bit(pid_t pid, unsigned char chr);
void	ft_send_signal(pid_t pid, char *str);
void	ft_recived(int signal);

#endif
