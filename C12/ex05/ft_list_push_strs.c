#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = 0;
	return (new);
}

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list	*new;
	t_list	*temp;
	int		i;

	new = 0;
	i = 0;
	while (i < size)
	{
		temp = new
		new = ft_create_elem(strs[i]);
		new->next = temp;
		i++;
	}
	return (new);
}
