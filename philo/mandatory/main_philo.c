/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:00:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/02 20:08:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_args(void)
{
	printf("Bad arguments ! ");
	printf("Pathern needed : \n");
	printf("./philo\n");
	printf("[number_of_philosophers]\n");
	printf("[time_to_die(in ms)]\n");
	printf("[time_to_eat(in ms)]\n");
	printf("[time_to_sleep(in ms)]\n");
	printf("[number_of_time_each_philosopher_must_eat] (optional)\n");
}

int	main(int argc, char **argv)
{
	if (!(argc >= 5 && argc <= 6))
		error_args();
	return (0);
}
