/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:50:41 by jduval            #+#    #+#             */
/*   Updated: 2023/04/06 18:19:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	long	i;
	long	value;
	long	a;

	value = 0;
	a = 1;
	i = 0;
	while (ft_isspace(nptr[i]) == true)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			a = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - '0');
		if (value > 2147483648 && a == -1)
			return (0);
		else if (value > 2147483647 && a == 1)
			return (0);
		i++;
	}
	return (value * a);
}

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

bool	check_overflow(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (true);
		i++;
	}
	return (false);
}
