/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:20:16 by jduval            #+#    #+#             */
/*   Updated: 2023/04/27 11:24:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
typedef void			t_action(t_philo *philo);

typedef enum e_plus
{
	PRINT = 3,
	FORK = 7
}	t_plus;

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

typedef struct s_time
{
	long	zero;
	long	death;
	long	job;
}	t_time;

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				nbr_of_eat;
	bool			end;
	t_action		**func;
	pthread_mutex_t	print;
	pthread_mutex_t	end_mutex;
}	t_data;

typedef struct s_philo
{
	int				spot;
	int				nbr_of_eat;
	pthread_mutex_t	nbr_eat;
	t_status		status;
	pthread_t		id;
	t_fork			*fork_r;
	t_fork			*fork_l;
	t_time			*time;
	t_data			*data;
}	t_philo;

#endif
