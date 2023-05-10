/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:04:14 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 16:03:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>

long	get_time(long zero)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000) - zero);
}

void	make_end(t_philo **philo)
{
	int		i;

	i = 0;
	while (philo[i])
	{
		pthread_mutex_lock(&philo[i]->v_status);
		if (philo[i]->status < DEAD)
			philo[i]->status = END;
		pthread_mutex_unlock(&philo[i]->v_status);
		i++;
	}
}

void	change_state(t_philo *philo, t_status state)
{
	if (am_i_dead(philo) == true || is_the_end(philo) == true)
		return ;
	pthread_mutex_lock(&philo->v_status);
	philo->status = state;
	pthread_mutex_unlock(&philo->v_status);
}
