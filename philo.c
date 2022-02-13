#include "philo.h"




void * philo_loop(void *philo)
{
	t_philo *phil;
	t_state *state;
	int start = current_time();
phil = philo;
state = phil->states;
	phil->time_to_take_eat = start + phil->death_time;
	if(phil->nbr % 2 == 0)
	{
		printf("%d\n",phil->nbr);
					usleep(16000);
	}
	while (1)
	{
		printf("is thinking %d\n",phil->nbr);
		sleep_time(phil->time_to_eat);
		printf("took l_fork %d\n",phil->nbr);
		pthread_mutex_lock(&state->forks[phil->lfork]);
		printf("took r_fork %d\n",phil->nbr);
		pthread_mutex_lock(&state->forks[phil->rfork]);
		sleep_time(phil->time_to_sleep);
		printf("drop l_fork %d\n",phil->nbr);
		pthread_mutex_unlock(&state->forks[phil->lfork]);
		pthread_mutex_unlock(&state->forks[phil->rfork]);
		printf("drop l_fork %d\n",phil->nbr);
		state->philo[phil->nbr]->time_to_take_eat = current_time() + phil->death_time;
		//printf("%u--\n",(unsigned int)state->philo[phil->nbr]->time_to_die);
		
		start = current_time();
		phil->ate++;
		//printf("philo:%d %d took lfrok: %d and rfork: %d\n",phil->nbr,  current_time() - start,phil->lfork,phil->rfork);
		//sleep_time(phil->time_to_eat);
	}
 //eat
//sleep
//think
return(0);
}
