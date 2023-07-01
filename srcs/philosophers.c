/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:55:26 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 23:28:27 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (check_arguments(argc, argv))
	{
		if (!init_data(&data, argv))
			return (-42);
		if (!make_philosophers_list(&philo, &data))
			return (-42);
		if (!simulator(&philo))
			return (-42);
	}
	return (0);
}
