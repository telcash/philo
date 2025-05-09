/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:13:03 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/09 16:13:35 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void thinking(t_philo *philo)
{
    if (is_philo_dead(philo->env))
        return;
    print_message(philo, "is thinking");
}

static void sleeping(t_philo *philo)
{
    if (is_philo_dead(philo->env))
        return;
    print_message(philo, "is sleeping");
    ft_usleep(philo->env->time_to_sleep);
}

static void eating(t_philo *philo)
{
    if (is_philo_dead(philo->env))
        return;
    pthread_mutex_lock(philo->left_fork_mutex);
    print_message(philo, "has taken a fork");
    if (philo->env->philo_count == 1)
    {
        ft_usleep(philo->env->time_to_die + 1);
        pthread_mutex_unlock(philo->left_fork_mutex);
        return ;
    }
    pthread_mutex_lock(philo->right_fork_mutex);
    print_message(philo, "has taken a fork");
    pthread_mutex_lock(&philo->env->last_eat_mutex);
    philo->last_eat = get_current_time();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->env->last_eat_mutex);
    print_message(philo, "is eating");
    ft_usleep(philo->env->time_to_eat);
    pthread_mutex_unlock(philo->right_fork_mutex);
    pthread_mutex_unlock(philo->left_fork_mutex);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    while (!is_philo_dead(philo->env))
    {
        eating(philo);
        sleeping(philo);
        thinking(philo);
    }
    return (NULL);
}