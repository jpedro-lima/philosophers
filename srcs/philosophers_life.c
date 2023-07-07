/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_life.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:59:35 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/06 12:13:30 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	end_of_dinner(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->data->end_dinner);
	result = philo->data->end_of_dinner;
	pthread_mutex_unlock(&philo->data->end_dinner);
	return (result);
}
int		one_philo(t_philo *philo)
{
	if (philo->next)
		return (FALSE);
	pthread_mutex_lock(&(philo->fork));
	print_log(philo, "has taken a fork");
	msleep(philo->data->time_die);
	return (TRUE);
}

void	*philosopher_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (one_philo(philo))
		return (NULL);
	while (!end_of_dinner(philo))
	{
		hold_forks(philo);
		if (!philo->next)
			return (NULL);
		eat(philo);
		drop_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
