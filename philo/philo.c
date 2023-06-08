/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:34:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/08 10:38:53 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(int *start, int stat);

int	main(int ac, char **av)
{
	int start;
	
	if (ac == 5 || ac == 6)
	{
		if (!parsing(av))
			return (0);
	}
	get_time(&start, 0);
	return (0);
}

int get_time(int *start, int stat)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	
	if (stat == 0)
		return (*start = time.tv_usec, 0);
	return (time.tv_usec - *start);
}
