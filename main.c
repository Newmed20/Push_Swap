/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:34:49 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/18 21:29:22 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void 	ft_printstack(t_list *stack_X)
{
	t_list *temp;
	
	temp = stack_X;

	while(temp)
	{
		printf("%d  " , temp->content);
		temp = temp->next;
	}
}



void 	ft_printindex(t_list *stack_X)
{
	t_list *temp;
	
	temp = stack_X;

	while(temp)
	{
		printf("%d  " , temp->index);
		temp = temp->next;
	}
}


t_list* duplicate_linked_list(t_list *head) {
    if (head == NULL) {
        return NULL;
    }

    t_list *current = head;
    t_list *new_head = NULL;
    t_list *new_tail = NULL;

    while (current != NULL) {
        t_list *new_node = malloc(sizeof(t_list));
        if (new_node == NULL)
			return NULL;
        new_node->content = current->content;
        new_node->next = NULL;

        if (new_head == NULL) {
            new_head = new_node;
            new_tail = new_node;
        } else {
            new_tail->next = new_node;
            new_tail = new_node;
        }

        current = current->next;
    }

    return new_head;
}


void	push_swap(int size, t_list **stack_A, t_list **stack_B,
		t_list **stack_tmp)
{
	if (size == 1 || size == 2)
		ft_sort2(stack_A);
	else if (size == 3)
		ft_sort3(stack_A);
	else if (size == 4)
		ft_sort4(stack_A, stack_B);
	else if (size == 5)
		ft_sort5(stack_A, stack_B);
	else
	{
		if (size <= 100)
			sort_algo1(stack_A, stack_B, *stack_tmp, 15);
		else if (size > 100 && size < 500)
			sort_algo1(stack_A, stack_B, *stack_tmp, 25);
		else if (size >= 500)
			sort_algo1(stack_A, stack_B, *stack_tmp, 35);
		affect_index(*stack_A, *stack_tmp);
		sort_algo2(stack_A, stack_B, size);
	}
}  

int main(int argc , char **argv)
{
	char  **str;
	t_list *stack_A;
	t_list *stack_B;
	t_list *stack_X;
	t_list *stack_tmp;
	
	int i;

	i	= 0;
	stack_A = NULL;
	stack_B = NULL;
	stack_tmp = NULL;
	
    if(argc ==1 )
		exit(0);
	check_args(argc , argv);
	str = ft_split( to_join(argc , argv) , ' ');
	ft_creat_stack(str , &stack_A);
	stack_tmp = duplicate_linked_list(stack_A);
	stack_tmp = sort_stack(stack_tmp , 0 ,0);
	affect_index(stack_A , stack_tmp);
	ft_printstack(stack_A);
	printf("\n\n");
	push_swap(ft_lstsize(stack_A),&stack_A , &stack_B , &stack_tmp);
	ft_printstack(stack_A);
	printf("\n\n");

	
	// ft_printindex(stack_A);
	// printf("\n\n");
	// ft_sort2(&stack_A);
	// ft_printstack(stack_A);
	// printf("\n\n");
	// ft_printindex(stack_A);
	// printf("\n\n");

	// ft_printstack(stack_tmp);
	// printf("\n\n");
	// ft_printindex(stack_tmp);

	// printf("\n\n");
	// ft_printindex(stack_tmp);

}
