
#include "philo.h"

int is_not_number(char *str)
{
int inc;

inc = 0;

	while(str[inc])
	{

		if(ft_isdigit(str[inc]))
			inc++;
		else
			return(1);
	}
return(0);
}

/* if too long  remove the printf calll*/
int verify_args(char *argv[],int argc)
{
	int inc;
	
	inc = 1;
	
	if (argc == 6 || argc == 7)
	{
		while(inc < argc)
		{
			if(is_not_number(argv[inc]))
			{
				printf("invalid input at: -> %s\n",argv[inc]);
				return(1);
			}
			inc++;
		}
	}
	else
		printf("wrong number of argument expected 5 or 6 got %d\n",argc - 1);
	inc = 1;	
	while (inc < argc - 2)
	{
		if(ft_atoi(argv[inc]) <= 0)
			return(false);
		inc++;
	}
	if((ft_atoi(argv[inc]) < 0 && argc == 6) || (ft_atoi(argv[inc]) == 0 && argc == 5))	
		{
			printf("wrong content in last field\n");
		return(false);
		}
	return (true);
	
	printf("Error: wrong number of field(s)\n");
	return (false);
}
