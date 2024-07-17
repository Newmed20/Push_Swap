/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:56:29 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/17 02:32:30 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
}					t_list;


//parcing.c

int	ft_atoi(const char *str);
int ft_strlen(char *str);
int     check_numbers(char *str);
int     check_empty(char *str);
void     check_args(int argc ,char **argv);

//parcing_utils.c
char *ft_strjoin(char *str1, char *str2);
char *to_join(int argc , char **argv);
void	ft_exit(void);
void 	is_dupplicated(t_list *stack_A ,int argument);
void 	ft_creat_stack(char **str , t_list **stack_A);


//linked_list_helper.c
t_list	*ft_lstnew(int content , int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);


//ft_split.c
char	**ft_split(char const *s, char c);
void	get_free(char **result);

//instructions
void    to_swap(int *nb1 , int *nb2);
void    sa(t_list   **stack_A);
void    sb(t_list   **stack_B);
void    ss(t_list **stack_A , t_list  **stack_B);
void    pa(t_list   **stack_A , t_list **stack_B);
void    pb(t_list   **stack_B , t_list **stack_A);
void    ra(t_list   **stack_A , int index);
void    rb(t_list   **stack_B , int index);
void    rr(t_list  **stack_A , t_list  **stack_B);
void    rra(t_list  **stack_A);
void    rrb(t_list  **stack_B);
void    rrr(t_list  **stack_A , t_list  **stack_B);

//SORT

t_list	*sort_stack(t_list *stack_A, int i, int swap);



#endif