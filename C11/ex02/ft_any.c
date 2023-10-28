int	ft_any(char **tab, int(*f)(char*))
{
	if (tab == 0)
	 return 0;
	while (tab)
	{
		if ((*f)(*tab) != 0)
			return (1);
		tab++;
	}
	return (0);
}
