int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (tab == 0)
	 return 0;
	while (i < length)
	{
		if ((*f)(*tab) != 0)
			counter++;
		i++;
	}
	return counter;
}
