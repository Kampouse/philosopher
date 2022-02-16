/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:29:22 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 15:44:23 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	phil_looping(t_philo *phil, t_state *state, int start)
{
	while (state->is_alive)
	{
		print_protected(state,
			"is thinking", phil->nbr, current_time() - start);
		pthread_mutex_lock(&state->forks[phil->lfork]);
		print_protected(state,
			"has taken a fork", phil->nbr, current_time() - start);
		pthread_mutex_lock(&state->forks[phil->rfork]);
		print_protected(state,
			"has  taken a fork", phil->nbr, current_time() - start);
		sleep_time(phil->time_to_eat);
		pthread_mutex_unlock(&state->forks[phil->lfork]);
		print_protected(state,
			"drop a fork", phil->nbr, current_time() - start);
		pthread_mutex_unlock(&state->forks[phil->rfork]);
		print_protected(state,
			"drop a fork", phil->nbr, current_time() - start);
		state->philo[phil->nbr
		]->time_to_take_eat = current_time() + phil->death_time;
		state->philo[phil->nbr]->ate++;
		sleep_time(phil->time_to_sleep);
		print_protected(state,
			"is sleeping", phil->nbr, current_time() - start);
	}
	return (0);
}

void	*philo_loop(void *philo)
{
	t_philo		*phil;
	t_state		*state;
	int			start;

	phil = philo;
	state = phil->states;
	start = current_time();
	phil->start = start;
	phil->time_to_take_eat = start + phil->death_time;
	if (phil->nbr % 2 == 0)
	{
		usleep(16000);
	}
	phil_looping(phil, state, start);
	pthread_detach(state->thread[phil->nbr]);
	return (0);
}
