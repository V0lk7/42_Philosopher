/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:10:16 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 17:05:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	print_fork(t_philo *philo)
{
	long	time;

	time = philo->time->job;
	pthread_mutex_lock(&philo->data->print);
	printf("%li %i has taken a fork\n", time, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_eat(t_philo *philo)
{
	long	time;

	time = philo->time->job;
	pthread_mutex_lock(&philo->data->print);
	printf("%li %i is eating\n", time, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_sleep(t_philo *philo)
{
	long	time;

	time = philo->time->job;
	pthread_mutex_lock(&philo->data->print);
	printf("%li %i is sleeping\n", time, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_think(t_philo *philo)
{
	long	time;

	time = philo->time->job;
	pthread_mutex_lock(&philo->data->print);
	printf("%li %i is thinking\n", time, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_death(t_philo *philo)
{
	long	time;

	time = philo->time->job;
	pthread_mutex_lock(&philo->data->print);
	printf("%li %i died\n", time, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}
