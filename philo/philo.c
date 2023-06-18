/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:34:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/18 14:50:40 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{	
	t_philo	*philo;
	
	if (!parsing(ac, av))
		return (0);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (ft_error(5));
	if (!init_philo(philo, av))
		philo->is_over = 1;
	while (1)
	{
		if (philo->is_over)
			break ;
	}
	free_philo(philo);
	return (0);
}
