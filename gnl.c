/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:03:28 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/08 17:54:28 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!ft_strchr(str, 10) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}	
	free(buffer);
	return (str);
}

char	*get_one_line(char *str)
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

char	*get_end_of_line(char *str)
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
	tmp = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	k = 0;
	while (str[i])
		tmp[k++] = str [i++];
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = get_one_line(str);
	str = get_end_of_line(str);
	//if (str == NULL)
	//	free(str);
	return (line);
}

int	main(void)
{
	int	fd;
	char *s;

	fd = open("test.c", O_RDONLY);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	s = get_next_line(fd);
	printf("%s",s);
	free(s);
	close(fd);
	return (0);
}