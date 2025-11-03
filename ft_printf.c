/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/03 15:01:45 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

static void	ft_print_formated(va_list args, char c)
{
	if (c == 'c')
		write(1, va_arg(args, char *), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putudec_fd(va_arg(args, unsigned int), 1);
	else if (c == 'p')
		ft_putptr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_puthex_fd(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		ft_putbighex_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_print_formated(args, *format);
			format++;
		}
		else
			write(1, format++, 1);
	}
	va_end(args);
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "Hello";
	ft_printf("%s %c %s %d %i %u %u %x %X %x %% %p world!!!!\n", str, "A",
		"BBB", -12, 12, -1, 1, 15, 255, -15, str);
	// printf("%c\n", 'B');
	// printf("%s\n", "BBB");
	ft_printf("String: %s. Pointer address: %p\n", str, str);
	printf("String: %s. Pointer address: %p\n", str, str);
	// printf("%p\n", 10);
	// printf("%x\n", 10);
	// printf("%u\n", -1);
	// printf("%u\n", 1);
	// printf("%d\n", -15);
	// printf("%i\n", -15);
	// printf("%x\n", -15);
	// printf("%X\n", -15);
	// printf("%d\n", 15);
	// printf("%i\n", 15);
	// printf("%x\n", 15);
	// printf("%X\n", 15);
	return (0);
}
*/
