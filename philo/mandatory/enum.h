/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:20:16 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 17:50:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

# include <stdbool.h>
# include <pthread.h>

typedef void	t_action(t_status obj);

typedef enum e_status
{
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_status;

typedef struct s_fork
{
	int				i;
	pthread_mutex_t	fork;	
}	t_fork;

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				nbr_of_eat;
	bool			end;
	pthread_mutex_t	print;
}	t_data;

typedef struct s_philo
{
	int				spot;
	pthread_t		id;
	t_status		status;
	unsigned int	time_of_death;
	int				nbr_of_eat;
	t_fork			*fork_r;
	t_fork			*fork_l;
	t_data			*data;
}	t_philo;


#endif
