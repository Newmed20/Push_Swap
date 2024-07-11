/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:56:29 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/11 02:26:39 by mjadid           ###   ########.fr       */
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
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);


//ft_split.c
char	**ft_split(char const *s, char c);
void	get_free(char **result);




#endif