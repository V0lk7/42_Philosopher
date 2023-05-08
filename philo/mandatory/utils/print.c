/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:10:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/08 13:07:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	print_fork(t_philo *philo)
{
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	philo->time.job = get_time(philo->time.zero);
	printf("%li %i has taken a fork\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_eat(t_philo *philo)
{
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	philo->time.job = get_time(philo->time.zero);
	printf("%li %i is eating\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_sleep(t_philo *philo)
{
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	philo->time.job = get_time(philo->time.zero);
	printf("%li %i is sleeping\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_think(t_philo *philo)
{
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	philo->time.job = get_time(philo->time.zero);
	printf("%li %i is thinking\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	philo->time.job = get_time(philo->time.zero);
	printf("%li %i died\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}
