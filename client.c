/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:00:20 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/27 14:43:42 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("%d\n", getpid());
		signal(SIGUSR1, ft_recived);
		ft_send_signal(pid, argv[2]);
	}
	else
	{
		ft_printf("\t<invalid arguments>\n");
		ft_printf("\t  <PID> <STRING>\n");
	}
}
