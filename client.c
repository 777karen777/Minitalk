/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:52:03 by knikogho          #+#    #+#             */
/*   Updated: 2022/10/08 11:51:41 by knikogho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shift(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		bit++;
		usleep(500);
	}
}

void	send_signal(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		shift(message[i], pid);
		i++;
	}
	shift('\0', pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_signal(av[2], pid);
		usleep(100);
		exit(0);
	}
	ft_putstr(ERR_ARG);
}
