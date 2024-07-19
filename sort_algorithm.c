/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 03:23:43 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 05:35:18 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*duplicate_linked_list(t_list *head)
{
	t_list	*current;
	t_list	*new_head;
	t_list	**last_ptr;
	t_list	*new_node;

	if (head == NULL)
		return (NULL);
	current = head;
	new_head = NULL;
	last_ptr = &new_head;
	while (current != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
			return (NULL);
		new_node->content = current->content;
		new_node->next = NULL;
		*last_ptr = new_node;
		last_ptr = &new_node->next;
		current = current->next;
	}
	return (new_head);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	lst = NULL;
}

int	locate_index(int start, int end, t_list *stack_A)
{
	if (stack_A->index >= start && stack_A->index <= end)
		return (1);
	else if (stack_A->index < start)
		return (2);
	else
		return (3);
}

void	sort_algo1(t_list **stack_A, t_list **stack_B, t_list *stack_tmp,
		int end)
{
	t_list	*tmp;
	int		start;

	tmp = *stack_A;
	start = stack_tmp->index;
	while (tmp != NULL && stack_A && stack_B)
	{
		if (locate_index(start, end, *stack_A) == 1)
		{
			pb(stack_B, stack_A);
			start++;
			end++;
		}
		else if (locate_index(start, end, *stack_A) == 2)
		{
			pb(stack_B, stack_A);
			rb(stack_B);
			start++;
			end++;
		}
		else
			ra(stack_A);
		tmp = *stack_A;
	}
}

void	sort_algo2(t_list **stack_A, t_list **stack_B, int size)
{
	int	max;
	int	mdl;
	int	x;

	mdl = size / 2;
	while (*stack_B != NULL)
	{
		if (*stack_B != NULL)
		{
			max = find_max(*stack_B);
			x = locate_element(*stack_B, max);
		}
		if (x == -1)
			break ;
		else if (x == 0)
		{
			pa(stack_A, stack_B);
			size = ft_lstsize(*stack_B);
			mdl = size / 2;
		}
		else if (x > mdl)
			rrb(stack_B);
		else if (x <= mdl)
			rb(stack_B);
	}
}
