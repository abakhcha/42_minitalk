/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:14:53 by abakhcha          #+#    #+#             */
/*   Updated: 2024/02/18 14:22:45 by abakhcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int		ft_atoi(char *str);
int	ft_printf(const char *str, ...);
void	send(int pid, char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int argn, char **pidmsg)
{
	char *message;
	int pid;
	int i;

	i = 0;
	if (argn == 3)
	{
		pid = ft_atoi(pidmsg[1]);
		message = pidmsg[2];
		if (message[0] == 0)
			ft_printf("Pls enter your message");
		while (message[i])
		{
			send(pid, message[i]);
			i++;
		}
		send(pid, '\0');
	}
	else
		ft_printf("Enter the server's PID followed by the message");
}
