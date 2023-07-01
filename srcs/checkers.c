/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:57:39 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 18:22:56 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_digit(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!ft_isdigit(*arg))
		return (FALSE);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

int	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (put_error_message(ERR_ARG_NUM));
	else
	{	
		while (--argc)
		{
			if (!check_digit(argv[argc]))
				return (put_error_message(ERR_ARG_DIGIT));
			if (ft_atol(argv[argc]) > FT_INT_MAX)
				return (put_error_message(ERR_ARG_RANGE));
		}
		if (ft_atol(argv[1]) <= 0)
			return (put_error_message(ERR_ARG_PHILO));
		if (argv[5] && ft_atol(argv[5]) <= 0)
			return (put_error_message(ERR_EACH_EAT));
	}
	return (TRUE);
}
