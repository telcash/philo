/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:08:32 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/02/13 22:12:19 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_env *env;
    t_table *table;

    if (argc < 5 || argc > 6)
        return (printf("Error: Wrong number of arguments\n"), 1);
    env = init_env(argc, argv);
    if (!env)
        return (printf("Error: Invalid arguments\n"), 1);
    table = init_table(env);
    if (!table)
        return(printf("Error: Table initialization failed\n"), 1);
    if (start_simulation(table))
        return (printf("Error: Simulation failed\n"), 1);
    destroy_mutexes(table);
    free(env);
    free(table->philo);
    free(table->forks);
    free(table);
    return (0);
}
