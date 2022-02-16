/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:58:24 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 15:43:47 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_delete(t_philo **philo)
{
	int	inc;

inc = 0;
	while (philo[inc])
	{
		free(philo[inc]);
		inc++;
	}
	free(philo);
}

int	must_eat( t_state *states)
{
	int				inc;
	const int		must_eat = states->philo[0]->must_eat;

	inc = 0;
	if (must_eat != -1)
	{
		while (states->philo[inc])
		{
			if (states->philo[inc]->ate != must_eat)
				break ;
			inc++;
		}
		if (inc == states->philo_count)
			return (0);
	}
	return (1);
}

void	state_delete(t_state *state)
{
	int		inc;

	inc = 0;
	while (inc < state->philo_count)
	{
		pthread_mutex_destroy(&state->forks[inc]);
		inc++;
	}
	pthread_mutex_destroy(&state->print);
	philo_delete(state->philo);
	free(state->forks);
	free(state);
}

int	main_loop(t_state *state, int inc)
{
	while (state->is_alive)
	{
		usleep(10);
		if (inc == state->philo_count)
			inc = 0;
		if (must_eat(state) == 0)
			return (0);
		if (current_time() > (unsigned int) state->philo[inc]->time_to_take_eat)
		{
			print_protected(state, "died", inc,
				state->philo[inc]->time_to_take_eat - state->philo[inc]->start);
				state->is_alive = 0;
			return (0);
		}
		inc++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_state		*state;
	long		sleep_times;
	pthread_t	*thread;	
	int			inc;

	inc = 0;
	sleep_times = current_time();
	if (verify_args(argv, argc) == FALSE)
		return (0);
	state = state_init(argv, argc);
	state->thread = malloc(sizeof(thread) * state->philo_count);
	while (state->philo[inc])
	{
		pthread_create(&state->thread[inc], NULL, philo_loop,
			state->philo[inc]);
		inc++;
	}
	main_loop(state, 0);
	state_delete(state);
}
