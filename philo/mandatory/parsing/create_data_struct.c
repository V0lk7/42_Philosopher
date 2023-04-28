/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:00:20 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 11:48:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

static t_fork	*last_fork(t_fork **forks);
static void		distribute_forks(t_philo *philo, t_fork **forks, int i);
static int		put_data_in_philo(t_philo *philo,
					t_data *data, t_fork **forks, int i);

t_fork	**create_forks(t_data data)
{
	t_fork	**forks;
	int		i;

	i = -1;
	forks = malloc(sizeof(t_fork *) * (data.nbr_of_philo + 1));
	if (forks == NULL)
		return (NULL);
	while (++i < data.nbr_of_philo)
	{
		forks[i] = malloc(sizeof(t_fork));
		forks[i + 1] = NULL;
		if (forks[i] == NULL)
		{
			if (i > 0)
				free_forks(forks);
			return (NULL);
		}
		if (pthread_mutex_init(&forks[i]->fork, NULL) != 0)
		{
			free_and_destroy(forks, i - 1);
			return (NULL);
		}
	}
	return (forks);
}

t_philo	**create_philo(t_data *data, t_fork **forks)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * (data->nbr_of_philo + 1));
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < data->nbr_of_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i + 1] = NULL;
		if (philo[i] == NULL
			|| put_data_in_philo(philo[i], data, forks, i) == 1)
		{
			free_philo(philo);
			return (NULL);
		}
		i++;
	}
	return (philo);
}

static int	put_data_in_philo(t_philo *philo,
							t_data *data, t_fork **forks, int i)
{
	t_time	*time;

	if (philo == NULL)
		return (1);
	time = malloc(sizeof(t_time));
	if (time == NULL)
		return (1);
	philo->time = time;
	philo->spot = i + 1;
	philo->nbr_of_eat = 0;
	philo->data = data;
	pthread_mutex_init(&philo->nbr_eat, NULL);
	if (i % 2 == 0)
		philo->status = EAT;
	else
		philo->status = SLEEP;
	distribute_forks(philo, forks, i);
	return (0);
}

static void	distribute_forks(t_philo *philo, t_fork **forks, int i)
{
	if (i == 0)
	{
		philo->fork_r = last_fork(forks);
		philo->fork_l = forks[0];
		if (philo->data->nbr_of_philo == 1)
			philo->fork_l = NULL;
	}
	else
	{
		philo->fork_r = forks[i - 1];
		philo->fork_l = forks[i];
	}
}

static t_fork	*last_fork(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		if (forks[i + 1] == NULL)
			return (forks[i]);
		i++;
	}
	return (forks[i]);
}
