/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:25:49 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/03 16:02:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_isdigit(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '+')
			i++;
		if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_val(char **av)
{
	int i;

	i = 1;
	if (ft_atoi(av[i++]) < 1)
		return (0);
	while (av[i])
		if (ft_atoi(av[i++]) < 60)
			return (0);
	return (1);
}

int	parsing(char **av)
{
	int j;

	j = 1;
	while (av[j])
	{
		if (!check_isdigit(av[j]))
			return (ft_error(2));
		j++;
	}
	j = 1;
	while (av[j])
	{
		if (ft_atoi(av[j]) < 0)
			return (ft_error(2));
		j++;
	}
	if (!check_val(av))
		return (ft_error(2));
	return (1);
}
