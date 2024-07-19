/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:19:51 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 05:34:34 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_swap(int *nb1, int *nb2)
{
	int	temp;

	temp = *nb1;
	*nb1 = *nb2;
	*nb2 = temp;
}

void	sa(t_list **stack_A)
{
	t_list	*temp;
	int		a;
	int		b;

	temp = *stack_A;
	if (ft_lstsize(*stack_A) == 1)
		return ;
	a = temp->content;
	b = temp->next->content;
	to_swap(&a, &b);
	temp->content = a;
	temp->next->content = b;
     a = temp->index;
    b = temp->next->index;
    to_swap(&a,&b);
    temp->index = a ;
    temp->next->index = b;
	write(1, "sa\n", 3);
}

void	pa(t_list **stack_A, t_list **stack_B)
{
	t_list	*temp;

	if (ft_lstsize(*stack_B) == 0)
		return ;
	temp = *stack_B;
	ft_lstadd_front(stack_A, ft_lstnew(temp->content, 0));
	*stack_B = (*stack_B)->next;
	free(temp);
	temp = NULL;
	write(1, "pa\n", 3);
}

void	ra(t_list **stack_A)
{
	t_list	*temp;

	if (ft_lstsize(*stack_A) < 2)
		return ;
	temp = *stack_A;
	ft_lstadd_back(stack_A, ft_lstnew(temp->content, temp->index));
	*stack_A = (*stack_A)->next;
	free(temp);
	temp = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list **stack_A)
{
	t_list	*temp;
	t_list	*lastone;

	if (ft_lstsize(*stack_A) < 2)
		return ;
	temp = *stack_A;
	while (temp->next->next != NULL)
		temp = temp->next;
	lastone = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_A, ft_lstnew(lastone->content, lastone->index));
	write(1, "rra\n", 4);
}
