/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:36:48 by jduval            #+#    #+#             */
/*   Updated: 2023/05/05 16:16:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "enum.h"

//----------create_database.c----------//
bool		create_database(t_data *data, int argc, char **argv);
//----------parse_user_input.c----------//
bool		parse_user_input(int argc, char **argv);
//----------parsing_utils.c----------//
bool		check_overflow(const char *str);
bool		ft_isspace(int c);
bool		ft_isdigit(int c);
int			ft_atoi(const char *nptr);
//----------create_data_struct.c----------//
t_fork		**create_forks(t_data data);
t_philo		**create_philo(t_data *data, t_fork **forks);
//----------clear_data.c----------//
void		free_philo(t_philo **philo);
void		free_forks(t_fork **forks);
void		free_destroy_all(t_fork **forks, t_philo **philo, t_data *data);
//----------init_mutex.c----------//
bool		init_all_mutex(t_philo **philo, t_fork **forks, t_data *data);
bool		init_mutex_data(t_data *data);
bool		init_mutex_forks(t_fork **forks);
bool		init_mutex_philo(t_philo **philo);
void		init_func(t_action **action);
//----------destroy_mutex.c----------//
void		destroy_all_mutex(t_data *data, t_philo **philo, t_fork **forks);
void		destroy_mutex_time(t_philo **philo, int i);
void		destroy_mutex_forks(t_fork **forks, int i);
void		destroy_mutex_philo(t_philo **philo, int i);
void		destroy_mutex_verif(t_philo **philo, int i);
//----------process_utils.c----------//
long		get_time(long zero);
void		make_end(t_philo **philo);
void		change_state(t_philo *philo, t_status state);
//----------verif.c.c----------//
bool		all_philo_have_eat(t_philo **philo);
bool		am_i_dead(t_philo *philo);
bool		is_he_dead(t_philo **philo);
bool		is_the_end(t_philo *philo);
bool		did_i_eat_all(t_philo *philo);
//----------print.c----------//
void		print_fork(t_philo *philo);
void		print_eat(t_philo *philo);
void		print_sleep(t_philo *philo);
void		print_think(t_philo *philo);
void		print_death(t_philo *philo);
//----------eat.c----------//
void		job_eat(t_philo *philo);
void		job_sleep(t_philo *philo);
void		job_think(t_philo *philo);
void		job_dead(t_philo *philo);
//----------error_pthread.c----------//
void		create_pthread_error(t_philo **philo, int index);
void		free_and_destroy(t_fork **forks, int index);
#endif
