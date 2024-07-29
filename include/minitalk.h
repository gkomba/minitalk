/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:18:00 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 12:32:49 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/*		bonus									by: gkomba		*/
void	ft_get_signal_bonus(int signal, siginfo_t *info, void *context);
void	ft_send_bit_bonus(pid_t pid, unsigned char chr);
void	ft_send_signal_bonus(pid_t pid, char *str);
void	ft_recived(int signal);

/*		mandatory								by: gkomba		*/
void	ft_get_signal(int signal);
void	ft_send_bit(pid_t pid, unsigned char chr);
void	ft_send_signal(pid_t pid, char *str);

#endif
