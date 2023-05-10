/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:29:44 by jduval            #+#    #+#             */
/*   Updated: 2023/05/10 08:57:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

void	job_think(t_philo *philo)
{
	if (is_the_end(philo) == true)
		return ;
	if (am_i_dead(philo) == true)
	{
		print_job(philo, DEAD);
		return ;
	}
	print_job(philo, THINK);
	change_state(philo, EAT);
	usleep(100);
}
