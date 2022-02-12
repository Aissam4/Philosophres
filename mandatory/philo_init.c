/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:06:28 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/13 00:09:32 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// checke parameters
//parsing
//create threads
//mutex
//routine
//get_time of the day
unsigned int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int     ft_isnumber(char *number)
{
	int     i;

	i = 0;
	if (!number)
		return (1);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
				return (0);
		i++;
	}
	return (1);
}

int	philo_init(int argc, char **argv, t_args *args)
{
	args->eating_number = 1;
	if (!ft_isnumber(argv[1]) || !ft_isnumber(argv[2]) || !ft_isnumber(argv[3]) || !ft_isnumber(argv[4]) || !ft_isnumber(argv[5]))
		return (ft_putstr_fd("\e[1;91mError: Invalid Arguments\e[0m\n", 2), 1);
	args->philo_number = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		args->eating_number = ft_atoi(argv[5]);
	if (args->philo_number <= 0 || args->time_to_die <= 59
		|| args->time_to_eat <= 59 || args->time_to_sleep <= 59
		|| args->eating_number <= 0)
		return (printf("\e[1;91mError: Wrong Arguments\e[0m\n"), 1);
	return (0);
}