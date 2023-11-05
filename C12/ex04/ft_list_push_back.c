#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = 0;
	return (new);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new;
	t_list *ptr;

	new = ft_create_elem (data);
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	ptr = *begin_list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}