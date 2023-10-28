#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int ret;

	ret = 0;
	while (*str)
	{
		ret *= 10;
		ret += (*(str++) - '0');
	}
	return (ret);
}
void ft_putnbr(int n)
{
	if (n < 0) {
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10) {
		ft_putnbr(n / 10);
	}
	ft_putchar('0' + (n % 10));
}
