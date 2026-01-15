#include "../push_swap.h"

int	ft_putchar_fd(char c, int fd)
{
	int	count;

	count = 0;
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long long int	num;
	long long int	number;
	int				count;

	count = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		write(fd, &"-", 1);
		count++;
	}
	if (num >= 10)
	{
		count += ft_putnbr_fd((num / 10), fd);
	}
	number = ((num % 10) + '0');
	count += write(fd, &number, 1);
	return (count);
}

int	ft_putstr_fd(const char *s, int fd)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *)s;
	if (!str)
		return ((write(fd, "(null)", 6)));
	while (str[index] != '\0')
	{
		write(fd, &str[index], 1);
		index++;
	}
	return (index);
}

int	print_float(float number, int fd)
{
	int count;

	count = 0;

	count += ft_putnbr_fd(number, fd);
	number = number - (int)number;
	count += write(2, ".", 1);
	number = number * 100;
	count += ft_putnbr_fd(number, fd);
	return (count);
}