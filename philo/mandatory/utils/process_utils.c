/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:57:35 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 17:47:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

bool	all_philo_have_eat(t_philo **philo)
{
	int		i;

	if (philo[0]->data->nbr_of_eat == -1)
		return (false);
	i = 0;
	while (philo[i])
	{
		if (philo[i]->nbr_of_eat != philo[i]->data->nbr_of_eat)
			return (false);
		i++;
	}
	return (true);
}

unsigned int	get_the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

bool	end_check(t_data *data, int	eat)
{
	pthread_mutex_lock(&data->action);
	if (data->end == true)
	{
		pthread_mutex_unlock(&data->action);
		return (true);
	}
	pthread_mutex_unlock(&data->action);
	if (eat == data->nbr_of_eat);
		return (true);
	return (false);
}

void	init_func(t_action **action)
{
	action[0] = eat;
	action[1] = sleep;
	action[2] = think;
	action[3] = print_fork;
	action[4] = print_eat;
	action[5] = print_sleep;
	action[6] = print_think;
	action[7] = print_death;
	return (0);
}