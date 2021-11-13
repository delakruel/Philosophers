/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:11:56 by rloyce            #+#    #+#             */
/*   Updated: 2021/10/28 21:26:01 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	printing(philo, "is sleeping \n");
	my_usleep(philo->sleep_time);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut[philo->right_fork]);
	printing(philo, "has taken a fork\n");
	pthread_mutex_lock(&philo->mut[philo->left_fork]);
	printing(philo, "has taken a fork\n");
	printing(philo, "is eating\n");
	my_usleep(philo->eat_time);
	philo->time_last_eat = get_time();
	philo->eated--;
	pthread_mutex_unlock(&philo->mut[philo->left_fork]);
	pthread_mutex_unlock(&philo->mut[philo->right_fork]);
}

void	*philo_do(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->ph % 2 == 0)
		usleep(500);
	while (philo->is_dead == 0 && philo->eated != 0)
	{
		eating(philo);
		sleeping(philo);
		printing(philo, "is thinking\n");
	}
	return (NULL);
}

void	init_threads(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		{
			data->philo[i].time_last_eat = get_time();
			pthread_create(&data->philo[i].thread,
				NULL, philo_do, &data->philo[i]);
		}
		i++;
	}
}

void	monitoring(int argc, t_data *data, int i, int k)
{
	while (data->DEAD == 0 && k != data->num_philo)
	{
		i = 0;
		while (i < data->num_philo && data->DEAD == 0)
		{
			if (data->philo[i].eated != 0)
			{
				if (get_time() - data->philo[i].time_last_eat
					> data->die_time)
				{
					data->philo[i].is_dead = 1;
					data->DEAD = 1;
					printing2(&data->philo[i], "died\n");
				}
			}
			if (argc == 6 && data->philo[i].eated == 0
				&& data->philo[i].counted == 0)
			{
				k++;
				data->philo[i].counted = 1;
			}
			i++;
		}
	}
}
