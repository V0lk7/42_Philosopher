/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:43:36 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 10:53:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death(t_philo *philo)
{
	philo->time_job = philo->time_of_death;
	philo->data->func[DEAD + PRINT](philo);
	pthread_mutex_lock(&philo->data->end_mutex);
	philo->data->end = true;
	pthread_mutex_unlock(&philo->data->end_mutex);
	philo->status = DEAD;
}
