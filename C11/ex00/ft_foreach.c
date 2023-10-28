

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

#include <stdio.h>

void print_int(int value) {
	value += 2;
    printf("%d ", value);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array after applying ft_foreach: ");
    ft_foreach(arr, length, &print_int);
    printf("\n");

    return 0;
}
