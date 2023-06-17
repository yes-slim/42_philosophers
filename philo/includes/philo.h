/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:53:36 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/17 09:28:27 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

/*===================struct================*/
typedef struct p_philo {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start;
	int				is_over;
	pthread_mutex_t	*forks;
	pthread_t 		*philo;
} t_philo;

/*===================helpers===============*/
int		ft_atoi(const char *str);
int		parsing(int ac, char **av);
int		ft_error(int err);
long	get_time(long start);
void	ft_usleep(long time, long start);
int		init_philo(t_philo *philo, char **av);
void	free_philo(t_philo *philo);
/*==========================================*/

#endif