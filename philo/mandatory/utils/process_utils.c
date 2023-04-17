/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:57:35 by jduval            #+#    #+#             */
/*   Updated: 2023/04/17 18:04:32 by jduval           ###   ########.fr       */
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

long	get_the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}
