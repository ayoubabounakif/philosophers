/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:50:16 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/03 09:50:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/philo_one.h"

pthread_mutex_t	mutex;

void		*routine(void *args)
{
	// TO-DO: Make a fucking routine
	printf("Philosopher is thinking...\n");

	// TO-DO: Make another lock as you said, and then unlock both of then when the philosopher is eating
	if (pthread_mutex_lock(&mutex) == 0)
		printf("Philosopher is eating...\n");
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void		threads(t_status *status)
{
	int			i;
	pthread_t	thread_id[status->number_of_philosophers];

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < status->number_of_philosophers)
	{
		if (pthread_create(thread_id + i, NULL, &routine, NULL) != 0)
			perror("Failed to create thread\n");
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return ;
}

t_status	*init(t_status *status, int ac, char **av)
{
	int		i = 0;

	status->number_of_philosophers = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		status->number_of_times_must_eat = ft_atoi(av[5]);
	else
		status->number_of_times_must_eat = 0;
	status->philos = (t_philo *)malloc(status->number_of_philosophers * sizeof(status->philos));
	while (i < status->number_of_philosophers)
	{
		status->philos[i].number = i;
		status->philos[i].left_fork = i;
		status->philos[i].right_fork = (i + 1) % status->number_of_philosophers;
		i++;
	}
	return (status);
}

int			main(int ac, char **av)
{
	t_status	status;
	
	if (ac < 5 || ac > 6)
			return (ft_exit("Error: Bad arguments number!\nQuitting...\n"));
	else
	{
		init(&status, ac, av);
		threads(&status);
		// printf("Number of philosophers : %d\n", status.number_of_philosophers);
		// printf("Time to die : %llu\n", status.time_to_die);
		// printf("Time to eat : %llu\n", status.time_to_eat);
		// printf("Time to sleep : %llu\n", status.time_to_sleep);
		// printf("Number of times a philosopher must eat : %d\n", status.number_of_times_must_eat);

		// printf("STARTING SIMULATION\n");
	}


					// TIME MONITORING (WILL COME BACK TO LAATER)

	/*
	**	Any change of status of a philosopher must be written as follows (with X replaced
	**	with the philosopher number and timestamp_in_ms the current timestamp in milliseconds)

			◦ timestamp_in_ms X has taken a fork
			◦ timestamp_in_ms X is eating
			◦ timestamp_in_ms X is sleeping
			◦ timestamp_in_ms X is thinking
			◦ timestamp_in_ms X died

	*/

	// struct timespec start, end;
	// clock_gettime(CLOCK_MONOTONIC_RAW, &start);

	// // DO STUFF (FOR EXAMPLE PHILOSOPHER STARTED EATING)

	// clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	// uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

	return (EXIT_SUCCESS);
}
