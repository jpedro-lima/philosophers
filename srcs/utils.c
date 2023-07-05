/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:00:13 by joapedr2          #+#    #+#             */
/*   Updated: 2023/07/04 22:13:29 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, char *action)
{
	if (end_of_dinner(philo) && ft_strncmp(action, "died", 4))
		return ;
	pthread_mutex_lock(&(philo->data->print_log));
	printf("%lld ", get_delta_time(philo->data->start_time));
	printf("%d ", philo->id);
	printf("%s", action);
	printf("\n");
	pthread_mutex_unlock(&(philo->data->print_log));
}

int	put_error_message(char *msg)
{
	printf("%s", msg);
	printf("\n");
	return (FALSE);
}
