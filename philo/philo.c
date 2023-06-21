/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:34:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/21 22:25:48 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pair(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (philo->p_data[i].id % 2 == 0)
			usleep(100);
		else
			pthread_create(&philo->philo[i], NULL, routine, &philo->p_data[i]);
	i++;
	}
}

void	ft_unpair(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (philo->p_data[i].id % 2 != 0)
			usleep(100);
		else
			pthread_create(&philo->philo[i], NULL, routine, &philo->p_data[i]);
		i++;
	}
}

int	main(int ac, char **av)
{	
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (ft_error(5));
	if (!parsing(ac, av))
		return (0);
	if (!init_philo(philo, av))
		philo->is_over = 1;
	ft_pair(philo);
	ft_unpair(philo);
	while (1)
	{
		check_for_nb_eat(philo);
		while (i < philo->nb_philo)
			if (!check_if_dead(&philo->p_data[i++]))
				break ;
		i = 0;
		if (philo->is_over == 1)
			break ;
	}
	free_philo(philo);
	return (0);
}
