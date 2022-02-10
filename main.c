#include "philo.h"



int display_args(int argc,char *argv[])
{
	(void)argc;
  printf("there will be : %d philos and forks\n",ft_atoi(argv[1]));
  printf("time before dying must eat: %d\n",ft_atoi(argv[2]));
  printf("they take  to eat : %d\n",ft_atoi(argv[3]));
  printf("they take  to sleep : %d\n",ft_atoi(argv[4]));
  if(argc == 6)
	  printf("optional must eat: %d\n",ft_atoi(argv[5]));

return(0);
}


void philo_delete(t_philo **philo)
{
int inc;

inc = 0;
	while(philo[inc])
	{
		free(philo[inc]);
		inc++;
	}
	free(philo);
}

t_philo **philo_init(t_state *state, char *argv[])
{

	(void)state;
	t_philo	**philos;
	int inc;
	const int nbr_philo	 = ft_atoi(argv[1]);

	inc = 0;
	philos = NULL;
	 philos = ft_calloc(sizeof(t_philo **),nbr_philo + 1);
	while (inc != nbr_philo)
	{
		philos[inc] = ft_calloc(sizeof(t_philo),1);
		philos[inc]->lfork = inc;
		philos[inc]->rfork = (inc + 1) % nbr_philo;
	    philos[inc]->nbr  = inc;
	    philos[inc]->ate  = 0;
	    philos[inc]->death_time = ft_atoi(argv[2]);
	    philos[inc]->time_to_eat = ft_atoi(argv[3]);
	    philos[inc]->time_to_sleep = ft_atoi(argv[4]);
	    philos[inc]->must_eat = ft_atoi(argv[5]);
	    philos[inc]->states = state;
			inc++;
	}
return (philos);
}

t_state *state_init(char *argv[])
{
	int		inc;

	const int nbr_philo  = ft_atoi(argv[1]);
	t_state *state;

	inc = 0;
	state = ft_calloc(sizeof(t_state), 1);	
	state->forks = ft_calloc(sizeof(pthread_mutex_t), nbr_philo);
	state->philo_count = nbr_philo;
	while (inc < nbr_philo)
	{
		pthread_mutex_init(&state->forks[inc], NULL);
		inc++;
	}
	state->philo = philo_init(state, argv);
	return (state);
}
 void state_delete(t_state *state)
{
	int		inc;

	inc = 0;
	while (inc < state->philo_count)
	{
		pthread_mutex_destroy(&state->forks[inc]);
		inc++;
	}
	philo_delete(state->philo);
	free(state->forks);
	free(state);
}
int main(int argc, char *argv[])
{
	t_state *state;
	long  sleep_times;
	pthread_t thread;	
	int inc;
	
	inc  = 0;
	//make an array of thread
	sleep_times = current_time();
	if (verify_args(argv, argc) == TRUE)
		display_args(argc, argv);
	else
		return (0);
	state = state_init(argv);
	while(state->philo[inc])
	{
		pthread_create(&thread,NULL,philo_loop,state->philo[inc]);
		usleep(15000);
		inc++;
	}
	while(1)
	{

		inc++;
	}
	state_delete(state);
}
