/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:46:24 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/17 10:10:41 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

int	ft_isnumber(char *number)
{
	int	i;

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

int	main(int ac, char **av)
{
	int		processes[200];
	t_args	args;
	t_sems	semaphore;
	int		pid;
	int		index;

	if (!take_args(ac, av, &args)
		|| !init_semaphores(&semaphore, args.philo_number))
		return (1);
	index = -1;
	while (++index < args.philo_number)
	{
		pid = fork();
		if (pid == -1)
			return (printf("fork failed: \
			resource temporarily unavailable\n"), 1);
		else if (pid == 0)
			child_process(index + 1, args, &semaphore);
		else
			processes[index] = pid;
	}
	close_program(processes, &args, &semaphore);
}
