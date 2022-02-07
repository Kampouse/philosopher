#include "philo.h"



long current_time(void)
{
	struct timeval te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000 + te.tv_usec / 1000);	
}



void sleep_time(int lenght)
{
const long time  = current_time();

	while(current_time() < time + lenght)
	{
		usleep(lenght);
	}

}
