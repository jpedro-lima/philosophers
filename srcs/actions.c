/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:47:21 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 18:54:08 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
}

void	hold_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	print_log(philo, "has taken a fork");
	if(!philo->next)
	{
		msleep(philo->data->time_die);
		return ;
	}	
	pthread_mutex_lock(&(philo->next->fork));
	print_log(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	print_log(philo, "is eating");
	msleep(philo->data->time_eat);
	pthread_mutex_lock(&(philo->data->meal));
	philo->meal_counter++;
	philo->last_meal = get_delta_time(philo->data->start_time);
	pthread_mutex_unlock(&(philo->data->meal));
}

void	sleeping(t_philo *philo)
{
	print_log(philo, "is sleeping");
	msleep(philo->data->time_sleep);
}

void	thinking(t_philo *philo)
{
	print_log(philo, "is thinking");
	msleep(philo->data->time_think);
}
