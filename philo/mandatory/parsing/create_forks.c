/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:00:20 by jduval            #+#    #+#             */
/*   Updated: 2023/04/07 23:25:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	**create_forks(t_data data)
{
	t_fork	**forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_fork *) * (data.nbr_of_philo + 1));
	if (forks == NULL)
		return (NULL);
	while (i < data.nbr_of_philo)
	{
		forks[i] = malloc(sizeof(t_fork));
		if (forks[i] == NULL)
			return (NULL);
		i++;
	}
	forks[i] = NULL;
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
		if (philo[i] == NULL)
		{
			if (i > 0)
				free_philo(philo);
			return (NULL);
		}
		//rmplir les données dans philo... aled
		i++;
	}
	return (philo);
	
}
