/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:25 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 16:14:00 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define  PHILO_H
# include "stdio.h"
# include "pthread.h"
# include "unistd.h"
# include<sys/time.h>
# include "pthread.h"
# include "libft/libft.h"

# define  TRUE 1
# define  FALSE 0

typedef struct t_philo
{
	unsigned int		death_time;
	unsigned int		last_ate;
	int					lfork;
	int					rfork;
	int					ate;
	int					state;
	int					is_eating;
	int					nbr;
	int					start;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_take_eat;
	size_t				time_to_sleep;
	size_t				time_to_think;
	size_t				next_meal;
	size_t				must_eat;
	void				*states;
	pthread_mutex_t		l_fork;	
	pthread_mutex_t		r_fork;	
}	t_philo;

typedef struct t_state
{
	int					philo_count;
	int					forks_counter;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				must_eat;
	pthread_mutex_t		death;	
	pthread_mutex_t		print;	
	pthread_mutex_t		*forks;	
	t_philo				**philo;
	int					is_alive;
	pthread_t			*thread;	

}	t_state;

int				is_all_number(char **args);
int				is_number(char *str);
int				verify_args(char *argv[], int argc);
t_state			*general_init(int argc, char *argv[], t_state **state);
void			sleep_time(int lenght);
unsigned int	current_time(void);
void			*philo_loop(void *philo);
int				print_protected(t_state *state,
					char *something, int nbr, int when);
int				must_eat(t_state *states);
t_philo			**philo_init(t_state *state, char *argv[], int argc, int inc);
int				print_protected(t_state *state,
					char *something, int nbr, int when);
t_state			*state_init(char *argv[], int argc);
int				display_args(int argc, char *argv[]);
int				ft_atoi(const char *value);
void			*ft_calloc(unsigned long lenght, unsigned long size);
int				ft_isdigit(int str);
#endif 
