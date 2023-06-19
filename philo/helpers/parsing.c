/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:25:49 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/19 23:12:54 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		si;
	long	res;

	i = 0;
	res = 0;
	si = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			si *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > INT_MAX)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)res * si);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

int	check_val(char *av)
{
	int	i;

	i = 1;
	if (!ft_atoi(av))
		return (0);
	return (1);
}

int	parsing(int ac, char **av)
{
	int	j;

	if (ac < 5 || ac > 6)
		return (ft_error(1));
	j = 1;
	while (av[j])
	{
		if (!check_isdigit(av[j]) || !check_val(av[j]))
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
	return (1);
}
