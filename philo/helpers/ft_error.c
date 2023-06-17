/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:54:05 by yes-slim          #+#    #+#             */
/*   Updated: 2023/06/17 11:01:24 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int err)
{
	if (err == 1)
		printf("Error: Wrong number of arguments !\n");
	if (err == 2)
		printf("Error: Invalide value !\n");
	if (err == 3)
		printf("Error: Threads creation failed !\n");
	if (err == 4)
		printf("Error: Mutex creation failed !\n");
	if (err == 5)
		printf("Error: Mallocation failed !\n");
	return (0);
}
