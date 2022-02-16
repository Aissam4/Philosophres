/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:51:26 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/16 16:07:56 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philosophers.h"
#include "../philo_bonus/philosophers.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}
