#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = 0;
	return (new);
}

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 1;
	while (begin_list->next != 0)
	{
		count++;
		begin_list++;
	}
	return count;
}
