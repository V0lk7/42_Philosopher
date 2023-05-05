/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:29:44 by jduval            #+#    #+#             */
/*   Updated: 2023/05/05 17:44:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	job_think(t_philo *philo)
{
	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	philo->data->func[PRINT_THINK](philo);
	change_state(philo, EAT);
}
