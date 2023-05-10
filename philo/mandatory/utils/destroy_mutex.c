/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:38:38 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 09:02:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_all_mutex(t_data *data, t_philo **philo, t_fork **forks)
{
	pthread_mutex_destroy(&data->print);
	destroy_mutex_forks(forks, -1);
	destroy_mutex_verif(philo, -1);
	destroy_mutex_philo(philo, -1);
	destroy_mutex_time(philo, -1);
}

void	destroy_mutex_time(t_philo **philo, int i)
{
	if (i == -1)
	{
		i = 0;
		while (philo[i])
		{
			pthread_mutex_destroy(&philo[i]->time.v_death);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i]->time.v_death);
		i--;
	}
	return ;
}

void	destroy_mutex_forks(t_fork **forks, int i)
{
	if (i == -1)
	{
		i = 0;
		while (forks[i])
		{
			pthread_mutex_destroy(&forks[i]->fork);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&forks[i]->fork);
		i--;
	}
	return ;
}

void	destroy_mutex_philo(t_philo **philo, int i)
{
	if (i == -1)
	{
		i = 0;
		while (philo[i])
		{
			pthread_mutex_destroy(&philo[i]->nbr_eat);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i]->nbr_eat);
		i--;
	}
	return ;
}

void	destroy_mutex_verif(t_philo **philo, int i)
{
	if (i == -1)
	{
		i = 0;
		while (philo[i])
		{
			pthread_mutex_destroy(&philo[i]->v_status);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i]->v_status);
		i--;
	}
}
