/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gildo <gildo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:34:24 by gildo             #+#    #+#             */
/*   Updated: 2024/07/27 12:39:32 by gildo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_flag = 0;

void ft_send_bit(pid_t  pid, unsigned char chr)
{
	int i;
	int bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		if (((chr >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else if (((chr >> i) & 1) == 0)
			kill(pid, SIGUSR2);
		while (!g_flag)
			;
		g_flag = 0;
	}
}

void	ft_recived(int signal)
{
	g_flag = 1;
}

void send_signal(pid_t pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_send_bit(pid, str[i]);
		i++;
	}
	ft_send_bit(pid, '\0');

}
int main(int argc, char **argv)
{
	pid_t pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		printf("%d\n", getpid());
		signal(SIGUSR1, ft_recived);
		send_signal(pid, argv[2]);
	}
}