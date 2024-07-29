/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:23:41 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 16:28:26 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_config_flag;

void	ft_recived(int signal)
{
	g_config_flag = 1;
	(void)signal;
}

void	ft_send_bit_bonus(pid_t pid, unsigned char chr)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((chr >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else if (((chr >> i) & 1) == 0)
			kill(pid, SIGUSR2);
		while (!g_config_flag)
			;
		g_config_flag = 0;
	}
}

void	ft_send_signal_bonus(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bit_bonus(pid, str[i]);
		i++;
	}
	ft_send_bit_bonus(pid, '\0');
}
