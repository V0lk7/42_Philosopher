/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/05/08 13:00:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>
#include <stdio.h>

static bool	lock_forks(t_philo *philo);
static void	one_philo(t_philo *philo);
static bool	eating(t_philo *philo);

void	job_eat(t_philo *philo)
{
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	pthread_mutex_lock(&philo->time.v_death);
	pthread_mutex_unlock(&philo->time.v_death);
	if (eating(philo) == false)
		return ;
	pthread_mutex_lock(&philo->nbr_eat);
	philo->nbr_of_eat++;
	pthread_mutex_unlock(&philo->nbr_eat);
	change_state(philo, SLEEP);
}

static bool	eating(t_philo *philo)
{
	long	time;

	if (lock_forks(philo) == false)
		return (false);
	if (am_i_dead(philo) == true || is_the_end(philo) == true)
		return (false);
	time = get_time(philo->time.zero) + philo->data->time_of_eat;
	pthread_mutex_lock(&philo->time.v_death);
	if (time > philo->time.death)
	{
		time = philo->time.death - get_time(philo->time.zero);
	}
	else
		time = philo->data->time_of_eat;
	philo->time.death = get_time(philo->time.zero) + philo->data->time_to_die;
	pthread_mutex_unlock(&philo->time.v_death);
	philo->data->func[PRINT_EAT](philo);
	usleep(time * 1000);
	pthread_mutex_unlock(&philo->fork_l->fork);
	pthread_mutex_unlock(&philo->fork_r->fork);
	return (true);
}

static void	one_philo(t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->fork_r->fork);
	philo->data->func[PRINT_FORK](philo);
	pthread_mutex_lock(&philo->time.v_death);
	time = philo->time.death - get_time(philo->time.zero);
	pthread_mutex_unlock(&philo->time.v_death);
	usleep((time) * 1000);
	pthread_mutex_unlock(&philo->fork_r->fork);
}

static bool	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_l->fork);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->fork_l->fork);
		return (false);
	}
	philo->data->func[PRINT_FORK](philo);
	pthread_mutex_lock(&philo->fork_r->fork);
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
	{
		pthread_mutex_unlock(&philo->fork_l->fork);
		pthread_mutex_unlock(&philo->fork_r->fork);
		return (false);
	}
	philo->data->func[PRINT_FORK](philo);
	return (true);
}
