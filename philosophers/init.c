/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:03:58 by rloyce            #+#    #+#             */
/*   Updated: 2021/10/25 22:54:30 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mut_init(t_data *data, int num_philo, int k)
{
	int	i;

	i = 0;
	if (k == 0)
	{
		pthread_mutex_init(&data->writing, NULL);
		while (i < num_philo)
		{
			pthread_mutex_init(&(data->mut[i]), NULL);
			i++;
		}
	}
	else
	{
		pthread_mutex_destroy(&data->writing);
		while (i < num_philo)
		{
			pthread_mutex_destroy(&(data->mut[i]));
			i++;
		}
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].ph = i;
		data->philo[i].mut = data->mut;
		data->philo[i].is_dead = 0;
		data->philo[i].eated = data->num_must_eat;
		data->philo[i].counted = 0;
		data->philo[i].eat_time = data->eat_time;
		data->philo[i].sleep_time = data->sleep_time;
		data->philo[i].time_start = data->time_start;
		data->philo[i].writing = &data->writing;
		i++;
	}
}

void	init_philo_forks(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (i == 0)
			data->philo[i].left_fork = data->num_philo - 1;
		else if (i % 2 == 0)
			data->philo[i].left_fork = i - 1;
		else
			data->philo[i].left_fork = i;
		if (i % 2 == 0)
			data->philo[i].right_fork = i;
		else
			data->philo[i].right_fork = i - 1;
		i++;
	}
	init_philos(data);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_philo = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = -1;
	if ((data->num_philo <= 0 || data->die_time <= 0 || data->eat_time <= 0
			|| data->sleep_time <= 0) || (argc == 6 && data->num_must_eat <= 0))
	{
		printf("Program works only with positive numbers!\n");
		return (0);
	}
	data->DEAD = 0;
	data->time_start = get_time();
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	data->mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_philo);
	if (!data->mut || !data->philo)
	{
		printf("Malloc error\n");
		return (0);
	}
	return (1);
}
