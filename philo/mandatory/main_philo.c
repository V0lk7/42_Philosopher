/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:00:38 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:00:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine_philo(void *variable);
static bool	start_philo(t_philo **philo);
static void	running_philosophers(t_philo **philo);

int	main(int argc, char **argv)
{
	t_data		data;
	t_fork		**forks;
	t_philo		**philo;

	if (parse_user_input(argc, argv) == false
		|| create_database(&data, argc, argv) == false)
		return (1);
	forks = create_forks(data);
	if (forks == NULL)
		return (1);
	philo = create_philo(&data, forks);
	if (philo == NULL)
	{
		free_forks(forks);
		return (1);
	}
	if (init_all_mutex(philo, forks, &data) == false)
		return (1);
	running_philosophers(philo);
	free_destroy_all(forks, philo, &data);
	return (0);
}

static void	running_philosophers(t_philo **philo)
{
	int	i;

	i = 0;
	if (start_philo(philo) == false)
		return ;
	while (1)
	{
		if (is_he_dead(philo) == true)
			break ;
		if (all_philo_have_eat(philo) == true)
			break ;
	}
	while (philo[i] != NULL)
	{
		pthread_join(philo[i]->id, NULL);
		i++;
	}
	return ;
}

static bool	start_philo(t_philo **philo)
{
	int			i;
	long		time_philo;

	i = 0;
	time_philo = get_time(0);
	while (philo[i])
	{
		philo[i]->time.zero = time_philo;
		philo[i]->time.death = philo[i]->data->time_to_die;
		if (pthread_create(&philo[i]->id, NULL, &routine_philo, philo[i]) != 0)
		{
			create_pthread_error(philo, i - 1);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	*routine_philo(void *philo_base)
{
	t_philo		*philo;
	t_status	tmp;

	philo = philo_base;
	while (1)
	{
		pthread_mutex_lock(&philo->v_status);
		tmp = philo->status;
		pthread_mutex_unlock(&philo->v_status);
		philo->data->func[tmp](philo);
		if (am_i_dead(philo) == true)
			break ;
		if (is_the_end(philo) == true)
			break ;
		if (did_i_eat_all(philo) == true)
			break ;
	}
	return (0);
}
