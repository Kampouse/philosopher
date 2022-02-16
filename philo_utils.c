/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:52:41 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/15 21:53:27 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	current_time(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return ((te.tv_sec * 1000) + (te.tv_usec / 1000));
}

void	sleep_time(int lenght)
{
	const long	time = current_time();

	while (current_time() < time + lenght)
	{
		usleep(current_time() - time + lenght);
	}
}
