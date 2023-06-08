/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:10:32 by rugoncal          #+#    #+#             */
/*   Updated: 2023/05/01 10:03:01 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *siginfo, void *context)
{
	static char	c = 0;
	static int	i = 0;
	int			client_pid;

	(void)context;
	client_pid = siginfo-> si_pid;
	if (signal == SIGUSR2)
		c += 1 << i;
	if (i == 7)
	{
		write(1, &c, 1);
		kill(client_pid, SIGUSR2);
		c = 0;
		i = 0;
	}
	else
		i++;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
