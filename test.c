



// t_list	*sort_tab(t_list *stack_x, int i, int swap)
// {
// 	t_list	*new_node;
// 	t_list	*ptr;

// 	new_node = NULL;
// 	ptr = stack_x;
// 	while (ptr != NULL && ptr->next != NULL)
// 	{
// 		if (ptr->content > ptr->next->content)
// 		{
// 			swap = ptr->content;
// 			ptr->content = ptr->next->content;
// 			ptr->next->content = swap;
// 			ptr = stack_x;
// 		}
// 		else
// 			ptr = ptr->next;
// 	}
// 	ptr = stack_x;
// 	while (ptr != NULL)
// 	{
// 		ft_lstadd_back(&new_node, ft_lstnew(ptr->content, i));
// 		i++;
// 		ptr = ptr->next;
// 	}
// 	return (new_node);
// }

// int main*