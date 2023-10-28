#include "header.h"

int ft_strcmp(char *str1, char *str2){

    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int	ft_find_oprator(char *argument)
{
	int	i;

	i = 0;
	char *operators[] = {"+", "-", "*", "/", "%"};
	while (operators[i])
	{
		if (ft_strcmp(operators[i], argument) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	main (int argc, char *argv[])
{
	int	operator;
	int	result;

	if (argc != 4)
		return (0);
	int (*operation[])(int, int) = {ft_add, ft_subtract, ft_multiply, ft_divide, ft_modulo};
	if ((operator = ft_find_oprator(argv[2])) < 0)
		write(1, "0", 1);
	else
	{
		if (operator == 3 && ft_atoi(argv[3]) < 0)
		{
			write(1, "Stop : division by zero\n", 24);
		}
		else if (operator == 4 && ft_atoi(argv[3]) < 0)
		{
			write(1, "Stop : modulo by zero\n", 22);
		}
		else
		{
		result = (*operation[operator])(ft_atoi(argv[1]), ft_atoi(argv[3]));
		ft_putnbr(result);
		}
	}
	return (0);
}
