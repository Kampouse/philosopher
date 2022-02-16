/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:00:29 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 16:19:18 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	print_error(char *error)
{
	printf(" %s ", error);
	return (FALSE);
}

int	is_not_number(char *str)
{
	int	inc;

inc = 0;
	while (str[inc])
	{
		if (ft_isdigit(str[inc]))
			inc++;
		else
			return (1);
	}
	return (0);
}

int	verify_len(char *argv[], int argc)
{
	int	inc;

	inc = 1;
	if (argc == 5 || argc == 6)
	{
		while (inc < argc)
		{
			if (is_not_number(argv[inc]))
				return (print_error("invalid input at\n"));
			inc++;
		}
	}
	else
		return (print_error("wrong number of fields\n"));
	return (TRUE);
}

/* if too long  remove the printf calll*/
int	verify_args(char *argv[], int argc)
{
	int	inc;

	inc = 1;
	if (verify_len(argv, argc) == FALSE)
		return (FALSE);
	inc = 1;
	while (inc < argc - 2)
	{
		if (ft_atoi(argv[inc]) <= 0)
			return (print_error(
					"argument cannot be eithe zero or under or  over 200\n"));
		inc++;
	}
	if ((ft_atoi(argv[inc]) < 0 && argc == 6) || (
			ft_atoi(argv[inc]) == 0 && argc == 5))
		return (print_error("wrong content in last field\n"));
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (print_error("sorry you cant eat 0  time\n"));
	else
		return (TRUE);
	return (print_error("Error: wrong number of field(s)\n" ));
}
