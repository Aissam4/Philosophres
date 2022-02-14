/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:36:07 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/14 09:21:03 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_lstadd_back(t_philo *lst, t_philo *new)
{
	t_philo	*tmp;

	tmp = lst;
	if (lst == NULL)
	{
		lst = new;
		new->prev = NULL;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = lst; 
		tmp = NULL;
	}
}
