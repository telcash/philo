/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:40:35 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/09 14:36:39 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int get_current_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(philo->print_mutex);
    if (!is_philo_dead(philo->env))
        printf("%d %d %s\n", get_current_time() - philo->env->start_time, philo->id + 1, message);
    pthread_mutex_unlock(philo->print_mutex);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;
    size_t elapsed;
    size_t remaining;

	start = get_current_time();
    elapsed = 0;
	while (elapsed < milliseconds)
    {
        remaining = milliseconds - elapsed;
        if (remaining > 10)
            usleep(remaining * 800);
        else
            usleep(1000);
        elapsed = get_current_time() - start;
    }
	return (0);
}

void destroy_mutexes(t_table *table)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&table->print_mutex);
    pthread_mutex_destroy(&table->env->dead_mutex);
    pthread_mutex_destroy(&table->env->last_eat_mutex);
    while (i < table->env->philo_count)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
}