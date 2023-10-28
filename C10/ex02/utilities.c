#include "utilities.h"

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
void	ft_print_error (char *prog_name, char *file_name)
{
	ft_putstr(basename(prog_name));
	ft_putstr(": ");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}
void	ft_putstr (char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		write (1, &text[i], 1);
		i++;
	}
}
