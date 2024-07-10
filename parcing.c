/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:53:40 by mjadid            #+#    #+#             */
/*   Updated: 2024/07/10 08:24:38 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	result;
	int	signe;
	int	i;

	result = 0;
	signe = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
        if(result * signe > 2147483647 || result * signe < -2147483648 )
		    ft_exit();
		i++;
    }
	return (result * signe);
}

int ft_strlen(char *str)
{
	int i ;
	
	i	= 0;
	while(str[i])
		i++;
	return(i);
}
int     check_numbers(char *str)
{
    int i;

    i      = 0;
    while(str[i])
    {
        if(str[i] != 32 && !((str[i] >= 9 && str[i]<= 32) || (str[i] >= '0' && str[i]<= '9') ||(str[i] == '+' || str[i] == '-') ))
            return(1);
        if(str[i] == '+' || str[i] == '-')
        {
            if(i != 0)
            {
                if((str[i + 1] >= 9 && str[i + 1] <= 13))
                    return(1);
            }
            if (!(str[i+1]>= '0' && str[i] <= '9'))
                return(1);
        }
        i++;
    }
    return(0);
}

int     check_empty(char *str)
{
    int i;
    
    i   = 0;
    if(str[0] == '\0')
        return(1);
    while (str[i] && (str[i] == 32) )
    {
        i++;
        if(str[i] == '\0')
            return(1);
    }
    return(0);
    
}
void     check_args(int argc ,char **argv)
{
    int i;
    
    i   = 1;
    while(i<argc)
    {
        if(check_numbers(argv[i]) || check_empty(argv[i]))
            ft_exit();
        i++;
    }
}
