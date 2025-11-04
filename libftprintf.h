/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/04 12:36:09 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd, int *counter);
int		ft_putudec_fd(unsigned int n, int fd);
int		ft_puthex_fd(unsigned int n, int fd);
int		ft_putbighex_fd(unsigned int n, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putnum_base(long n, char *base, int fd);

#endif
