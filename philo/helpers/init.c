/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:10:02 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/20 23:49:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= philo->nb_philo)
	{
		philo->p_data[i].id = j;
		philo->p_data[i].right = i;
		philo->p_data[i].left = i % philo->nb_philo + 1;
		philo->p_data[i].nb_eat = 0;
		philo->p_data[i].last_eat = philo->start;
		philo->p_data[i].m_philo = philo;
		i++;
		j++;
	}
}

void	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

int	init_philo(t_philo *philo, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->nb_eat = -1;
	if (av[5])
		philo->nb_eat = ft_atoi(av[5]);
	philo->start = get_time(0);
	philo->is_over = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * (philo->nb_philo));
	if (!philo->forks)
		return (ft_error(4));
	philo->philo = malloc(sizeof(pthread_t) * (philo->nb_philo));
	if (!philo->philo)
		return (ft_error(3));
	philo->p_data = malloc(sizeof(t_data) * (philo->nb_philo));
	if (!philo->p_data)
		return (ft_error(5));
	pthread_mutex_init(&philo->print, NULL);
	init_data(philo);
	init_mutex(philo);
	return (1);
}

void	free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_detach(philo->philo[i]);
		pthread_mutex_destroy(&philo->forks[i]);
		free(&philo->p_data[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->print);
	free(philo->forks);
	free(philo->philo);
	free(philo->p_data);
	free(philo);
}
