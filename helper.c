/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/04 17:22:01 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_fd(unsigned int n, int fd)
{
	return (ft_putnum_base(n, "0123456789abcdef", fd));
}

int	ft_putbighex_fd(unsigned int n, int fd)
{
	return (ft_putnum_base(n, "0123456789ABCDEF", fd));
}

int	ft_putptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	write(fd, "0x", 2);
	return (ft_puthex_fd((size_t)ptr, fd) + 2);
}
