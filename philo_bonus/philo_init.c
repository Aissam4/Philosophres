/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:44:18 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/17 10:17:16 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	take_args(int ac, char **av, t_args *args)
{
	if (ac < 5)
		return (printf("\e[1;91mmissing args!\e[0m\n"), 0);
	else if (ac > 6)
		return (printf("\e[1;91mtoo many args!\e[0m\n"), 0);
	if (!ft_isnumber(av[1]) || !ft_isnumber(av[2]) || !ft_isnumber(av[3])
		|| !ft_isnumber(av[4]) || !ft_isnumber(av[5]))
		return (printf("\e[1;91mError: Invalid Arguments\e[0m\n"), 0);
	args->philo_number = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->eating_number = -1;
	if (ac == 6)
		args->eating_number = ft_atoi(av[5]);
	if (args->philo_number <= 0 || args->time_to_die <= 59
		|| args->time_to_eat <= 59 || args->time_to_sleep <= 59)
		return (printf("\e[1;91mError: Wrong Arguments\e[0m\n"), 0);
	return (1);
}

int	init_semaphores(t_sems *sems, int num_of_forks)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_print");
	sems->fork_sem = sem_open("/philo_forks", \
	O_CREAT | O_EXCL, 0700, num_of_forks);
	if (sems->fork_sem == SEM_FAILED)
		return (printf("failed to open semaphore!\n"), 0);
	sems->print_sem = sem_open("/philo_print", O_CREAT | O_EXCL, 0700, 1);
	if (sems->print_sem == SEM_FAILED)
		return (sem_close(sems->print_sem), \
		printf("failed to open semaphore!\n"), 0);
	return (1);
}

long	getms(t_philo *philo)
{
	return (gettime() - philo->start_time);
}

void	print_status(t_philo *philo, char *message)
{
	sem_wait(philo->sems->print_sem);
	printf("\033[0;36mMs : %lu \e[0m| Philo Id: [%d] \033[0;33m%s\033[0m\n",
		getms(philo), philo->id, message);
	sem_post(philo->sems->print_sem);
}
