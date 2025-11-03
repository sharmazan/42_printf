/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/03 13:27:02 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_puthex_fd(unsigned int n, int fd)
{
	ft_putnum_base(n, "0123456789abcdef", fd);
}

void	ft_putbighex_fd(unsigned int n, int fd)
{
	ft_putnum_base(n, "0123456789ABCDEF", fd);
}

void	ft_putptr_fd(unsigned int n, int fd)
{
	write(fd, "0x", 2);
	ft_putnum_base(n, "0123456789abcdef", fd);
}
