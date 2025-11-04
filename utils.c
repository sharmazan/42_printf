/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/04 11:44:29 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	printed;

	printed = 0;
	while (*s)
		printed += write(fd, s++, 1);
	return (printed);
}

void	ft_putnbr_fd(int n, int fd, int *counter)
{
	char	c;
	int		base;
	int		print;

	print = 0;
	base = -1000000000;
	if (n < 0)
		*counter += write(fd, "-", 1);
	else
		n = -n;
	while (base)
	{
		if (n <= base)
		{
			print = 1;
			c = n / base + '0';
			*counter += write(fd, &c, 1);
			n %= base;
		}
		else if (print)
			*counter += write(fd, "0", 1);
		base /= 10;
	}
	if (!print)
		*counter += write(fd, "0", 1);
}

int	ft_putudec_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	base;
	int				print;
	int				printed;

	if (n == 0)
		return (write(fd, "0", 1));
	printed = 0;
	print = 0;
	base = 1000000000;
	while (base)
	{
		if (n >= base)
		{
			print = 1;
			c = n / base + '0';
			printed += write(fd, &c, 1);
			n %= base;
		}
		else if (print)
			printed += write(fd, "0", 1);
		base /= 10;
	}
	return (printed);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putnum_base(long n, char *base, int fd)
{
	int		digit;
	int		ibase;
	int		i;
	char	buf[255];
	int		printed;

	printed = 0;
	i = 0;
	ibase = ft_strlen(base);
	while (n > 0)
	{
		digit = n % ibase;
		buf[i++] = *(base + digit);
		n /= ibase;
	}
	while (i >= 0)
		printed += write(fd, &buf[--i], 1);
	return (printed);
}
