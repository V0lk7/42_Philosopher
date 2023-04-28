/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 13:31:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static bool	lock_forks(t_philo *philo);
static void	eat_to_death(t_philo *philo, long time);
static void	one_philo(t_philo *philo);
static bool	eating(t_philo *philo);

void	job_eat(t_philo *philo)
{
	long	time;

	if (end_check(philo->data, philo) == true)
		return ;
	time = get_the_time(philo->time.zero) + philo->data->time_of_eat;
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	if (time >= philo->time.death)
	{
		eat_to_death(philo, time);
		return ;
	}
	if (eating(philo) == false)
		return ;
	pthread_mutex_lock(&philo->nbr_eat);
	philo->nbr_of_eat++;
	pthread_mutex_unlock(&philo->nbr_eat);
	time = get_the_time(philo->time.zero) + philo->data->time_to_die;
	philo->time.death = time;
	philo->status = SLEEP;
}

static bool	eating(t_philo *philo)
{
	if (lock_forks(philo) == false)
		return (false);
	philo->time.job = get_the_time(philo->time.zero);
	philo->data->func[EAT + PRINT](philo);
	usleep(philo->data->time_of_eat * 1000);
	pthread_mutex_unlock(&philo->fork_l->fork);
	pthread_mutex_unlock(&philo->fork_r->fork);
	return (true);
}

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_r->fork);
	philo->time.job = get_the_time(philo->time.zero);
	philo->data->func[FORK](philo);
	usleep((philo->time.death - philo->time.job) * 1000);
	pthread_mutex_unlock(&philo->fork_r->fork);
	death(philo);
}

static void	eat_to_death(t_philo *philo, long time)
{
	if (end_check(philo->data, philo) == true)
		return ;
	if ((time - philo->data->time_of_eat) == philo->time.death)
		death(philo);
	else
	{
		if (lock_forks(philo) == false)
			return ;
		time = (philo->time.death - get_the_time(philo->time.zero));
		if (time >= 0)
		{
			philo->data->func[EAT + PRINT](philo);
			usleep(time * 1000);
		}
		pthread_mutex_unlock(&philo->fork_l->fork);
		pthread_mutex_unlock(&philo->fork_r->fork);
		death(philo);
	}
}

static bool	lock_forks(t_philo *philo)
{
	if (end_check(philo->data, philo) == true)
		return (false);
	pthread_mutex_lock(&philo->fork_l->fork);
	if (end_check(philo->data, philo) == true)
	{
		pthread_mutex_unlock(&philo->fork_l->fork);
		return (false);
	}
	philo->time.job = get_the_time(philo->time.zero);
	philo->data->func[FORK](philo);
	pthread_mutex_lock(&philo->fork_r->fork);
	if (end_check(philo->data, philo) == true)
	{
		pthread_mutex_unlock(&philo->fork_l->fork);
		pthread_mutex_unlock(&philo->fork_r->fork);
		return (false);
	}
	philo->time.job = get_the_time(philo->time.zero);
	philo->data->func[FORK](philo);
	return (true);
}
