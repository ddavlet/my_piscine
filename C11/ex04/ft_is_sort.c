int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	tmp;
	int	k;

	i = 1;
	k = 0;
	if (tab == 0 || length <= 1)
	 return (1);
	while (i < length)
	{
		tmp = (*f)(tab[i - 1], tab[i]);
		if (tmp == 0)
			continue;
		if (k == 0)
			k = tmp;
		else if ((k > 0 && tmp < 0) || (k < 0 && tmp > 0))
			return (0);
	}
	return (1);
}
