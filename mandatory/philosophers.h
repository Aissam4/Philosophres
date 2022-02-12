/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:31:33 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/12 23:56:30 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_number;
	pthread_mutex_t	print;
}	t_args;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	unsigned int	should_die;
	size_t			last_time_to_eat;
	t_args			*args;
	pthread_mutex_t	fork;
	struct s_philo *next;
	struct s_philo *head;
}	t_philo;

int		ft_isdigit(int c);
int     ft_isnumber(char *number);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);


int	philo_init(int argc, char **argv, t_args *args);

#endif