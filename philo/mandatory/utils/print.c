/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:10:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:31:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>
#include <unistd.h>

static	bool	lock_print(t_philo *philo);
static	void	unlock_print(t_philo *philo);

void	print_job(t_philo *philo, t_status status)
{
	if (is_the_end(philo) == true)
		return ;
	if (lock_print(philo) == false)
		return ;
	philo->time.job = get_time(philo->time.zero);
	if (status == FORK)
		printf("%li %i has taken a fork\n", philo->time.job, philo->spot);
	else if (status == EAT)
		printf("%li %i is eating\n", philo->time.job, philo->spot);
	else if (status == SLEEP)
		printf("%li %i is sleeping\n", philo->time.job, philo->spot);
	else if (status == THINK)
		printf("%li %i is thinking\n", philo->time.job, philo->spot);
	else if (status == DEAD)
		printf("%li %i died\n", philo->time.job, philo->spot);
	unlock_print(philo);
}

static bool	lock_print(t_philo *philo)
{
	while (philo->print == false)
	{
		pthread_mutex_lock(&philo->data->print);
		if (philo->data->lock == false)
		{
			philo->data->lock = true;
			philo->print = true;
			pthread_mutex_unlock(&philo->data->print);
			return (true);
		}
		pthread_mutex_unlock(&philo->data->print);
		if (is_the_end(philo) == true)
			return (false);
	}
	return (true);
}

static void	unlock_print(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	philo->data->lock = false;
	pthread_mutex_unlock(&philo->data->print);
	philo->print = false;
}
