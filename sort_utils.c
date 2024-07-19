/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:29:12 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 03:30:22 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_stack(t_list *stack_A, int i, int swap)
{
	t_list	*sorted_stack;
	t_list	*temp;

	temp = stack_A;
	sorted_stack = NULL;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->content > temp->next->content)
		{
			swap = temp->next->content;
			temp->next->content = temp->content;
			temp->content = swap;
			temp = stack_A;
		}
		else
			temp = temp->next;
	}
	temp = stack_A;
	while (temp != NULL)
	{
		ft_lstadd_back(&sorted_stack, ft_lstnew(temp->content, i));
		i++;
		temp = temp->next;
	}
	return (sorted_stack);
}

void	affect_index(t_list *stack_A, t_list *stack_tmp)
{
	t_list	*tmp;

	tmp = stack_A;
	while (stack_tmp != NULL)
	{
		tmp = stack_A;
		while (tmp != NULL)
		{
			if (stack_tmp->content == tmp->content)
				tmp->index = stack_tmp->index;
			tmp = tmp->next;
		}
		stack_tmp = stack_tmp->next;
	}
}

int	find_min(t_list *stack_A)
{
	int		min;
	t_list	*temp;

	temp = stack_A;
	min = temp->index;
	while (temp != NULL)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	find_max(t_list *stack_A)
{
	int		max;
	t_list	*temp;

	temp = stack_A;
	max = temp->index;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	locate_element(t_list *stack_A, int index)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	temp = stack_A;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (counter);
		counter++;
		temp = temp->next;
	}
	return (-1);
}
