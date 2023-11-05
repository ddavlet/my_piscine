#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*b_list;
	t_list	*prev_list;
	t_list	*tmp;

	b_list =*begin_list;
	prev_list = 0;
	if (begin_list == 0)
		return ;
	if (data_ref == 0)
		return ;
	while (b_list)
	{
		if (cmp(b_list->data, data_ref) == 0)
		{
			if (prev_list == 0)
			{
				*begin_list = b_list->next;
				free_fct(b_list);
				b_list = b_list->next;
			}
			else
			{
				prev_list->next = b_list->next;
				free_fct(b_list);
				b_list = prev_list->next;
			}
		}
		else
		{
			prev_list = prev_list->next;
			b_list = b_list->next;
		}
	}
}
