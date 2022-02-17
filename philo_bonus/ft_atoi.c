/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:46:29 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/17 10:09:33 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) && ft_isspace(*(str + i)))
		i++;
	if (*(str + i) && ft_issign(*(str + i)))
		sign *= '+' - *(str + i++) + 1;
	while (*(str + i) && ft_isdigit(*(str + i)))
	{
		num = num * 10 + *(str + i) - 48;
		i++;
	}
	return (num * sign);
}
