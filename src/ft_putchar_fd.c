/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 23:10:17 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/16 16:07:44 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo/philosophers.h"
#include "../philo_bonus/philosophers.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
