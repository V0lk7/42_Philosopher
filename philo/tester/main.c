/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:50:29 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 17:38:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

static long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

static void	*routine(void *lol)
{
	return (0);
}

int	main(int argc, char **argv)
{
	int		nbr;
	int		i = 0;
	long	average[1000];
	long	time1;
	long	time2;
	pthread_t	*id;

	if (argc != 2)
		return (1);
	nbr = atoi(argv[1]);
	if (nbr <= 0)
		return (1);
	for (int i = 0; i < 1000; i++)
	{
		id = malloc(sizeof(pthread_t) * nbr);
		id[nbr] = 0;
		time1 = get_time();
		for (int a = 0; a < nbr; a++)
			pthread_create(&id[a], NULL, &routine, NULL);
		time2 = get_time();
		average[i] = time2 - time1;
		for (int a = 0; a < nbr; a++)
			pthread_join(id[a], NULL);
		free(id);
	}
	long count = 0;
	for (int i = 0; i < 1000; i++)
		count += average[i];
	count = count / 1000;
	printf("La moyenne est de %li\n", count);
	return (0);
}
