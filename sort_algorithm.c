



#include "push_swap.h"

int	locate_index(int start, int end, t_list *stack_A)
{
	if (stack_A->index >= start && stack_A->index <= end)
		return (1);
	else if (stack_A->index < start)
		return (2);
	else
		return (3);
}

void	sort_algo1(t_list **stack_A, t_list **stack_B, t_list *stack_tmp, int end)
{
	t_list	*tmp;
	int		start;

	tmp = *stack_A;
	start = stack_tmp->index;
	while (tmp != NULL)
	{
		if (locate_index(start, end, *stack_A) == 1)
		{
			pb(stack_A, stack_B);
			start++;
			end++;
		}
		else if (locate_index(start, end, *stack_A) == 2)
		{
			pb(stack_A, stack_B);
			rb(stack_B, (*stack_B)->index);
			start++;
			end++;
		}
		else if (locate_index(start, end, *stack_A) == 3)
			ra(stack_A, (*stack_A)->index);
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
			rb(stack_B, (*stack_B)->index);
	}
}
