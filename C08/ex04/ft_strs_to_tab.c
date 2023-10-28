#include "ft_strs_to_tab.h"
#include <stdlib.h>

char *ft_strcpy_mal (char *str, int l)
{
	char *new_str;
	int i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * (l + 1));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str *struc_arr;
	struc_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!struc_arr)
		return (0);
	i = 0;
	while (i < ac)
	{
		struc_arr[i].size = ft_strlen (av[i]);
		struc_arr[i].str = av[i];
		struc_arr[i].copy = ft_strcpy_mal(av[i], ft_strlen (av[i]));
		i++;
	}
	struc_arr[i].str = 0;
	return (struc_arr);
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

    for (int i = 0; i < numStrings; i++) {
        printf("String: %s\n", stockArray[i].str);
        printf("Size: %d\n", stockArray[i].size);
        printf("Copy: %s\n\n", stockArray[i].copy);
    }

    // Free allocated memory
    for (int i = 0; i < numStrings; i++) {
        free(stockArray[i].copy);
    }
    free(stockArray);

    return 0;
}
