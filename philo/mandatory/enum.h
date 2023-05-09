/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:20:16 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 17:38:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
typedef void			t_action(t_philo *philo);

typedef enum e_status
{
	EAT,
	SLEEP,
	THINK,
	DEAD,
	FORK,
	END
}	t_status;

typedef struct s_fork
{
	pthread_mutex_t	fork;	
	bool			lock;
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
	t_action		*func[4];
	pthread_mutex_t	print;
	bool			lock;
}	t_data;

typedef struct s_philo
{
	int				spot;
	int				nbr_of_eat;
	t_status		status;
	bool			print;
	t_fork			*fork_r;
	bool			fork_right;
	t_fork			*fork_l;
	bool			fork_left;
	t_time			time;
	t_data			*data;
	pthread_t		id;
	pthread_mutex_t	nbr_eat;
	pthread_mutex_t	v_status;
}	t_philo;

#endif
