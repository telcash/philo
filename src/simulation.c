/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:43:10 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/09 16:08:49 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int is_philo_dead(t_env *env)
{
    pthread_mutex_lock(&env->dead_mutex);
    if (env->philo_dead > 0)
    {
        pthread_mutex_unlock(&env->dead_mutex);
        return (1);
    }
    pthread_mutex_unlock(&env->dead_mutex);
    return (0);
}

static int create_philos_threads(t_table *table)
{
    int i;

    i = 0;
    while (i < table->env->philo_count)
    {
        if (pthread_create(&table->philo[i].thread, NULL, &philo_routine, &table->philo[i]))
            return (1) ;
        i++;
    }
    i = 0;
    while (i < table->env->philo_count)
    {
        if (pthread_join(table->philo[i].thread, NULL))
            return (1);
        i++;
    }
    return (0);
}

void sync_philo_last_eat(t_table *table)
{
    int i;
    
    i = 0;
    while (i < table->env->philo_count)
    {
        table->philo[i].last_eat = table->env->start_time;
        i++;
    }
}

int start_simulation(t_table *table)
{
    pthread_t monitor;

    table->env->start_time = get_current_time();
    sync_philo_last_eat(table);
    if (pthread_create(&monitor, NULL, &monitor_routine, table))
        return (destroy_mutexes(table), 1);
    if (create_philos_threads(table))
        return (destroy_mutexes(table), 1);
    if (pthread_join(monitor, NULL))
        return (destroy_mutexes(table), 1);
    return (0);
}
