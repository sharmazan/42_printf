/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/11/04 11:45:54 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_print_formated(va_list args, char c)
{
	int	printed;

	printed = 0;
	if (c == 'c')
		return (write(1, va_arg(args, char *), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, &printed);
	else if (c == 'u')
		return (ft_putudec_fd(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_putbighex_fd(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed += ft_print_formated(args, *format);
			format++;
		}
		else
			printed += write(1, format++, 1);
	}
	va_end(args);
	return (1);
}

#include <stdio.h>

void	test_dec(void)
{
	int	i;
	int	j;
	int	n;

	n = -2147483648;
	i = printf("%d\n", 0);
	j = ft_printf("%d\n", 0);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%d\n", -15);
	j = ft_printf("%d\n", -15);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%d\n", 15);
	j = ft_printf("%d\n", 15);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%d\n", n);
	j = ft_printf("%d\n", n);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%d\n", 2147483647);
	j = ft_printf("%d\n", 2147483647);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
}

void	test_int(void)
{
	int	n;
	int	i;
	int	j;

	n = -2147483648;
	i = printf("%i\n", 0);
	j = ft_printf("%i\n", 0);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%i\n", -15);
	j = ft_printf("%i\n", -15);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%i\n", 15);
	j = ft_printf("%i\n", 15);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%i\n", n);
	j = ft_printf("%i\n", n);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
	i = printf("%i\n", 2147483647);
	j = ft_printf("%i\n", 2147483647);
	ft_printf("Original: [%i], ft_print: [%i]\n", i, j);
}

#include "helper.c"
#include "utils.c"

int	main(void)
{
	char	*str;

	// int		i;
	str = NULL;
	test_int();
	test_dec();
	// ft_printf("%s %c %s %d %i %u %u %x %X %x %% %p world!!!!\n", str, "A",
	// 	"BBB", -12, 12, -1, 1, 15, 255, -15, str);
	// printf("%c\n", 'B');
	// printf("%s\n", "BBB");
	// ft_printf("String: %s. Pointer address: %p\n", str, str);
	// i = printf("String: %s. Pointer address: %p\n", str, str);
	// printf("%d\n", i);
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
