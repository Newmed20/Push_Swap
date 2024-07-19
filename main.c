/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:34:49 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 04:44:02 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int size, t_list **stack_A, t_list **stack_B,
		t_list **stack_tmp)
{
	if (size == 1 || size == 2)
		ft_sort2(stack_A);
	else if (size == 3)
		ft_sort3(stack_A);
	else if (size == 4)
		ft_sort4(stack_A, stack_B);
	else if (size == 5)
		ft_sort5(stack_A, stack_B);
	else
	{
		if (size <= 100)
			sort_algo1(stack_A, stack_B, *stack_tmp, 15);
		else if (size > 100 && size < 500)
			sort_algo1(stack_A, stack_B, *stack_tmp, 25);
		else if (size >= 500)
			sort_algo1(stack_A, stack_B, *stack_tmp, 35);
		affect_index(*stack_A, *stack_tmp);
		sort_algo2(stack_A, stack_B, size);
	}
}

int	is_sorted(t_list *stack_A)
{
	t_list	*ptr;
	int		size;
	int		i;

	ptr = stack_A;
	size = ft_lstsize(stack_A);
	i = 0;
	while (ptr->next != NULL)
	{
		if (ptr->index < ptr->next->index)
			i++;
		ptr = ptr->next;
	}
	if (i == size - 1)
	{
		ft_lstclear(&stack_A);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**str;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_tmp;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	stack_tmp = NULL;
	if (argc == 1)
		exit(0);
	check_args(argc, argv);
	str = ft_split(to_join(argv), ' ');
	ft_creat_stack(str, &stack_a);
	stack_tmp = duplicate_linked_list(stack_a);
	stack_tmp = sort_stack(stack_tmp, 0, 0);
	affect_index(stack_a, stack_tmp);
	if (is_sorted(stack_a) == 0)
		return (1);
	push_swap(ft_lstsize(stack_a), &stack_a, &stack_b, &stack_tmp);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	ft_lstclear(&stack_tmp);
}
