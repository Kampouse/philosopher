/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:09:33 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/16 16:11:17 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *value)
{
	int			base;
	int			nbr;
	const char	*ptr;

	nbr = 0;
	base = 1;
	ptr = value;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{	
		if (*ptr == '-')
			base *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		nbr *= 10;
		nbr += (int)(*ptr - '0');
		ptr++;
	}
	return (nbr * base);
}

int	ft_isdigit(int str)
{
	return (str >= '0' && str <= '9');
}

void	*ft_calloc(unsigned long lenght, unsigned long size)
{
	void	*p;

	p = malloc(lenght * size);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, lenght * size));
}

void	*ft_memset(void *ptr, int value, size_t num)

{
	unsigned char	*pted;

	pted = ptr;
	while (num--)
	{
		*pted++ = (unsigned char)value;
	}
	return (ptr);
}
