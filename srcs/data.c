/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:14:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 23:25:03 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"	

void	free_data(t_data *data)
{
	pthread_mutex_destroy(&(data->monitor));
	pthread_mutex_destroy(&(data->print_log));
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
	data->end_of_dinner = FALSE;
	data->start_time = 0;
	if (pthread_mutex_init(&(data->monitor), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	if (pthread_mutex_init(&(data->print_log), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	return (TRUE);
}
