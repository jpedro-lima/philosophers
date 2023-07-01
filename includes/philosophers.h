/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:54:46 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 23:24:40 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>	// malloc()
# include <unistd.h>	// write()
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
	int				meal_limit;
	int				end_of_dinner;
	long long int	start_time;
	pthread_mutex_t	print_log;
	pthread_mutex_t	monitor;
}	t_data;

typedef struct s_philosopher
{
	int						id;
	int						meal_counter;
	long long int			last_eat;
	t_data					*data;
	pthread_mutex_t			fork;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philo;

//utils.c
int		put_error_message(char *msg);
void	free_data(t_data *data);

//data.c
int		init_data(t_data *data, char **argv);

//checkers.c
int		check_arguments(int argc, char **argv);

//linked_list.c
int		make_philosophers_list(t_philo **philo, t_data *data);
void	free_philosopher_list(t_philo **philo);

//t_libft.c
long	ft_atol(const char *str);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

#endif //PHILOSOPHERS_H
