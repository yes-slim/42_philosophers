/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:25 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/20 18:14:47 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*philo;
	int		left;
	int		right;

	philo = (t_data *)arg;
	check_if_dead(philo);
	right = philo->id;
	left = philo->id % philo->m_philo->nb_philo + 1;
	pthread_mutex_lock(&philo->m_philo->forks[right]);
	ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	pthread_mutex_lock(&philo->m_philo->forks[left]);
	ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	philo->last_eat = get_time(0);
	ft_print(philo->m_philo, philo->id, "is eating", -1);
	ft_usleep(philo->m_philo->time_to_eat, get_time(0));
	pthread_mutex_unlock(&philo->m_philo->forks[right]);
	pthread_mutex_unlock(&philo->m_philo->forks[left]);
	philo->nb_eat++;
	ft_print(philo->m_philo, philo->id, "is sleeping", -1);
	ft_usleep(philo->m_philo->time_to_sleep, get_time(0));
	ft_print(philo->m_philo, philo->id, "is thinking", -1);
	return (NULL);
}
