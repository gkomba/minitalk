/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:17:33 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 16:28:28 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_message(pid_t pid_client)
{
	write(1, "\n", 1);
	ft_printf("MESSAGE FROM: %d\n", pid_client);
	ft_printf("\nNEW MESSAGE >>\n");
}

void	ft_get_signal_bonus(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		i;
	static int		pid_client;

	(void)context;
	if (pid_client != info->si_pid)
	{
		i = 0;
		c = 0;
	}
	pid_client = info->si_pid;
	if (signal == SIGUSR2)
		c = (c * 2);
	else if (signal == SIGUSR1)
		c = ((c * 2) + 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			ft_message(info->si_pid);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
