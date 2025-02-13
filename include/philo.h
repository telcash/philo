/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:08:48 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/02/13 22:09:58 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# ifndef MAX_PHILOS
#  define MAX_PHILOS 200
# endif
# ifndef MIN_TIME
#  define MIN_TIME 60
# endif

typedef struct s_env
{
    int				philo_count;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				must_eat_count;
    int			start_time;
    int                philo_dead;
    pthread_mutex_t    dead_mutex;
    pthread_mutex_t    last_eat_mutex;
}	t_env;

typedef struct s_philo
{
    int				id;
    int				eat_count;
    int			last_eat;
    t_env            *env;
    pthread_t        thread;
    pthread_mutex_t	*left_fork_mutex;
    pthread_mutex_t	*right_fork_mutex;
    pthread_mutex_t    *dead_mutex;
    pthread_mutex_t *print_mutex;
}	t_philo;

typedef struct s_table
{
    t_env			*env;
    pthread_mutex_t    print_mutex;
    pthread_mutex_t	*forks;
    t_philo			*philo;
} t_table;

t_env		*init_env(int argc, char **argv);
t_table		*init_table(t_env *env);
int			start_simulation(t_table *table);
int        get_current_time(void);
void        print_message(t_philo *philo, char *message);
void *philo_routine(void *arg);
void *monitor_routine(void *arg);
int is_philo_dead(t_env *env);
int	ft_usleep(size_t milliseconds);
void destroy_mutexes(t_table *table);
#endif