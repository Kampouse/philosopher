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

t_philo **philo_init(char *argv[])
{

	t_philo	**philos;
	int inc;
	const int nbr_philo	 = ft_atoi(argv[1]);

	inc = 0;
	philos = NULL;
	 philos = ft_calloc(sizeof(t_philo **),nbr_philo + 1);
	while(inc != nbr_philo)
	{
		philos[inc] = ft_calloc(sizeof(t_philo),1);
		philos[inc]->death_time  = ft_atoi(argv[2]);
	    philos[inc]->last_ate  = ft_atoi(argv[2]);
			inc++;
	}
return (philos);
}

void forks_init(t_philo **philo,char *argv[])
{
	int		inc;
	(void)argv;
	
	inc = 0;
	while(philo[inc])
	{
			pthread_mutex_init(&philo[inc]->l_fork,NULL);
		inc++;
	}
}

int main(int argc,char *argv[])
{
	t_philo **philo;
	if (verify_args(argv,argc) == TRUE)
		display_args(argc,argv);
	else	
		return(0);
 philo = philo_init(argv);	
	forks_init(philo,argv);
	philo_delete(philo);	
}
