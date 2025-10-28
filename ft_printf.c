/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2025/10/28 20:18:48 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static char	*get_value(char c)
{
	// cspdiuxX%
	if (c == 'c')
		return ("CHAR");
	if (c == 's')
		return ("STRING");
	if (c == 'p')
		return ("PNTR");
	if (c == 'd')
		return ("DECI");
	if (c == 'i')
		return ("INTEGER");
	if (c == 'u')
		return ("UUUU");
	if (c == 'x')
		return ("xxxx");
	if (c == 'X')
		return ("XXXX");
	if (c == '%')
		return ("%%%%");
	return ("NULL");
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			write(1, get_value(*(++format)), 4);
		else
			write(1, format++, 1);
	}
	// write(1, va_arg(args, char *), 1);
	// write(1, va_arg(args, char *), 1);
	// write(1, va_arg(args, char *), 1);
	// printf("%s\n", va_arg(args, char *));
	// printf("%s\n", va_arg(args, char *));
	// printf("%s\n", va_arg(args, char *));
	// printf("%s\n", va_arg(args, char *));
	// printf("%s %d %s\n", va_arg(args, char *), 1);
	write(1, "\n", 1);
	va_end(args);
	return (1);
}
