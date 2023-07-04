/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:54:30 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 20:01:24 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	new_philosopher_node(t_philo **current, t_data *data)
{
	t_philo	*new;
	t_philo	*last;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (put_error_message(ERR_MALLOC));
	new->id = 1;
	new->meal_counter = 0;
	new->last_meal = 0;
	new->data = data;
	new->next = NULL;
	if (pthread_mutex_init(&(new->fork), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	if (*current)
	{
		new->next = *current;
		last = *current;
		while (last->next && last->id < last->next->id)
			last = last->next;
		new->id += last->id;
		last->next = new;
	}
	else
		*current = new;
	return (TRUE);
}

void	free_philosopher_list(t_philo **philo)
{
	t_philo	*aux;
	int		size;

	size = (*philo)->data->number_philo;
	while (size--)
	{
		aux = NULL;
		if ((*philo)->next)
			aux = (*philo)->next;
		pthread_mutex_destroy(&((*philo)->fork));
		free((*philo));
		(*philo) = aux;
	}
}

int	make_philosophers_list(t_philo **philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philo)
	{
		if (!new_philosopher_node(philo, data))
		{
			free_philosopher_list(philo);
			free_data(data);
			return (FALSE);
		}
	}
	return (TRUE);
}
