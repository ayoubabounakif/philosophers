/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:50:16 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/03 09:50:16 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/philo_bonus.h"

int	main(int ac, char **av)
{
	t_status	*status;
	
	if (ac != 5 && ac != 6)
			return (printError("Error: Bad arguments number\n"));
	else
	{
		status = (t_status *)malloc(sizeof(t_status));
		Constructor(status, ac, av);
		if (status->numberOfPhilosophers == 0)
			return (EXIT_SUCCESS);
		semaphoreConstructor(status);
		spawnProcs(status);
	}
	return (EXIT_SUCCESS);
}
