/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:23:41 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 12:42:00 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
		usleep(100);
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
