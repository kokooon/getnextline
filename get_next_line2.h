/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:11:14 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/05 16:58:08 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
int	ft_strlen(const char *s);
char	*ft_cleantmp(char **s, char *tmp);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ftset(char *s);

# endif