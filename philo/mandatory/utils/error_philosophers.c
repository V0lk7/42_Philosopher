/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:17:04 by jduval            #+#    #+#             */
/*   Updated: 2023/04/27 11:23:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

void	error_create_philo(t_fork **forks)
{
	free_forks(forks);
	printf("Error of malloc during philo creation\n");
	return ;
}
