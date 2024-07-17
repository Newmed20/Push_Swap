/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:34:49 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/17 15:32:34 by mjadid           ###   ########.fr       */
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




int main(int argc , char **argv)
{
	char  **str;
	t_list *stack_A;
	t_list *stack_A;
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
	ft_printstack(stack_A);
	stack_tmp = sort_stack(stack_A , 0 , 0);

	
}
