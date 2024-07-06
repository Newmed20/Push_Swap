/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:39:47 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/05 13:01:05 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *ft_strjoin(char *str1 , char *str2)
{
    int i = 0;
    int j = 0;
    char *joinedstr;
    
    while(str1[i])
        i++;
    while(str2[j])
        j++;
    joinedstr = malloc(i+j+1);
    i = 0;
    j = 0;
    while(str1[i])
    {
        joinedstr[i] = str1[i];
        i++;
    }
    while(str2[j])
    {
        joinedstr[i] =str2[j];
        i++;
        j++;
    }
    joinedstr[i] = '\0';
    return(joinedstr);
}


int main(int argc , char **argv)
{
    int i = 1;
    char *str ;
    
    
    if (argc>1)
    {
        while(i<argc - 1)
        {
            str = ft_strjoin(argv[i] , argv[i+1]);
            i++;
        }
    }
    printf("[%s]" , str);
    return (0);
}

