/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:17:33 by gkomba            #+#    #+#             */
/*   Updated: 2024/07/29 16:28:36 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_get_signal(int signal)
{
	static char		c;
	static int		i;

	if (signal == SIGUSR2)
		c = (c * 2);
	else if (signal == SIGUSR1)
		c = ((c * 2) + 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
		i = 0;
	}
}
