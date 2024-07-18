/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:19:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/18 01:01:40 by mjadid           ###   ########.fr       */
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

// void    affect_index(t_list  **stackA , t_list *stack_tmp)
// {
//     t_list *temp:
    
//     temp = stack_tmp;
//     while(temp!= NULL)
//     {
        
//     }
// }


void    ft_sort3(t_list **stack_A)
{
    t_list *temp;
    int a;
    int b;
    int c;
    
    temp = *stack_A;
    a = temp->index;
    b = temp->next->index;
    c = temp->next->next->index;
    if(a>= b && a <=c && b <=c)
        sa(stack_A);
    else if(a>=b && b <=c && a >=c)
        ra(stack_A , (*stack_A)->index);
    else if(a <=b && b>=c && a >=c)
        rra(stack_A);
    else if(a<=b && b >=c && a <=c)
    {
        rra(stack_A);
        sa(stack_A);
    }
    else if(a>=b && b >=c && a >=c)
    {
        ra(stack_A , (*stack_A)->index);
        sa(stack_A);
    }
}

int     find_min(t_list   *stack_A)
{
    int min;
    t_list  *temp;
    
    temp = stack_A;
    min = temp->index;
    while(temp!= NULL)
    {
        if(temp->index < min )
            min = temp->index;
        temp = temp->next;
    }
    return (min);
}

int     locate_element(t_list *stack_A , int index)
{
    int counter;
    t_list  *temp;

    counter = 0;
    temp = stack_A;
    
    while(temp != NULL)
    {
        if(temp->index == index)
            return(counter);
        counter++;
        temp = temp ->next;
    }
    return(-1);
}

void    push_min(t_list   **stack_A , t_list **stack_B)
{
    int center;
    int min;
    t_list  *temp;

    temp = *stack_A;
    center = ft_lstsize(*stack_A)/2;
    min= find_min(*stack_A);
    while(temp!= NULL)
    {
        if(locate_element(*stack_A , min) == 0)
        {
            pb(stack_B , stack_A);
            return;
        }
        if(locate_element(*stack_A , (*stack_A)->index) >= center)
            rra(stack_A);
        else
            ra(stack_A , min);
    }
    
}

void    ft_sort4(t_list **stack_A, t_list  **stack_B)
{
    push_min(stack_A , stack_B);
    ft_sort3(stack_A);
    pa(stack_A , stack_B);
}