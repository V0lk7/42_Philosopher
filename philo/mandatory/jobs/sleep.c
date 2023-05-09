/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:12:36 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 18:18:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

void	job_sleep(t_philo *philo)
{
	long	time;

	if (am_i_dead(philo) == true)
	{
		print_job(philo, DEAD);
		return ;
	}
	if (is_the_end(philo) == true)
		return ;
	print_job(philo, SLEEP);
	time = get_time(philo->time.zero) + philo->data->time_of_sleep;
	while (get_time(philo->time.zero) < time)
	{
		if (am_i_dead(philo) == true)
		{
			print_job(philo, DEAD);
			return ;
		}
		if (is_the_end(philo) == true)
			return ;
		usleep(100);
	}
	change_state(philo, THINK);
}
