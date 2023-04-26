/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:43:36 by jduval            #+#    #+#             */
/*   Updated: 2023/04/26 16:57:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death(t_philo *philo)
{
	if (end_check(philo->data, philo) == true)
		return ;
	philo->time->job = philo->time->death;
	philo->status = DEAD;
	pthread_mutex_lock(&philo->data->end_mutex);
	if (philo->data->end == true)
	{
		pthread_mutex_unlock(&philo->data->end_mutex);
		return ;
	}
	philo->data->end = true;
	pthread_mutex_unlock(&philo->data->end_mutex);
	philo->data->func[DEAD + PRINT](philo);
}
