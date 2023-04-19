/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:29:44 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 17:29:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

void	job_think(t_philo *philo)
{
	philo->time->job = get_the_time(philo->time->zero);
	if (philo->time->job >= philo->time->death)
	{
		death(philo);
		return ;
	}
	philo->data->func[THINK + PRINT](philo);
	philo->status = EAT;
}
