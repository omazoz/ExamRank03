/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <tlufulua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:26:07 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/30 17:42:37 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_itoa_base(long int num, int base)
{
	unsigned int	n;
	unsigned int	x;
	size_t			size;
	char			*s;

	x = num;
	if (base == 10 && num < 0)
		x = num * -1;
	size = (num < 0 && base == 10) + (num == 0);
	n = x;
	while (n)
	{
		n = n / base;
		size++;
	}
	s = (char *)malloc(sizeof(char) * size);
	s[size--] = '\0';
	while (s && x > 0)
	{
		if ((x % base) > 9)
			s[size--] = ((x % base) + 39) + '0';
		else
			s[size--] = (x % base) + '0';
		x = x / base;
	}
	if (x == 0)
		s[size] = '0';
	if (num < 0 && base == 10)
		s[size] = '-';
	return (s);
}

int	hexadecimal(va_list arg)
{
	char *s;
	int	i;

	i = 0;
	s = ft_itoa_base(va_arg(arg, unsigned int), 16);
	if (s)
	{
		i = write(1, s, ft_strlen(s));
		free(s);
	}
	return (i);
}

int	decimal(va_list arg)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa_base(va_arg(arg, int), 10);
	if (s)
	{
		i = write(1, s, ft_strlen(s));
		free(s);
	}
	return (i);
}

int	string(va_list arg)
{
	char	*s;
	
	s = va_arg(arg, char *);
	if (!s)
		return(write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	convert(const char *format, va_list arg)
{
	size_t	i;

	i = 0;
	if (*format == 's')
		i = string(arg);
	if (*format == 'd')
		i = decimal(arg);
	if (*format == 'x')
		i = hexadecimal(arg);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	
	va_start(arg, format);
	i = 0;
	while (*format)
	{
		if (*format == '%' && format++)
			i += convert(format, arg);
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (i);
}
