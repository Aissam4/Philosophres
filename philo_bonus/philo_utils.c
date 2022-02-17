/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:46:44 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/17 10:17:16 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->args.eating_number-- && !philo->isdied)
	{
		sem_wait(philo->sems->fork_sem);
		print_status(philo, "has taken a fork");
		sem_wait(philo->sems->fork_sem);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		usleep(philo->args.time_to_eat * 1e3);
		philo->last_meal = gettime();
		sem_post(philo->sems->fork_sem);
		sem_post(philo->sems->fork_sem);
		print_status(philo, "is sleeping");
		usleep(philo->args.time_to_sleep * 1e3);
		print_status(philo, "is thinking");
	}
	philo->isfull = 1;
	return (arg);
}

void	check_health(t_philo *philo)
{
	while (1)
	{
		if (philo->isfull)
			exit(1);
		if (gettime() - philo->last_meal >= philo->args.time_to_die + 5)
		{
			sem_wait(philo->sems->print_sem);
			philo->isdied = 1;
			printf("\033[0;31mMs : %lu | Philo Id: [%d] %s \n",
				getms(philo), philo->id, "philo is died\033[0m");
			exit(1);
		}
	}
}

void	child_process(int id, t_args args, t_sems *sems)
{
	pthread_t	th;
	t_philo		philo;

	philo.args = args;
	philo.id = id;
	philo.last_meal = gettime();
	philo.start_time = gettime();
	philo.isdied = 0;
	philo.sems = sems;
	philo.isfull = 0;
	if (pthread_create(&th, NULL, &routine, &philo) != 0)
		return (printf("Can't create the thread!\n"), exit(4));
	if (pthread_detach(th) != 0)
		return (printf("Can't detach the thread!\n"), exit(5));
	check_health(&philo);
	exit(0);
}

void	close_program(int processes[200], t_args *args, t_sems *sems)
{
	int	status;
	int	j;

	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 1)
	{
		j = -1;
		while (++j < args->philo_number)
			kill(processes[j], SIGTERM);
	}
	sem_close(sems->fork_sem);
	sem_close(sems->print_sem);
}
