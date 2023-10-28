#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list *temp;
	t_list *prev_list;
	t_list *next_list;

	if (!*begin_list || !(*begin_list)->next)
		return;
	prev_list = *begin_list;
	next_list = prev_list->next;
	prev_list->next = 0;
	while (next_list->next)
	{
		temp = next_list->next;
		next_list->next = prev_list;
		prev_list = next_list;
		next_list = temp;
	}
	next_list->next = prev_list;
	*begin_list = next_list;
}
