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




int main(int argc,char *argv[])
{
	if (verify_args(argv,argc) == true)
		display_args(argc,argv);

	



	
}
