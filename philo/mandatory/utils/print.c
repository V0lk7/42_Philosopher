/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:10:16 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 10:16:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%li %li has taken a fork\n", philo->time_job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%li %li is eating\n", philo->time_job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%li %li is sleeping\n", philo->time_job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%li %li is thinking\n", philo->time_job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%li %li died\n", philo->time_job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}
