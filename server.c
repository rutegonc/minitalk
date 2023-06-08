/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:10:32 by rugoncal          #+#    #+#             */
/*   Updated: 2023/04/17 22:34:25 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR2)
		c += 1 << i;
	if (i == 7)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		i++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
