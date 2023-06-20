/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:21:25 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/20 18:49:23 by yes-slim         ###   ########.fr       */
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
	return (NULL);
}
