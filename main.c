/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:25:06 by abarchil          #+#    #+#             */
/*   Updated: 2022/01/11 12:20:36 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	error_handling(int ac)
{
	if (ac < 4)
	{
		ft_putstr_fd("\e[1;91mToo few arguments\e[0m", 2);
		exit(1);
	}
	else if (ac > 5)
	{
		ft_putstr_fd("\e[1;91mToo many arguments\e[0m", 2);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	error_handling(--ac);
	return (0);
}