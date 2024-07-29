/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:16:53 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 15:39:02 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	struct sigaction	data;

	ft_memset(&data, 0, sizeof(struct sigaction));
	data.sa_sigaction = &ft_get_signal_bonus;
	data.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR2, &data, NULL);
	sigaction(SIGUSR1, &data, NULL);
	printf("\t\t<<WELCOME>>\n");
	ft_printf("\nNEW MESSAGE >>\n");
	while (1)
		;
	free(data);
	exit(0);
}
