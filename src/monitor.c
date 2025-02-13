/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:16:49 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/02/13 21:49:03 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int all_philos_ate(t_philo *philo)
{
    int i;

    i = 0;
    if (philo->env->must_eat_count == 0)
        return (0);
    while (i < philo->env->philo_count)
    {
        pthread_mutex_lock(&philo->env->last_eat_mutex);
        if (philo[i].eat_count < philo->env->must_eat_count)
        {
            pthread_mutex_unlock(&philo->env->last_eat_mutex);
            return (0);
        }
        pthread_mutex_unlock(&philo->env->last_eat_mutex);
        i++;
    }
    pthread_mutex_lock(&philo->env->dead_mutex);
    philo->env->philo_dead = 1;
    pthread_mutex_unlock(&philo->env->dead_mutex);
    return (1);
}

void *monitor_routine(void *arg)
{
    int i;
    int delta_eat;
    t_table *table;

    table = (t_table *)arg;
    while (!is_philo_dead(table->env) && !all_philos_ate(table->philo))
    {
        i = 0;
        while (i < table->env->philo_count)
        {
            pthread_mutex_lock(&table->env->last_eat_mutex);
            delta_eat = get_current_time() - table->philo[i].last_eat;
            pthread_mutex_unlock(&table->env->last_eat_mutex);
            if (delta_eat > table->env->time_to_die)
            {
                print_message(&table->philo[i], "died");
                pthread_mutex_lock(table->philo[i].dead_mutex);
                table->env->philo_dead = 1;
                pthread_mutex_unlock(table->philo[i].dead_mutex);
                return (NULL);
            }
            i++;
        }
    }
    return (NULL);
}
