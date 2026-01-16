/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:15 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/16 14:50:58 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_hexa(unsigned long long n, const char c)
{
	char	*list;
	int		count;

	count = 0;
	if (c == 'X')
		list = "0123456789ABCDEF";
	else if (c == 'x')
		list = "0123456789abcdef";
	if (n >= 16)
	{
		count += print_hexa((n / 16), c);
	}
	count += ft_putchar_fd(list[n % 16], 1);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	unsigned long long int	num;
	unsigned long long int	number;
	int						count;

	count = 0;
	num = n;
	if (num >= 10)
	{
		count += print_unsigned((num / 10));
	}
	number = ((num % 10) + '0');
	count += write(2, &number, 1);
	return (count);
}

int	print_ptr(void *ptr)
{
	int					count;
	unsigned long long	temp;

	count = 0;
	temp = (unsigned long long)ptr;
	if (!ptr)
		return ((write(2, "(nil)", 5)));
	count += write(2, &"0x", 2);
	count += print_hexa(temp, 'x');
	return (count);
}

static int	typecheck(const char *str, va_list arguments)
{
	unsigned int	count;

	count = 0;
	if (*str == 'c')
		return (count += ft_putchar_fd(va_arg(arguments, int), 2));
	else if (*str == 's')
		return (count += ft_putstr_fd(va_arg(arguments, char *), 2));
	else if (*str == 'p')
		return (count += print_ptr(va_arg(arguments, void *)));
	else if (*str == 'd')
		return (count += ft_putnbr_fd(va_arg(arguments, int), 2));
	else if (*str == 'i')
		return (count += ft_putnbr_fd(va_arg(arguments, int), 2));
	else if (*str == 'u')
		return (count += print_unsigned(va_arg(arguments, unsigned int)));
	else if (*str == 'x')
		return (count += print_hexa(va_arg(arguments, unsigned int), 'x'));
	else if (*str == 'X')
		return (count += print_hexa(va_arg(arguments, unsigned int), 'X'));
	else if (*str == 'f')
		return (count += print_float(va_arg(arguments, double), 2));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	va_list	args;

	if (!str)
		return (0);
	index = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str && ft_strchr("cspdiuxXf", *str))
			{
				index += typecheck(str, args);
			}
			else if (*str == '%')
				index += ft_putchar_fd('%', 2);
		}
		else
			index += write(2, str, 1);
		str++;
	}
	va_end(args);
	return (index);
}
