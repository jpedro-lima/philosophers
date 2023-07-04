/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:14:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 18:12:54 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"	

void	free_data(t_data *data)
{
	pthread_mutex_destroy(&(data->print_log));
	pthread_mutex_destroy(&(data->end_dinner));
	pthread_mutex_destroy(&(data->meal));
}

int	init_data(t_data *data, char **argv)
{
	data->number_philo = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->meal_limit = -1;
	if (argv[5])
		data->meal_limit = ft_atol(argv[5]);
	data->time_think = 1 + data->time_eat - data->time_sleep;
	data->end_of_dinner = FALSE;
	data->start_time = 0;
	if (pthread_mutex_init(&(data->print_log), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&(data->end_dinner), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&(data->meal), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	return (TRUE);
}
