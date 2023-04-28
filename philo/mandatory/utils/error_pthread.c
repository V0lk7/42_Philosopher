/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:24 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 10:51:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_pthread_error(t_philo **philo, int index)
{
	if (index == 0)
		return ;
	pthread_mutex_lock(&philo[index]->data->end_mutex);
	philo[index]->data->end = true;
	pthread_mutex_unlock(&philo[index]->data->end_mutex);
	while (index > 0)
	{
		pthread_join(philo[index]->id, NULL);
		index--;
	}
	return ;
}
