/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:02:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>
#include <stdio.h>

static void	one_philo(t_philo *philo);
static bool	eating(t_philo *philo);

void	job_eat(t_philo *philo)
{
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	if (lock_forks(philo) == false)
	{
		if (am_i_dead(philo) == true)
			print_job(philo, DEAD);
		return ;
	}
	if (eating(philo) == false)
	{
		print_job(philo, DEAD);
		return ;
	}
	pthread_mutex_lock(&philo->nbr_eat);
	philo->nbr_of_eat++;
	pthread_mutex_unlock(&philo->nbr_eat);
	change_state(philo, SLEEP);
}

static bool	eating(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->time.v_death);
	philo->time.death = get_time(philo->time.zero) + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->time.v_death);
	print_job(philo, EAT);
	time = get_time(philo->time.zero) + philo->data->time_of_eat;
	while (get_time(philo->time.zero) < time)
	{
		if (is_the_end(philo) == true)
		{
			unlock_forks(philo);
			return (false);
		}
	}
	unlock_forks(philo);
	return (true);
}

static void	one_philo(t_philo *philo)
{
	long	time;

	take_fork(philo, 1);
	pthread_mutex_lock(&philo->time.v_death);
	time = philo->time.death - get_time(philo->time.zero);
	pthread_mutex_unlock(&philo->time.v_death);
	usleep((time) * 1000);
	unlock_forks(philo);
}
