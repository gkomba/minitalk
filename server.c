/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:34:54 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 12:37:06 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check_signal(int signal, siginfo_t *info, void *context)
{
	static char c;
	static int i;

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
			printf("%d\n", info->si_pid);
		}
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	struct sigaction data;
	data.sa_sigaction = &ft_check_signal;
	data.sa_flags = SA_SIGINFO;

	printf("%d\n", getpid());
	sigaction(SIGUSR2, &data, NULL);
	sigaction(SIGUSR1, &data, NULL);
	while (1)
		;
}

/*//011001000

c = (c * 2)
c = (c * 2) + 1

c = 0;
c = 0 * 2 = 0;
c = c  */