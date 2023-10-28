#include <unistd.h>
#include "ft_strs_to_tab.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(int num)
{
	char c;

	c = 0;
	if (num == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *strings[] = {
        "Hello",
        "World",
        "Test",
        "Example"
    };
    int numStrings = sizeof(strings) / sizeof(strings[0]);

    t_stock_str *stockArray = ft_strs_to_tab(numStrings, strings);
    if (stockArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

	ft_show_tab(stockArray);

    // Free allocated memory
    for (int i = 0; i < numStrings; i++) {
        free(stockArray[i].copy);
    }
    free(stockArray);

    return 0;
}
