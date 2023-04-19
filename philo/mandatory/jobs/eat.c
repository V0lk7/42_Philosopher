/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 17:44:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static void	eat_to_death(t_philo *philo, long time);
static void	one_philo(t_philo *philo);
static void	eating(t_philo *philo);

void	job_eat(t_philo *philo)
{
	long	time;

	time = get_the_time(philo->time->zero) + philo->data->time_of_eat;
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	if (time >= philo->time->death)
	{
		eat_to_death(philo, time);
		return ;
	}
	eating(philo);
	philo->nbr_of_eat++;
	time = get_the_time(philo->time->zero) + philo->data->time_to_die;
	philo->time->death = time;
	philo->status = SLEEP;
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_l->fork);
	philo->time->job = get_the_time(philo->time->zero);
	philo->data->func[FORK](philo);

	pthread_mutex_lock(&philo->fork_r->fork);
	philo->time->job = get_the_time(philo->time->zero);
	philo->data->func[FORK](philo);

	philo->time->job = get_the_time(philo->time->zero);
	philo->data->func[EAT + PRINT](philo);
	usleep(philo->data->time_of_eat * 1000);
	pthread_mutex_unlock(&philo->fork_l->fork);
	pthread_mutex_unlock(&philo->fork_r->fork);
}

static void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_r->fork);
	philo->time->job = get_the_time(philo->time->zero);
	philo->data->func[FORK](philo);

	usleep(philo->time->death - philo->time->zero * 1000);

	pthread_mutex_unlock(&philo->fork_r->fork);
	death(philo);
}

static void	eat_to_death(t_philo *philo, long time)
{
	if ((time - philo->data->time_of_eat) == philo->time->death)
		death(philo);
	else
	{
		pthread_mutex_lock(&philo->fork_l->fork);
		philo->time->job = get_the_time(philo->time->zero);
		philo->data->func[FORK](philo);

		pthread_mutex_lock(&philo->fork_r->fork);
		philo->time->job = get_the_time(philo->time->zero);
		philo->data->func[FORK](philo);

		time = (philo->time->death - get_the_time(philo->time->zero));
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
