/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:53:55 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/09 13:28:24 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen_bonus(char *s);
char	*ft_strchr_bonus(const char *s, int c);
char	*ft_strjoin_bonus(const char *s1, const char *s2);
char	*get_end_of_line_bonus(char *str);
char	*get_one_line_bonus(char *str);
char	*ft_read_bonus(char **str, int fd);

#endif
