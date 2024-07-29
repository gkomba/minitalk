/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:16:53 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 17:17:00 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	data;

	data.sa_sigaction = &ft_get_signal;
	data.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR2, &data, NULL);
	sigaction(SIGUSR1, &data, NULL);
	printf(">>\n");
	while (1)
		;
}
