/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 11:41:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eat_to_death(t_philo *philo, long time);
static void	one_philo(t_philo *philo);

void	job_eat(t_philo *philo)
{
	long	time;

	time = get_the_time() + philo->data->time_of_eat;
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	if (time >= philo->time_of_death)
	{
		death(philo);
		return ;
	}
	philo->nbr_of_eat++;
	philo->time_of_death = get_the_time() + philo->data->time_of_death;
	philo->status = SLEEP;
}

static void	eating(t_philo *philo)
{
	philo->time_job = get_the_time();
	pthread_mutex_lock(&philo->fork_l->fork);
	philo->time_job = get_the_time();
	philo->data->func[FORK](philo);
	pthread_mutex_lock(&philo->fork_r->fork);
	philo->time_job = get_the_time();
	philo->data->func[FORK](philo);
	philo->data->func[EAT + PRINT](philo);
	usleep(philo->data->time_of_eat * 1000);
	pthread_mutex_unlock(&philo->fork_l->fork);
	pthread_mutex_unlock(&philo->fork_r->fork);
}

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_r->fork);
	philo->time_job = get_the_time();
	philo->data->func[FORK](philo);
	usleep(philo->time_of_death - get_the_time() * 1000);
	death(philo);
	pthread_mutex_unlock(&philo->fork_r->fork);
}

static void	eat_to_death(t_philo *philo, long time)
{
	if ((time - philo->data->time_of_eat) == philo->time_of_death)
		death(philo);
	else
	{
		pthread_mutex_lock(&philo->fork_l->fork);
		philo->time_job = get_the_time();
		philo->data->func[FORK](philo);
		pthread_mutex_lock(&philo->fork_r->fork);
		philo->time_job = get_the_time();
		philo->data->func[FORK](philo);
		time = (philo->time_of_death - get_the_time()) * 1000;
		if (time >= 0)
		{
			philo->data->func[EAT + PRINT](philo);
			usleep(time);
		}
		death(philo);
	}
}
