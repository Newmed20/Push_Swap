/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:20:29 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 03:23:20 by mjadid           ###   ########.fr       */
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
	printf("\n");
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
	printf("\n");
}

