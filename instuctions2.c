/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instuctions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:24:41 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 03:37:22 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_list   **stack_B)
{
    t_list      *temp;
    int     a;
    int     b;

    temp = *stack_B;
    if(ft_lstsize(*stack_B) == 1 || ft_lstsize(*stack_B) == 2)
        return;
    
    a = temp->content;
    b = temp->next->content;
    to_swap(&a,&b);
    temp->content = a ;
    temp->next->content = b;
    write(1 , "sb\n" ,3);
}

void    pb(t_list   **stack_B , t_list **stack_A)
{
    t_list *temp;
    
    if (*stack_A == NULL || stack_A == NULL) {
        printf("null\n");
		return ;
    }
    if(ft_lstsize(*stack_A) == 0){
            printf("size is 0\n");
        return ;
    }
    temp = *stack_A;
    ft_lstadd_front(stack_B , ft_lstnew(temp->content , temp->index));
    *stack_A = (*stack_A)->next;
    free(temp);
    temp = NULL;
    write(1 , "pb\n" , 3);
}

void    rb(t_list   **stack_B , int index)
{
    t_list	*temp;

	if (*stack_B == NULL || (*stack_B)->next == NULL || stack_B == NULL)
		return ;
	temp = *stack_B;
	ft_lstadd_back(stack_B, ft_lstnew(temp->content, index));
	*stack_B = (*stack_B)->next;
	free(temp);
	temp = NULL;
	write(1 , "rb\n" , 3);
}



void    rrb(t_list  **stack_B)
{
    t_list *temp;
    t_list *lastone;
    
    if(ft_lstsize(*stack_B) < 2)
        return;
    
    temp = *stack_B;
    while(temp->next->next != NULL)
        temp=temp->next;
    lastone = temp->next;
    temp->next = NULL;
    ft_lstadd_front(stack_B , ft_lstnew(lastone->content , lastone->index));
    write(1 , "rrb\n" , 4);
}

