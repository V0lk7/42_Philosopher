/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:00:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/06 17:55:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
//	t_fork	**forks;
//	t_philo	**philo;

	if (parse_user_input(argc, argv) == false
		|| create_database(&data, argc, argv) == false)
		return (0);
/*
	forks = create_forks(data);
	if (forks == NULL)
		error_forks();
	philo = create_philo(&data, forks);
	if (philo == NULL)
		error_philo(forks);
	free_all(forks, philo);*/
	return (0);
}
