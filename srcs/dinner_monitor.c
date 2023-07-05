/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:59:48 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 22:12:20 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long int	get_last_meal(t_philo *philo)
{
	long long int	last_meal;

	pthread_mutex_lock(&(philo->data->meal));
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&(philo->data->meal));
	return (last_meal);
}

static int	meal_limit_reached(t_philo *philo)
{
	t_philo	*aux;
	int		i;

	aux = philo;
	i = philo->data->number_philo;
	if (philo->data->meal_limit <= 0)
		return (FALSE);
	while (i--)
	{
		if (aux->meal_counter < philo->data->meal_limit)
			return (FALSE);
		aux = aux->next;
	}
	return (TRUE);
}

void	*dinner_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!end_of_dinner(philo))
	{
		if (get_delta_time(philo->data->start_time)
			- get_last_meal(philo) > philo->data->time_die)
		{
			end_simulation(philo->data);
			print_log(philo, "died");
		}
		if (meal_limit_reached(philo))
			end_simulation(philo->data);
		if (philo->next)
			philo = philo->next;
	}
	return (NULL);
}
