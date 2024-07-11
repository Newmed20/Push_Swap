/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:19:51 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/11 06:51:15 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    to_swap(int *nb1 , int *nb2)
{
    int     temp;
 
    temp    = *nb1;
    nb1     = *nb2;
    *nb2    = temp;
}
void    sa(t_list   **stack_A)
{
    t_list      *temp;

    temp = stack_A;
    if(ft_lstsize(stack_A) == 1 || ft_lstsize(stack_A) == 2)
        return;
    
    
    
}