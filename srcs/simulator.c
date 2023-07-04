/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:28:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 19:39:57 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end_simulation(t_data *data)
{
	pthread_mutex_lock(&(data->end_dinner));
	data->end_of_dinner = TRUE;
	pthread_mutex_unlock(&(data->end_dinner));
}

static int	create_threads(pthread_t *thread, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->number_philo)
	{
		if (pthread_create(&thread[i], NULL, &philosopher_life, (*philo)))
			return (free(thread), put_error_message(ERR_THREAD_CREATE));
		if ((*philo)->next)
			(*philo) = (*philo)->next;
	}
	return (TRUE);
}

static int	join_threads(pthread_t *thread, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->number_philo)
	{
		if (pthread_join(thread[i], NULL))
			return (put_error_message(ERR_THREAD_JOIN));
	}
	return (TRUE);
}

int	simulator(t_philo **philo, t_data *data)
{
	pthread_t	*thread;
	pthread_t	monitor;

	data->start_time = current_time();
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (!thread)
		return (put_error_message(ERR_MALLOC));
	if (!create_threads(thread, philo))
		return (FALSE);
	if (pthread_create(&monitor, NULL, &dinner_monitor, *philo))
		return (free(thread), put_error_message(ERR_THREAD_CREATE));
	if (!join_threads(thread, philo))
		return (FALSE);
	if (pthread_join(monitor, NULL))
		return (free(thread), put_error_message(ERR_THREAD_JOIN));
	free(thread);
	return (TRUE);
}
