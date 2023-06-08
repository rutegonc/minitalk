/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:11:58 by rugoncal          #+#    #+#             */
/*   Updated: 2023/04/06 17:25:48 by rugoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{	
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

int	ft_atoi(const char *str)
{
	char	*i;
	int		result;
	int		sign;

	i = (char *)str;
	result = 0;
	sign = 1;
	while ((*i == ' ') || (*i >= 9 && *i <= 13))
		i++;
	if (*i == '-' || *i == '+')
	{
		if (*i == '-')
			sign *= -1;
		i++;
	}
	while (*i && *i >= '0' && *i <= '9')
	{
		result = result * 10 + *i - '0';
		i++;
	}
	return (result * sign);
}
