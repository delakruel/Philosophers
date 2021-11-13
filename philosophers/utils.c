/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:06:55 by rloyce            #+#    #+#             */
/*   Updated: 2021/10/28 21:26:03 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	long int		n;
	long int		sign;

	sign = 1;
	i = 0;
	n = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(sign * n));
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}

void	my_usleep(int	time_to_sleep)
{
	struct timeval	t1;
	ssize_t			timing;

	gettimeofday(&t1, NULL);
	timing = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time_to_sleep > ((t1.tv_sec * 1000 + t1.tv_usec / 1000) - timing))
	{
		gettimeofday(&t1, NULL);
		usleep(50);
	}
}

void	printing(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->writing);
	if (philo->eated != 0)
		printf ("%lld Philo %d %s", get_time()
			- philo->time_start, philo->ph, msg);
	pthread_mutex_unlock(philo->writing);
}

void	printing2(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->writing);
	if (philo->eated != 0)
		printf ("%lld Philo %d %s", get_time()
			- philo->time_start, philo->ph, msg);
}
