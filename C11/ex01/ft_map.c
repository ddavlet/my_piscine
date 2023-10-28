int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int *new_arr;

	i = 0;
	if (tab == 0 || length < 1 || f == 0)
	 return (0);
	new_arr = (int *)malloc(length * sizeof(int));
	if (!new_arr)
		return (0);
	while (i < length)
	{
		new_arr[i] = (*f)(tab[i]);
		i++;
	}
	return (new_arr);
}
