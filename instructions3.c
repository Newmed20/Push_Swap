/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:26:50 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 03:27:49 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"



void    ss(t_list **stack_A , t_list  **stack_B)
{
    t_list      *temp;
    t_list      *temp1;
    int     a;
    int     b;

    temp = *stack_A;
    if(ft_lstsize(*stack_A) == 1 || ft_lstsize(*stack_A) == 2)
        return;
    a = temp->content;
    b = temp->next->content;
    to_swap(&a,&b);
    temp->content = a ;
    temp->next->content = b;
    temp1 = *stack_B;
    if(ft_lstsize(*stack_B) == 1 || ft_lstsize(*stack_B) == 2)
        return;
    
    a = temp1->content;
    b = temp1->next->content;
    to_swap(&a,&b);
    temp1->content = a ;
    temp1->next->content = b;
    write(1 , "ss\n" ,3);
}


void    rr(t_list  **stack_A , t_list  **stack_B)
{
    t_list  *temp;
    t_list  *temp1;
    
    if(ft_lstsize(*stack_A) < 2 && ft_lstsize(*stack_B) < 2 )
        return;
    temp = *stack_A;
    ft_lstadd_back(stack_A,ft_lstnew(temp->content,(*stack_A)->index));
    *stack_A = (*stack_A)->next;
    free(temp);
    temp = NULL;
    temp1 = *stack_B;
    ft_lstadd_back(stack_B,ft_lstnew(temp1->content, (*stack_B)->index));
    *stack_B = (*stack_B)->next;
    free(temp1);
    temp1 = NULL;
    write(1 , "rr\n" , 3);
}

void    rrr(t_list  **stack_A , t_list  **stack_B)
{
    t_list *temp;
    t_list *temp1;
    t_list *lastone;
    t_list *lastone1;
    
    if(ft_lstsize(*stack_A) < 2 && ft_lstsize(*stack_B) < 2)
        return;
    
    temp = *stack_A;
    while(temp->next->next != NULL)
        temp=temp->next;
    lastone = temp->next;
    temp->next = NULL;
    ft_lstadd_front(stack_A , ft_lstnew(lastone->content , lastone->index));
    temp1 = *stack_B;
    while(temp1->next->next != NULL)
        temp1=temp1->next;
    lastone1 = temp1->next;
    temp1->next = NULL;
    ft_lstadd_front(stack_B , ft_lstnew(lastone->content , lastone->index));
    write(1 , "rrr\n" , 3);
}

