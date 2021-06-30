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

int	main(int ac, char **av)
{
	t_status	status;
	
	if (ac < 5 || ac > 6)
			return (printError("Error: Bad arguments number!\n"));
	else
	{
		Constructor(&status, ac, av);
		mutexConstructor(&status);
		runThreads(&status);
		// superviseThreads(&status);
	}
	return (EXIT_SUCCESS);
}
