/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:30:23 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/02/13 21:56:36 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static pthread_mutex_t *init_forks(t_env *env)
{
    pthread_mutex_t *forks;
    int i;

    forks = malloc(sizeof(pthread_mutex_t) * env->philo_count);
    if (!forks)
        return (NULL);
    i = 0;
    while (i < env->philo_count)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    return (forks);
}

static t_philo *init_philos(t_table *table)
{
    t_philo *philo;
    int i;

    philo = malloc(sizeof(t_philo) * table->env->philo_count);
    if (!philo)
        return (NULL);
    i = 0;
    while (i < table->env->philo_count)
    {
        philo[i].id = i;
        philo[i].eat_count = 0;
        philo[i].last_eat = table->env->start_time;
        philo[i].env = table->env;
        philo[i].left_fork_mutex = &table->forks[i];
        if (i == table->env->philo_count - 1)
            philo[i].right_fork_mutex = &table->forks[0];
        else
            philo[i].right_fork_mutex = &table->forks[i + 1];
        philo[i].dead_mutex = &table->env->dead_mutex;
        philo[i].print_mutex = &table->print_mutex;
        i++;
    }
    return (philo);
}

t_table *init_table(t_env *env)
{
    t_table *table;
    
    table = malloc(sizeof(t_table));
    if (!table)
        return (NULL);
    table->env = env;
    pthread_mutex_init(&table->print_mutex, NULL);
    table->forks = init_forks(env);
    if (!table->forks)
        return (free(table), NULL);
    table->philo = init_philos(table);
    if (!table->philo)
    {
        free(table->forks);
        return (free(table), NULL);
    }
    return (table);
}

t_env   *init_env(int argc, char **argv)
{
    t_env *env;

    env = malloc(sizeof(t_env));
    if (!env)
        return (NULL);
    env->philo_count = ft_atoi(argv[1]);
    env->time_to_die = ft_atoi(argv[2]);
    env->time_to_eat = ft_atoi(argv[3]);
    env->time_to_sleep = ft_atoi(argv[4]);
    env->start_time = get_current_time();
    if (argc == 6)
        env->must_eat_count = ft_atoi(argv[5]);
    else
        env->must_eat_count = 0;
    env->philo_dead = 0;
    pthread_mutex_init(&env->dead_mutex, NULL);
    pthread_mutex_init(&env->last_eat_mutex, NULL);
    if (env->philo_count < 1 || env->philo_count > MAX_PHILOS || env->time_to_die < MIN_TIME || env->time_to_eat < MIN_TIME || env->time_to_sleep < MIN_TIME || env->must_eat_count < 0)
    {
        free(env);
        return (NULL);
    }
    return (env);
}
