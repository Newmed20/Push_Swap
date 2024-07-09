/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:34:49 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/09 22:22:41 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"



void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i ;
	
	i	= 0;
	while(str[i])
		i++;
	return(i);
}

char *ft_strjoin(char *str1, char *str2)
{
    int i = 0;
	int j = 0;
    if (str1) 
		i = ft_strlen(str1);
    j = ft_strlen(str2);
    char *str = malloc(i + j + 2);
    if (!str)
		return NULL;
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
    return str;
}



int main(int argc , char **argv)
{
    int	i = 1 ;
	char *str = NULL;
	char *temp;
	
	
    if(argc > 1)
    {
        while(argv[i])
		{
        	temp = ft_strjoin(str , argv[i]);
			free(str);
			str = temp;
			i++;
		}
    }
	printf("[%s]" , str);
}
