/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:54:30 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 23:27:49 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	node_swap(t_philo *new, t_philo *last)
{
	new->next = last->next;
	if (last->next)
		last->next->prev = new;
	last->next = new;
	new->prev = last;
}

static int	new_philosopher_node(t_philo **current, t_data *data)
{
	t_philo	*new;
	t_philo	*last;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (put_error_message(ERR_MALLOC));
	new->id = 1;
	new->meal_counter = 0;
	new->last_eat = 0;
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	if (pthread_mutex_init(&(new->fork), NULL) != 0)
		return (put_error_message(ERR_MUTEX_INIT));
	if (*current)
	{
		last = *current;
		while (last->next && last->id < last->next->id)
			last = last->next;
		new->id = last->id + 1;
		node_swap(new, last);
	}
	else
		*current = new;
	return (TRUE);
}

void	free_philosopher_list(t_philo **philo)
{
	t_philo	*aux;

	if (!(*philo))
		return ;
	(*philo)->prev->next = NULL;
	aux = *philo;
	while (aux)
	{
		aux = NULL;
		if ((*philo)->next)
			aux = (*philo)->next;
		aux->prev = NULL;
		pthread_mutex_destroy(&((*philo)->fork));
		free(*philo);
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
