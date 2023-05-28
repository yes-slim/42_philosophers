/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:25:49 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/28 22:04:42 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_isdigit(char *av)
{
	
}

int	check_ispositif(char *av)
{
	
}

int	parsing(int ac, char ** av)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (av[j])
	{
		while (av[j][i])
		{
			if (av[j][i] == '+')
				i++;
			if (!ft_isdigit(av[j][i]))
			{
				ft_error(2);
				return (0);
			}
			i++;
		}
		j++;
	}
	j = 0;
	while (j < ac)
	{
		if (ft_atoi(av[j]) < 0 || ft_atoi(av[j]) > INT_MAX)
		{
			ft_error(2);
			return (0);
		}
		j++;
	}
	return (1);
}