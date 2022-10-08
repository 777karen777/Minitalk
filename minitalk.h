/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:53:24 by knikogho          #+#    #+#             */
/*   Updated: 2022/10/08 11:53:25 by knikogho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERR_ARG "Invalid arguments\nUsage: ./client [PID] [MSG]\n"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
#endif
