/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:46:38 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/17 10:17:16 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_sems
{
	sem_t	*fork_sem;
	sem_t	*print_sem;
}	t_sems;

typedef struct s_args
{
	int	philo_number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eating_number;
}	t_args;

typedef struct s_philo
{
	int		id;
	long	last_meal;
	long	start_time;
	int		isdied;
	int		isfull;
	t_sems	*sems;
	t_args	args;
}	t_philo;

long	gettime(void);
int		ft_isdigit(int c);
int		ft_isnumber(char *number);
int		take_args(int ac, char **av, t_args *args);
int		ft_atoi(char *str);
int		init_semaphores(t_sems *sems, int num_of_forks);
long	getms(t_philo *philo);
void	print_status(t_philo *philo, char *msg);
void	close_program(int processes[200], t_args *args, t_sems *sems);
void	child_process(int id, t_args args, t_sems *sems);
void	check_health(t_philo *philo);
void	*routine(void *arg);

#endif