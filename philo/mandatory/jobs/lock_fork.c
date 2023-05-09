/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 08:44:45 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:30:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

bool	lock_forks(t_philo *philo)
{
	while (philo->fork_right == false && philo->fork_left == false)
	{
		if (take_fork(philo, 1) == true)
			philo->fork_right = true;
		if (take_fork(philo, 0) == true)
			philo->fork_left = true;
		if (am_i_dead(philo) == true || is_the_end(philo) == true)
		{
			unlock_forks(philo);
			return (false);
		}
		usleep(10);
	}
	return (true);
}

bool	take_fork(t_philo *philo, int which)
{
	if (which == 1)
	{
		pthread_mutex_lock(&philo->fork_r->fork);
		if (philo->fork_r->lock == false)
		{
			philo->fork_r->lock = true;
			pthread_mutex_unlock(&philo->fork_r->fork);
			print_job(philo, FORK);
			return (true);
		}
		pthread_mutex_unlock(&philo->fork_r->fork);
		return (false);
	}
	pthread_mutex_lock(&philo->fork_l->fork);
	if (philo->fork_l->lock == false)
	{
		philo->fork_l->lock = true;
		pthread_mutex_unlock(&philo->fork_l->fork);
		print_job(philo, FORK);
		return (true);
	}
	pthread_mutex_unlock(&philo->fork_l->fork);
	return (false);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->fork_right == true)
	{
		pthread_mutex_lock(&philo->fork_r->fork);
		philo->fork_r->lock = false;
		pthread_mutex_unlock(&philo->fork_r->fork);
		philo->fork_right = false;
	}
	if (philo->fork_left == true)
	{
		pthread_mutex_lock(&philo->fork_l->fork);
		philo->fork_l->lock = false;
		pthread_mutex_unlock(&philo->fork_l->fork);
		philo->fork_left = false;
	}
}
