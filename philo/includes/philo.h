/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:53:36 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/22 08:08:38 by yes-slim         ###   ########.fr       */
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
	pthread_t		*philo;
	struct p_data	*p_data;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
	pthread_mutex_t	eat;
}	t_philo;

typedef struct p_data {
	int				id;
	int				right;
	int				left;
	int				nb_eat;
	long			last_eat;
	struct p_philo	*m_philo;
}	t_data;

/*===================helpers===============*/
int		ft_atoi(const char *str);
int		parsing(int ac, char **av);
int		ft_error(int err);
long	get_time(long start);
void	ft_usleep(long time, long start);
int		init_philo(t_philo *philo, char **av);
void	free_philo(t_philo *philo);
void	check_for_nb_eat(t_philo *philo);
int		check_if_dead(t_data *philo);
void	*routine(void *arg);
void	ft_print(t_philo *philo, int id, char *str, int is_over);
/*==========================================*/
#endif