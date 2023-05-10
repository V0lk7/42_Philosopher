/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:10:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 08:57:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	print_job(t_philo *philo, t_status status)
{
	if (is_the_end(philo) == true)
		return ;
	pthread_mutex_lock(&philo->data->print);
	philo->time.job = get_time(philo->time.zero);
	if (status == FORK)
		printf("%li %i has taken a fork\n", philo->time.job, philo->spot);
	else if (status == EAT)
		printf("%li %i is eating\n", philo->time.job, philo->spot);
	else if (status == SLEEP)
		printf("%li %i is sleeping\n", philo->time.job, philo->spot);
	else if (status == THINK)
		printf("%li %i is thinking\n", philo->time.job, philo->spot);
	else if (status == DEAD)
		printf("%li %i died\n", philo->time.job, philo->spot);
	pthread_mutex_unlock(&philo->data->print);
}
