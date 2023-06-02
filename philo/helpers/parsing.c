/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:25:49 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/02 21:55:09 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_isdigit(char *av)
{
	int	i;

	i = 1;
	while (av[i++] == ' ');
	while (av[i])
	{
		if (av[i] == '+')
			i++;
		if (!ft_isdigit(av[i]))
			break ;
		i++;
	}
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	parsing(char ** av)
{
	int j;

	j = 1;
	while (av[j])
	{
		if (!check_isdigit(av[j]))
		{
			ft_error(2);
			return (0);
		}
		j++;
	}
	j = 1;
	while (av[j])
	{
		if (ft_atoi(av[j]) < 0)
		{
			ft_error(2);
			return (0);
		}
		j++;
	}
	return (1);
}