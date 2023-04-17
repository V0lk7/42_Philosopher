/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:00:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/17 18:05:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

static void	display_data(t_data data, t_philo **philo);
static void	*routine_philo(void *variable);
static void start_philo(t_philo **philo);
static void	running_philosophers(t_data *data, t_philo **philo);

int	main(int argc, char **argv)
{
	t_data	data;
	t_fork	**forks;
	t_philo	**philo;

	if (parse_user_input(argc, argv) == false
		|| create_database(&data, argc, argv) == false)
		return (0);
	forks = create_forks(data);
	if (forks == NULL)
		return (1);
	philo = create_philo(&data, forks);
	if (philo == NULL)
		error_create_philo(forks);
	display_data(data, philo);
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
	int				i;
	long			time_philo;

	i = 0;
	time_philo = get_the_time();
	while (philo[i])
	{
		philo[i]->time = time_philo;
		pthread_create(&philo[i]->id, NULL, &routine_philo, NULL);
		i++;
	}
	return ;
}

static void	*routine_philo(void *variable)
{
	(void)variable;
	usleep(1000000);
	return (0);
}

static void	display_data(t_data data, t_philo **philo)
{
	int	i;

	i = 0;
	printf("nbr of philo = %i\n", data.nbr_of_philo);
	printf("time_to_die = %i\n", data.time_to_die);
	printf("time_of_eat = %i\n", data.time_of_eat);
	printf("time_of_sleep = %i\n", data.time_of_sleep);
	printf("nbr_of_eat = %i\n", data.nbr_of_eat);
	while (philo[i])
	{
		printf("#####################\n");
		printf("philo id = %d\n", philo[i]->spot);
		printf("philo status = ");
		if (philo[i]->status == 0)
			printf("EAT\n");
		else if (philo[i]->status == 1)
			printf("SLEEP\n");
		else if (philo[i]->status == 2)
			printf("THINK\n");
		printf("left fork = %i\n", philo[i]->fork_l->i);
		printf("right fork = %i\n", philo[i]->fork_r->i);
		i++;
	}
}
