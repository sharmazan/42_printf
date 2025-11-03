/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:26:20 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		base;
	int		print;

	print = 0;
	base = -1000000000;
	if (n < 0)
		write(fd, "-", 1);
	else
		n = -n;
	while (base)
	{
		if (n <= base)
		{
			print = 1;
			c = n / base + '0';
			write(fd, &c, 1);
			n %= base;
		}
		else if (print)
			write(fd, "0", 1);
		base /= 10;
	}
	if (!print)
		write(fd, "0", 1);
}

void	ft_putudec_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	base;
	int				print;

	print = 0;
	base = 1000000000;
	while (base)
	{
		if (n >= base)
		{
			print = 1;
			c = n / base + '0';
			write(fd, &c, 1);
			n %= base;
		}
		else if (print)
			write(fd, "0", 1);
		base /= 10;
	}
	if (!print)
		write(fd, "0", 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putnum_base(long n, char *base, int fd)
{
	int		digit;
	int		ibase;
	int		i;
	char	buf[255];

	i = 0;
	ibase = ft_strlen(base);
	while (n > 0)
	{
		digit = n % ibase;
		buf[i++] = *(base + digit);
		n /= ibase;
	}
	while (i >= 0)
		write(fd, &buf[--i], 1);
}
