/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:16:31 by abakhcha          #+#    #+#             */
/*   Updated: 2024/02/18 14:23:00 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int	ft_printf(const char *str, ...);
void	recieved(int signal)
{
	static unsigned char	rec;
	static int				b_index;

	if (signal == SIGUSR2)
		rec |= 0;
	else if (signal == SIGUSR1)
		rec |= 1;
	b_index++;
	if (b_index == 8)
	{
		if (rec == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", rec);
		b_index = 0;
		rec = 0;
	}
	else
		rec <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, recieved);
	signal(SIGUSR2, recieved);
	while (1)
		pause();
}
