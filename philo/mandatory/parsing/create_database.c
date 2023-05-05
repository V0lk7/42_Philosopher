/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_database.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:15:41 by jduval            #+#    #+#             */
/*   Updated: 2023/05/05 13:37:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdio.h>

static bool	database_check(t_data data, char **argv, int flag);
static bool	database_check_part_one(t_data data, char **argv);
static bool	database_check_part_two(t_data data, char **argv);
static void	error_data(int type, char *str);

bool	create_database(t_data *data, int argc, char **argv)
{
	bool	flag;
	int		option;

	flag = true;
	option = 0;
	data->nbr_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_of_eat = ft_atoi(argv[3]);
	data->time_of_sleep = ft_atoi(argv[4]);
	init_func(data->func);
	if (argc == 6)
	{
		data->nbr_of_eat = ft_atoi(argv[5]);
		option = 1;
	}
	else
		data->nbr_of_eat = -1;
	flag = database_check(*data, argv, option);
	return (flag);
}

static bool	database_check(t_data data, char **argv, int option)
{
	bool	flag;

	flag = true;
	if (database_check_part_one(data, argv) == false)
		flag = false;
	if (database_check_part_two(data, argv) == false)
		flag = false;
	if (option == 1 && data.nbr_of_eat <= 0)
	{
		if (data.nbr_of_eat == 0 && check_overflow(argv[5]) == true)
			error_data(1, "number of eating");
		else if (data.nbr_of_eat == 0 && check_overflow(argv[5]) == false)
			error_data(2, "nbr of eating");
		else
			error_data(3, "nbr of eating");
		flag = false;
	}
	return (flag);
}

static bool	database_check_part_one(t_data data, char **argv)
{
	bool	flag;

	flag = true;
	if (data.nbr_of_philo <= 0)
	{
		if (data.nbr_of_philo == 0 && check_overflow(argv[1]) == true)
			error_data(1, "number of philosophers");
		else if (data.nbr_of_philo == 0 && check_overflow(argv[1]) == true)
			error_data(2, "number of philosophers");
		else
			error_data(3, "number of philosophers");
		flag = false;
	}
	if (data.time_to_die <= 0)
	{
		if (data.time_to_die == 0 && check_overflow(argv[2]) == true)
			error_data(1, "time to die");
		else if (data.time_to_die == 0 && check_overflow(argv[2]) == false)
			error_data(2, "time to die");
		else
			error_data(3, "time to die");
		flag = false;
	}
	return (flag);
}

static bool	database_check_part_two(t_data data, char **argv)
{
	bool	flag;

	flag = true;
	if (data.time_of_eat <= 0)
	{
		if (data.time_of_eat == 0 && check_overflow(argv[3]) == true)
			error_data(1, "time of eat");
		else if (data.time_of_eat == 0 && check_overflow(argv[3]) == false)
			error_data(2, "time of eat");
		else
			error_data(3, "time of eat");
		flag = false;
	}
	if (data.time_of_sleep <= 0)
	{
		if (data.time_of_sleep == 0 && check_overflow(argv[4]) == true)
			error_data(1, "time of sleep");
		else if (data.time_of_sleep == 0 && check_overflow(argv[4]) == false)
			error_data(2, "time of sleep");
		else
			error_data(3, "time of sleep");
		flag = false;
	}
	return (flag);
}

static void	error_data(int type, char *str)
{
	if (type == 1)
		printf("error:%s: value overflow, try with value < 2147483648\n", str);
	else if (type == 2)
		printf("error:%s: value can't be 0, try with value > 0\n", str);
	else
		printf("error:%s: value can't be under 0, try positive one\n", str);
	return ;
}
