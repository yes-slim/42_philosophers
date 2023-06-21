/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:25 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/21 14:26:41 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_control(t_data *philo, char stat)
{
	if (stat == 'l')
	{
		pthread_mutex_lock(&philo->m_philo->forks[philo->left]);
		ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
		pthread_mutex_lock(&philo->m_philo->forks[philo->right]);
		ft_print(philo->m_philo, philo->id, "has taken a fork", -1);
	}
	else if (stat == 'u')
	{
		pthread_mutex_lock(&philo->m_philo->forks[philo->right]);
		pthread_mutex_lock(&philo->m_philo->forks[philo->left]);
	}
}

void	*routine(void *arg)
{
	t_data	*philo;

	philo = (t_data *)arg;
	if (!check_if_dead(philo))
	{
		philo->m_philo->is_over = 1;
		return (NULL);
	}
	mutex_control(philo, 'l');
	philo->last_eat = get_time(0);
	ft_print(philo->m_philo, philo->id, "is eating", -1);
	ft_usleep(philo->m_philo->time_to_eat, philo->last_eat);
	mutex_control(philo, 'u');
	ft_print(philo->m_philo, philo->id, "is sleeping", -1);
	ft_usleep(philo->m_philo->time_to_sleep, get_time(0));
	ft_print(philo->m_philo, philo->id, "is thinking", -1);
	philo->nb_eat++;
	return (NULL);
}