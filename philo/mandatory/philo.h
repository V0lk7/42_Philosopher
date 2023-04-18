/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:36:48 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 17:50:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "enum.h"

int				ft_atoi(const char *nptr);
//----------create_database.c----------//
bool			create_database(t_data *data, int argc, char **argv);
//----------parse_user_input.c----------//
bool			parse_user_input(int argc, char **argv);
//----------parsing_utils.c----------//
bool			check_overflow(const char *str);
bool			ft_isspace(int c);
bool			ft_isdigit(int c);
int				ft_atoi(const char *nptr);
//----------create_data_struct.c----------//
t_fork			**create_forks(t_data data);
t_philo			**create_philo(t_data *data, t_fork **forks);
//----------clear_data.c----------//
void			free_philo(t_philo **philo);
void			free_forks(t_fork **forks);
void			free_all(t_fork **forks, t_philo **philo);
//----------error_philosophers.c----------//
void			error_create_philo(t_fork **forks);
//----------process_utils.c----------//
bool			all_philo_have_eat(t_philo **philo);
unsigned int	get_the_time(void);
bool			end_check(t_data *data, int eat);
void			init_func(t_action **action);
//----------process.c----------//
#endif
