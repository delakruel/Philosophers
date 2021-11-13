/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloyce <rloyce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:13:48 by rloyce            #+#    #+#             */
/*   Updated: 2021/10/28 21:26:40 by rloyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				ph;
	int				is_dead;
	int				eated;
	int				counted;
	int				eat_time;
	int				sleep_time;
	long long		time_last_eat;
	long long		time_start;
	pthread_t		thread;
	pthread_mutex_t	*mut;
	pthread_mutex_t	*writing;
}				t_philo;

typedef struct s_data
{
	int				num_must_eat;
	int				num_philo;
	int				sleep_time;
	int				eat_time;
	int				die_time;
	int				DEAD;
	long long		time_start;
	t_philo			*philo;
	pthread_mutex_t	*mut;
	pthread_mutex_t	writing;
}				t_data;

int			init_data(int argc, char **argv, t_data *data);
int			ft_atoi(const char *str);
void		init_philos(t_data *data);
void		init_philo_forks(t_data	*data);
void		mut_init(t_data *data, int num_philo, int k);
void		my_usleep(int	time_to_sleep);
void		sleeping(t_philo *philo);
void		eating(t_philo *philo);
void		*philo_do(void *args);
void		init_threads(t_data	*data);
void		monitoring(int argc, t_data *data, int i, int k);
void		printing(t_philo *philo, char *msg);
void		printing2(t_philo *philo, char *msg);
long long	get_time(void);

#endif
