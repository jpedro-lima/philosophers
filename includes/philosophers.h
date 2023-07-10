/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:54:46 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 18:49:40 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>	// malloc() free()
# include <unistd.h>	// usleep()
# include <sys/time.h>	// gettimeofday()
# include <pthread.h>	// thread functions()
# include "error_messages.h"

# define FT_INT_MAX		2147483647

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct s_data
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				meal_limit;
	int				end_of_dinner;
	long long int	start_time;
	pthread_mutex_t	print_log;
	pthread_mutex_t	end_dinner;
	pthread_mutex_t	meal;
}	t_data;

typedef struct s_philosopher
{
	int						id;
	int						meal_counter;
	long long int			last_meal;
	t_data					*data;
	pthread_mutex_t			fork;
	struct s_philosopher	*next;
}	t_philo;

//utils.c
int				put_error_message(char *msg);
void			print_log(t_philo *philo, char *action);

//data.c
int				init_data(t_data *data, char **argv);
void			free_data(t_data *data);

//simulator.c
int				simulator(t_philo **philo, t_data *data);
void			end_simulation(t_data *data);

//time.c
int				msleep(long long int time_in_ms);
long long int	current_time(void);
long long int	get_delta_time(long long int start);

//checkers.c
int				check_arguments(int argc, char **argv);

//linked_list.c
int				make_philosophers_list(t_philo **philo, t_data *data);
void			free_philosopher_list(t_philo **philo);

//actions.c
void			hold_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
void			eat(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);

//t_libft.c
long			ft_atol(const char *str);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

//philosophers_life.c (routine)
void			*philosopher_life(void *arg);
int				end_of_dinner(t_philo *philo);

//dinner_monitor.c (routine)
void			*dinner_monitor(void *arg);
long long int	get_last_meal(t_philo *philo);

#endif //PHILOSOPHERS_H
