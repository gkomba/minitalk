/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:00:20 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 12:30:49 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send_signal(pid, argv[2]);
	}
	else
	{
		ft_printf("\t<invalid arguments>\n");
		ft_printf("\t  <PID> <STRING>\n");
	}
}
