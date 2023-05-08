/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:20:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/08 11:44:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
typedef void			t_action(t_philo *philo);

typedef enum e_print
{
	PRINT_EAT = 4,
	PRINT_SLEEP = 5,
	PRINT_THINK = 6,
	PRINT_DEATH = 7,
	PRINT_FORK = 8
}	t_plus;

typedef enum e_status
{
	EAT,
	SLEEP,
	THINK,
	DEAD,
	END = 9
}	t_status;

typedef struct s_fork
{
	pthread_mutex_t	fork;	
}	t_fork;

typedef struct s_time
{
	long			zero;
	long			death;
	long			job;
	pthread_mutex_t	v_death;	
}	t_time;

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				nbr_of_eat;
	t_action		*func[9];
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				spot;
	int				nbr_of_eat;
	t_status		status;
	t_fork			*fork_r;
	t_fork			*fork_l;
	t_time			time;
	t_data			*data;
	pthread_t		id;
	pthread_mutex_t	nbr_eat;
	pthread_mutex_t	v_status;
}	t_philo;

#endif
