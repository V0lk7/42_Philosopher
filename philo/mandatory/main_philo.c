/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:00:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 11:48:37 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void	*routine_philo(void *variable);
static void start_philo(t_philo **philo);
static void	running_philosophers(t_data *data, t_philo **philo);

int	main(int argc, char **argv)
{
	t_data		data;
	t_fork		**forks;
	t_philo		**philo;

	if (parse_user_input(argc, argv) == false
		|| create_database(&data, argc, argv) == false)
		return (0);
	forks = create_forks(data);
	if (forks == NULL)
		return (1);
	philo = create_philo(&data, forks);
	if (philo == NULL)
		error_create_philo(forks);
	running_philosophers(&data, philo);
	free_all(forks, philo);
	return (0);
}

static void	running_philosophers(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	start_philo(philo);
	while (1)
	{
		if (data->end == true || all_philo_have_eat(philo) == true)
			break ;
	}
	while (philo[i])
	{
		pthread_join(philo[i]->id, NULL);
		i++;
	}
	return ;
}

static void start_philo(t_philo **philo)
{
	int			i;
	long		time_philo;

	i = 0;
	time_philo = get_the_time() + philo[0]->data->time_to_die;
	while (philo[i])
	{
		philo[i]->time_of_death = time_philo;
		pthread_create(&philo[i]->id, NULL, &routine_philo, philo[i]);
		i++;
	}
	return ;
}

static void	*routine_philo(void *philo_base)
{
	t_philo 	*philo;
	t_action	*func[8];
	
	philo = philo_base;
	philo->data->func = func;
	init_func(func);
	while (end_check(philo->data, philo->nbr_of_eat) == false)
		func[philo->status](philo);
	return (0);
}
