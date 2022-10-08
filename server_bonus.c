/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:35:36 by knikogho          #+#    #+#             */
/*   Updated: 2022/10/08 11:55:04 by knikogho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *p)
{
	static int	i;
	static char	byte;

	(void)p;
	if (sig == SIGUSR2)
	{
		(byte |= (128 >> i));
		i++;
	}
	else
		i++;
	if (i == 8)
	{
		if (!byte)
			kill(info->si_pid, SIGUSR1);
		write(1, &byte, 1);
		i = 0;
		byte = 0;
	}
}

void	print_pid(int pid)
{
	char	c;

	if (pid > 9)
		print_pid (pid / 10);
	c = pid % 10 + '0';
	write (1, &c, 1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	print_pid (pid);
	write (1, "\n", 1);
	while (1)
	{
		pause();
	}	
	exit(1);
}
