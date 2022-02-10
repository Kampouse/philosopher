#include "philo.h"




void * philo_loop(void *philo)
{
	t_philo *phil;
	t_state *state;
	int meal;
phil = philo;
state = phil->states;
meal = current_time() + phil->death_time;
printf("%ul\n",(unsigned int)meal / 100000000);
	while(1)
	{
		sleep_time(phil->time_to_eat);

		printf("%d\n",phil->nbr);
		sleep_time(phil->time_to_eat);

	}
 //eat
//sleep
//think
return(0);
}
