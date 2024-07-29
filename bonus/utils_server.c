/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:17:33 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 17:17:35 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_signal(int signal, siginfo_t *info, void *context)
{
	static char		c;
	static int		i;

	(void)context;
	if (signal == SIGUSR2)
		c = (c * 2);
	else if (signal == SIGUSR1)
		c = ((c * 2) + 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			printf("MESSAGE FROM: %d\n", info->si_pid);
		}
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
