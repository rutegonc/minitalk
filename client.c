/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:10:20 by rugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 17:27:36 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
SIGUSR1 == 0
SIGUSR2 == 1
*/
void	ft_atob(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (str[i])
		{
			ft_atob(pid, str[i]);
			i++;
		}
	}
}
