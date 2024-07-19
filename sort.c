/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:19:58 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 03:30:37 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    push_min(t_list   **stack_A , t_list **stack_B , int size)
{
    int center;
    int min;
    t_list  *temp;

    temp = *stack_A;
    center = size/2;
    min= find_min(*stack_A);
    while(temp!= NULL)
    {
        if(locate_element(*stack_A , min) == 0)
        {
            pb(stack_B , stack_A);
            break;
        }
        if(locate_element(*stack_A , min )>= center)
            rra(stack_A);
        else if (locate_element(*stack_A , min ) < center)
            ra(stack_A , min);
    }
    
}



void    ft_sort2(t_list **stack_A)
{
    t_list *temp;
    int a;
    int b;
    
    if(ft_lstsize(*stack_A) == 1)
        return;
    temp = *stack_A;
    a = temp->content;
    b = temp->next->content;
    if(a > b)
        sa(stack_A);
}

void    ft_sort3(t_list **stack_A)
{
    t_list *temp;
    int a;
    int b;
    int c;
    
    temp = *stack_A;
    a = temp->content;
    b = temp->next->content;
    c = temp->next->next->content;
    if(a> b && a <c && b <c)
        sa(stack_A);
    else if(a>b && b <c && a >c)
        ra(stack_A , (*stack_A)->index);
    else if(a <b && b>c && a >c)
        rra(stack_A);
    else if(a<b && b >c && a <c)
    {
        sa(stack_A);
        ra(stack_A , (*stack_A)->index);
    }
    else if(a>b && b >c && a >c)
    {
        sa(stack_A);
        rra(stack_A);
    }
}
void    ft_sort4(t_list **stack_A, t_list  **stack_B )
{
    push_min(stack_A , stack_B , 4);
    ft_sort3(stack_A);
    pa(stack_A , stack_B);
}

void    ft_sort5(t_list **stack_A, t_list  **stack_B)
{
    push_min(stack_A , stack_B , 5);
    ft_sort4(stack_A , stack_B);
    pa(stack_A , stack_B);
}
