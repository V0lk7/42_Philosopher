/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:36:48 by jduval            #+#    #+#             */
/*   Updated: 2023/04/06 18:21:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

typedef enum e_status
{
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_status;

typedef struct s_fork
{
	pthread_mutex_t	fork;	
}	t_fork;

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				nbr_of_eat;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int			spot;
	pthread_t	id;
	long		time;
	t_status	status;
	t_fork		*fork_r;
	t_fork		*fork_l;
	t_data		*data;
}	t_philo;

int		ft_atoi(const char *nptr);
//----------create_database.c----------//
bool	create_database(t_data *data, int argc, char **argv);
//----------parse_user_input.c----------//
bool	parse_user_input(int argc, char **argv);
//----------parsing_utils.c----------//
bool	check_overflow(const char *str);
bool	ft_isspace(int c);
bool	ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif
