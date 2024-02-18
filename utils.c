/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:05:23 by abakhcha          #+#    #+#             */
/*   Updated: 2024/02/17 17:15:15 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int		i;
	int		sym;
	long	res;

	i = 0;
	sym = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sym *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sym * res);
}
