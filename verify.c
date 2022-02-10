
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
	
	if (argc == 5 || argc == 6)
	{
		while(inc < argc)
		{
			if(is_not_number(argv[inc]))
			{
				printf("invalid input at: -> %s\n",argv[inc]);
				return(FALSE);
			}
			inc++;
		}
	}
	else
	{
		printf("wrong number of argument expected 5 or 6 got %d\n",argc - 1);
		return(FALSE);
	}
	inc = 1;	
	while (inc < argc - 2)
	{
		if(ft_atoi(argv[inc]) <= 0)
			return(FALSE);
		inc++;
	}
	if((ft_atoi(argv[inc]) < 0 && argc == 6) || (ft_atoi(argv[inc]) == 0 && argc == 5))	
		{
			printf("wrong content in last field\n");
		return(FALSE);
		}
	return (TRUE);
	
	printf("Error: wrong number of field(s)\n");
	return (FALSE);
}
