/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:59:08 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/19 04:26:57 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *str1, char *str2, int i, int j)
{
	char	*str;

	if (str1)
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	str = malloc(i + j + 2);
	if (!str)
		return (NULL);
	i = 0;
	if (str1)
	{
		while (str1[i])
		{
			str[i] = str1[i];
			i++;
		}
	}
	str[i++] = ' ';
	j = 0;
	while (str2[j])
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str2);
	free(str1);
	return (str);
}

char	*to_join(char **argv)
{
	int		i;
	char	*str;
	char	*temp;

	i = 1;
	str = NULL;
	while (argv[i])
	{
		temp = ft_strjoin(str, argv[i], 0, 0);
		free(str);
		str = temp;
		i++;
	}
	return (str);
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	is_dupplicated(t_list *stack_A, int argument)
{
	t_list	*temp;

	temp = stack_A;
	while (temp)
	{
		if (temp->content == argument)
			ft_exit();
		temp = temp->next;
	}
}

void	ft_creat_stack(char **str, t_list **stack_A)
{
	int		i;
	t_list	*temp;
	int		argument;

	i = 0;
	while (str[i])
	{
		argument = ft_atoi(str[i]);
		is_dupplicated(*stack_A, argument);
		temp = ft_lstnew(argument, 0);
		ft_lstadd_back(stack_A, temp);
		i++;
	}
}
