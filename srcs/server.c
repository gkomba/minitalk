/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:16:53 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 12:44:55 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	printf("\t\t<<WELCOME>>\n");
	ft_printf("SERVER PID: %d\n", getpid());
	signal(SIGUSR1, ft_get_signal);
	signal(SIGUSR2, ft_get_signal);
	while (1)
		;
}
