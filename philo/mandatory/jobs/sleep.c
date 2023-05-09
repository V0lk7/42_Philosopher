/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:12:36 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:01:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

void	job_sleep(t_philo *philo)
{
	long	time;

	time = get_time(philo->time.zero) + philo->data->time_of_sleep;
	print_job(philo, SLEEP);
	while (get_time(philo->time.zero) < time)
	{
		if (am_i_dead(philo) == true)
		{
			print_job(philo, DEAD);
			return ;
		}
		if (is_the_end(philo) == true)
			return ;
	}
	change_state(philo, THINK);
}
