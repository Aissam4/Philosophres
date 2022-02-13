/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:06:28 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/13 10:14:50 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//deach all threads when u finish
//routine

// ft_put_str("is thinking", philosopher->id, philosopher->args);
// 	pthread_mutex_lock(&philosopher -> fork);
// 	ft_put_str("has taken a fork", philosopher->id, philosopher->args);
// 	pthread_mutex_lock(philosopher -> next_fork);
// 	ft_put_str("has taken a fork", philosopher->id, philosopher->args);
// 	philosopher->should_die = get_time() + philosopher->args->time_die;
// 	ft_put_str("is eating", philosopher->id, philosopher->args);
// 	usleep(philosopher->args->time_eat * 1000);
// 	pthread_mutex_unlock(&philosopher -> fork);
// 	pthread_mutex_unlock(philosopher -> next_fork);
// 	ft_put_str("is sleeping", philosopher->id, philosopher->args);
// 	usleep(philosopher->args->time_sleep * 1000);

size_t	get_time(void)
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

int	args_init(int argc, char **argv, t_args *args)
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

t_philo	*philo_init(t_args *args)
{
	int		i;
	t_philo *philo;

	i = -1;
	args->starting_time = get_time();
	pthread_mutex_init(&args->print, NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * args->philo_number); 
	if (!philo)
		return (ft_putstr_fd("Error : Allocation field\n", 2), exit(1), NULL);
	while (++i < args->philo_number)
	{
		philo[i].philo_id = i + 1;
		philo[i].args = args;
		pthread_mutex_init(&philo[i].fork, NULL);
		if (i == args->philo_number - 1)
			philo[i].next_fork = philo[0].fork;
		else
			philo[i].next_fork = philo[i + 1].fork;
	}
	return(philo);
}

void	*routine(void *philo)
{
	int	i;
	t_philo *tmp_philo;

	i = -1;
	tmp_philo = (t_philo *)philo;
	while (++i < tmp_philo[0].args->philo_number)
	{
		printf("%d is Thinking...\n", tmp_philo[i].philo_id);
	}
	return (NULL);
}

int	creat_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].args->philo_number)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]) != 0)
			return (free(philo), ft_putstr_fd("\e[1;91mError: Thread creation failed\e[0m\n", 2), -1);
		usleep(25);
	}
	return (0);
}