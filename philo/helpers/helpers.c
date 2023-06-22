/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 08:29:03 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/22 20:29:44 by yes-slim         ###   ########.fr       */
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

void	ft_usleep(long time, long start)
{
	long	t;

	t = get_time(start);
	while (get_time(start) - t < time)
		usleep(100);
}

void	check_for_nb_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->nb_eat == -1)
		return ;
	pthread_mutex_lock(&philo->eat);
	while (i < philo->nb_philo)
	{
		if (philo->p_data[i].nb_eat < philo->nb_eat)
		{	
			pthread_mutex_unlock(&philo->eat);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&philo->eat);
	philo->is_over = 1;
}

void	ft_print(t_philo *philo, int id, char *str, int is_over)
{
	pthread_mutex_lock(&philo->print);
	printf("%ld %d %s\n", get_time(philo->start), id, str);
	if (!is_over)
		return ;
	pthread_mutex_unlock(&philo->print);
}

int	check_if_dead(t_data *philo)
{
	pthread_mutex_lock(&philo->m_philo->time);
	if (get_time(0) - philo->last_eat >= philo->m_philo->time_to_die)
	{
		philo->m_philo->is_over = 1;
		ft_print(philo->m_philo, philo->id, "died", 0);
		pthread_mutex_unlock(&philo->m_philo->time);
		return (0);
	}
	pthread_mutex_unlock(&philo->m_philo->time);
	return (1);
}
