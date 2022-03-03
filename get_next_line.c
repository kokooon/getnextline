/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:03:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/03 20:57:59 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleantmp(char *s, char *tmp)
{
	char	*s1;
	char	*tmp1;
	int		i;

	i = 0;
	s1 = s;
	tmp1 = tmp;
	if (!(ft_strchr(tmp, 10))
		{
			s = ft_strjoin(s1, tmp1);
			return (NULL);
		}
	else
	{
		tmp = ft_strdup(ft_strchr(tmp1, 10) + 1);
		i = ft_strlen(tmp1) - ft_strlen(tmp);
		*(tmp1 + i) = '\0';
		return (tmp1);
	}
}

char	*get_next_line(int fd)
{
	static char	*s;
	static char	buffer[BUFFER_SIZE + 1];
	int			len;
	static char	*tmp;
	int			i;

	if (fd == -1)
		return (NULL);
	s = NULL;
	tmp = NULL;
	i = 0;
	if (tmp != NULL)
	{
		tmp = ft_cleantmp(s, tmp);
		if (tmp != NULL)
			return (s);
	}
	if (tmp == NULL)
		len = read(fd, buffer, BUFFER_SIZE);
	buffer[len] = '\0';
	if (len < 0)
		return (NULL);
	if (len == 0)
		return (s);
	while (len)
	{
		if (buffer[len - 1] == '\0')
		{
			// a modifier la copie du buffeur pas -> le buffeur contient plusieurs /n
			s = ft_strjoin(s, buffer);
			return (s);
		}
		if (!ft_strchr(buffer, 10))
			s = ft_strjoin(s, buffer);
		else
		{
			tmp = ft_strdup(ft_strchr(buffer, 10) + 1);
			i = ft_strlen(buffer) - ft_strlen(tmp);
			buffer[i] = '\0';
			s = ft_strjoin(s, buffer);
			//ft_cleantmp(*s, tmp);
		}
		//len = read(fd, buffer, BUFFER_SIZE);
	}
	return (s);
}


//ssize_t read(int fd, void *buf, size_t count);