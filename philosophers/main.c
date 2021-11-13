/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:01:55 by rloyce            #+#    #+#             */
/*   Updated: 2021/10/26 15:42:33 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_help(int argc, t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	mut_init(data, data->num_philo, 0);
	init_philo_forks(data);
	init_threads(data);
	monitoring(argc, data, 0, 0);
	while (i++ < data->num_philo)
		if (data->philo[i].counted == 1)
			k++;
	i = 0;
	if (k == data->num_philo)
		while (i++ < data->num_philo)
			pthread_join(data->philo[i].thread, NULL);
	mut_init(data, data->num_philo, 1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 6 || argc < 5)
	{
		printf("Wrong number of arguments!\nError\n");
		return (0);
	}
	if (init_data(argc, argv, &data) == 0)
	{
		printf("Error\n");
		return (0);
	}
	main_help(argc, &data);
	free (data.philo);
	free (data.mut);
	return (0);
}
