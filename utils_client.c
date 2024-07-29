/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:23:41 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 16:23:43 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_config_flag;

void	ft_recived(int signal)
{
	g_config_flag = 1;
	(void)signal;
}

void	ft_send_bit(pid_t pid, unsigned char chr)
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

void	ft_send_signal(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\0');
}
