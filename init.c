/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:24:15 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 15:40:51 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**philo_init(t_state *state, char *argv[], int argc, int inc)
{
	t_philo		**philos;
	const int	nbr_philo = ft_atoi(argv[1]);

	philos = NULL;
	philos = ft_calloc(sizeof(t_philo **), nbr_philo + 1);
	while (++inc != nbr_philo)
	{
		philos[inc] = ft_calloc(sizeof(t_philo), 1);
		philos[inc]->lfork = inc;
		philos[inc]->rfork = (inc + 1) % nbr_philo;
		philos[inc]->nbr = inc;
		philos[inc]->ate = 0;
		philos[inc]->death_time = ft_atoi(argv[2]);
		philos[inc]->time_to_eat = ft_atoi(argv[3]);
		philos[inc]->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philos[inc]->must_eat = ft_atoi(argv[5]);
		else
			philos[inc]->must_eat = -1;
	philos[inc]->l_fork = state->forks[philos[inc]->lfork];
	philos[inc]->r_fork = state->forks[philos[inc]->rfork];
	philos[inc]->states = state;
	}
	return (philos);
}

int	print_protected(t_state *state, char *something, int nbr, int when)
{
	(void)when;
	pthread_mutex_lock(&state->print);
	printf("%d %d %s\n", when, nbr + 1, something);
	pthread_mutex_unlock(&state->print);
	return (0);
}

t_state	*state_init(char *argv[], int argc)
{
	int			inc;
	const int	nbr_philo = ft_atoi(argv[1]);
	t_state		*state;

	inc = 0;
	state = ft_calloc(sizeof(t_state), 1);
	state->is_alive = 1;
	state->forks = ft_calloc(sizeof(pthread_mutex_t), nbr_philo);
	state->philo_count = nbr_philo;
	pthread_mutex_init(&state->print, NULL);
	pthread_mutex_init(&state->forks[inc], NULL);
	while (inc < nbr_philo)
	{
		pthread_mutex_init(&state->forks[inc], NULL);
		inc++;
	}
	state->philo = philo_init(state, argv, argc, -1);
	return (state);
}

int	display_args(int argc, char *argv[])
{
	(void)argc;
	printf("there will be : %d philos and forks\n", ft_atoi(argv[1]));
	printf("time before dying must eat: %d\n", ft_atoi(argv[2]));
	printf("they take  to eat : %d\n", ft_atoi(argv[3]));
	printf("they take  to sleep : %d\n", ft_atoi(argv[4]));
	if (argc == 6)
		printf("optional must eat: %d\n", ft_atoi(argv[5]));
	return (0);
}
