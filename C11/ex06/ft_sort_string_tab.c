#include <stdio.h>

int		ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*(str1) != *(str2))
			return ((int)(*str1) - (int)(*str2));
		str1++;
		str2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	k;
	char *tmp;

	k = 0;
	while (tab[k + 1])
	{
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		k++;
	}
}

#include <stdio.h>

int ft_strcmp(char *str1, char *str2);
void ft_sort_string_tab(char **tab);

int main() {
    char *strings[] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "fig",
    NULL  // Terminating NULL pointer
};

    // Sort the array of strings
    ft_sort_string_tab(strings);

    // Print the sorted array
    printf("Sorted strings:\n");
    for (int i = 0; strings[i] != NULL; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
