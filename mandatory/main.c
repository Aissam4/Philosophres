/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:25:06 by abarchil          #+#    #+#             */
/*   Updated: 2022/02/13 08:41:26 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	error_handling(int ac)
{
	if (ac < 4)
	{
		ft_putstr_fd("\e[1;91mError: Too few arguments\e[0m", 2);
		return (1);
	}
	else if (ac > 5)
	{
		ft_putstr_fd("\e[1;91mError: Too many arguments\e[0m", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_args	args;
	
	philo = NULL;
	if (error_handling(--ac) || args_init(ac, av, &args))
		return (1);
	philo = philo_init(&args);
	return (0);
}