/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:55:30 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/08 19:17:21 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_bonus(char **str, int fd)
{
	char	*buffer;
	int		len;
	char	*tmp;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!ft_strchr_bonus(str[fd], 10) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		tmp = ft_strjoin_bonus(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
	}
	free(buffer);
	return (str[fd]);
}

char	*get_one_line_bonus(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_end_of_line_bonus(char *str)
{
	char	*tmp;
	int		i;
	int		k;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(*str))
	{
		free (str);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen_bonus(str) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	k = 0;
	while (str[i])
		tmp[k++] = str[i++];
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str[100];
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	str[fd] = ft_read_bonus(str, fd);
	if (!str[fd])
		return (NULL);
	line = get_one_line_bonus(str[fd]);
	str[fd] = get_end_of_line_bonus(str[fd]);
	return (line);
}
