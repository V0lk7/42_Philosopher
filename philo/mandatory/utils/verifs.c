/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:17:29 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 15:00:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	all_philo_have_eat(t_philo **philo)
{
	int		i;

	if (philo[0]->data->nbr_of_eat == -1)
		return (false);
	i = 0;
	while (philo[i])
	{
		pthread_mutex_lock(&philo[i]->nbr_eat);
		if (philo[i]->nbr_of_eat < philo[i]->data->nbr_of_eat - 1)
		{
			pthread_mutex_unlock(&philo[i]->nbr_eat);
			return (false);
		}
		pthread_mutex_unlock(&philo[i]->nbr_eat);
		i++;
	}
	return (true);
}

bool	am_i_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->v_status);
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(&philo->v_status);
		return (true);
	}
	pthread_mutex_unlock(&philo->v_status);
	return (false);
}

bool	is_he_dead(t_philo **philo)
{
	int		i;

	i = 0;
	while (philo[i])
	{
		pthread_mutex_lock(&philo[i]->time.v_death);
		if (get_time(philo[i]->time.zero) >= philo[i]->time.death)
		{
			pthread_mutex_unlock(&philo[i]->time.v_death);
			change_state(philo[i], DEAD);
			make_end(philo);
			return (true);
		}
		pthread_mutex_unlock(&philo[i]->time.v_death);
		i++;
	}
	return (false);
}

bool	is_the_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->v_status);
	if (philo->status == END)
	{
		pthread_mutex_unlock(&philo->v_status);
		return (true);
	}
	pthread_mutex_unlock(&philo->v_status);
	return (false);
}

bool	did_i_eat_all(t_philo *philo)
{
	if (philo->data->nbr_of_eat == -1)
		return (false);
	pthread_mutex_lock(&philo->nbr_eat);
	if (philo->nbr_of_eat == philo->data->nbr_of_eat)
	{
		pthread_mutex_unlock(&philo->nbr_eat);
		change_state(philo, END);
		return (true);
	}
	pthread_mutex_unlock(&philo->nbr_eat);
	return (false);
}
