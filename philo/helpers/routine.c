/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:25 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/22 08:09:04 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_control(t_data *philo, char stat)
{
	if (stat == 'l')
	{
		pthread_mutex_lock(&philo->m_philo->forks[philo->left]);
		pthread_mutex_lock(&philo->m_philo->forks[philo->right]);
		ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
		ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	}
	else if (stat == 'u')
	{
		pthread_mutex_unlock(&philo->m_philo->forks[philo->left]);
		pthread_mutex_unlock(&philo->m_philo->forks[philo->right]);
	}
}

void	*routine(void *arg)
{
	t_data	*philo;

	philo = (t_data *)arg;
	while (1)
	{
		if (philo->m_philo->nb_eat != -1
			&& philo->nb_eat == philo->m_philo->nb_eat)
			break ;
		mutex_control(philo, 'l');
		pthread_mutex_lock(&philo->m_philo->time);
		philo->last_eat = get_time(0);
		pthread_mutex_unlock(&philo->m_philo->time);
		ft_print(philo->m_philo, philo->id, "is eating", -1);
		pthread_mutex_lock(&philo->m_philo->eat);
		philo->nb_eat++;
		pthread_mutex_unlock(&philo->m_philo->eat);
		ft_usleep(philo->m_philo->time_to_eat, philo->last_eat);
		mutex_control(philo, 'u');
		ft_print(philo->m_philo, philo->id, "is sleeping", -1);
		ft_usleep(philo->m_philo->time_to_sleep, get_time(0));
		ft_print(philo->m_philo, philo->id, "is thinking", -1);
	}
	return (NULL);
}
