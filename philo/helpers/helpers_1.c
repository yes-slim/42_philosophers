/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:29:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/16 21:14:38 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(long start)
{
	struct timeval	time;
	long			t;
	
	gettimeofday(&time, NULL);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t - start);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time(0);
	while (get_time(start) < time)
		usleep(100);
}

void	init_philo(t_philo *philo, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->nb_eat = -1;
	if (av[5])
		philo->nb_eat = ft_atoi(av[5]);
	philo->start = get_time(0);
	philo->forks = malloc(sizeof(pthread_mutex_t) * (philo->nb_philo + 1));
	philo->philo = malloc(sizeof(pthread_t) * (philo->nb_philo + 1));
}