/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:25 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/20 23:37:19 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*philo;
	int		left;
	int		right;

	philo = (t_data *)arg;
	ig (!check_if_dead(philo))
	{
		philo->m_philo->is_over = 1;
		return (NULL);
	}
	right = philo->id;
	left = philo->id % philo->m_philo->nb_philo + 1;
	pthread_mutex_lock(&philo->m_philo->forks[right]);
	ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	pthread_mutex_lock(&philo->m_philo->forks[left]);
	ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	philo->last_eat = get_time(0);
	ft_print(philo->m_philo, philo->id, "is eating", -1);
	ft_usleep(philo->m_philo->time_to_eat, philo->last_eat);
	pthread_mutex_unlock(&philo->m_philo->forks[right]);
	pthread_mutex_unlock(&philo->m_philo->forks[left]);
	philo->nb_eat++;
	return (NULL);
}
