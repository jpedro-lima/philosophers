/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:54:49 by joapedr2          #+#    #+#             */
/*   Updated: 2023/06/30 22:15:48 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERR_ARG_NUM	"Wrong number of arguments. \
\nTry: ./philo 2 800 200 200 5"

# define ERR_EACH_EAT	"Number of times each philosopher \
should eat must be greater than zero."

# define ERR_ARG_DIGIT	"All arguments must be numeric."
# define ERR_ARG_RANGE	"Argument with value out of range."
# define ERR_ARG_PHILO	"No philosophers for dinner."

# define ERR_MUTEX_INIT	"Error starting mutex"
# define ERR_MALLOC		"Error allocating memory"

#endif //ERROR_MESSAGES_H