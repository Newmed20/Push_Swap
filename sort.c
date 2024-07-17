/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:19:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/17 12:39:49 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*sort_stack(t_list *stack_A, int i, int swap)
{
	t_list *sorted_stack;
	t_list *temp;

    temp = stack_A;
    sorted_stack = NULL;
    while(temp != NULL && temp -> next != NULL )
    {
        if(temp->content > temp->next->content)
        {
            swap = temp->next->content;
            temp->next->content = temp->content;
            temp->content = swap;
            temp = stack_A;
        }
        else
            temp = temp -> next;
    }
    temp = stack_A;
    while(temp != NULL)
    {
        ft_lstadd_back(&sorted_stack, ft_lstnew(temp->content, i));
        i++;
        temp = temp->next;
    }   
	return (sorted_stack);
}
void    ft_sort3(t_list **stack)
{
    
}