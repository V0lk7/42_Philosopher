/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:43:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/06 18:12:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../philo.h"

static void	bad_number_of_args(void);
static bool	parse_by_arg(const char *arg);

bool	parse_user_input(int argc, char **argv)
{
	int		i;
	bool	flag;

	flag = true;
	i = 1;
	if (!(argc >= 5 && argc <= 6))
	{
		bad_number_of_args();
		return (false);
	}
	while (argv[i])
	{
		if (parse_by_arg(argv[i]) == false)
		{
			printf("arg %i\n%s :bad syntax\n", i, argv[i]);
			flag = false;
		}
		i++;
	}
	return (flag);
}

static bool	parse_by_arg(const char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (false);
	while (arg[i] && ft_isspace(arg[i]) == true)
		i++;
	if (arg[i] && (arg[i] == '+' || arg[i] == '-'))
		i++;
	while (arg[i] && ft_isdigit(arg[i]) == true)
		i++;
	if (arg[i] != '\0' || (arg[i] == '\0' && ft_isdigit(arg[i - 1]) == false))
		return (false);
	return (true);
}

static void	bad_number_of_args(void)
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
