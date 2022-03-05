/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:03:09 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/05 14:59:34 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleantmp(char **s, char *tmp)
{
	char	*s1;
	char	*tmp1;
	int		i;

	i = 0;
	s1 = *s;
	tmp1 = tmp;
	if (!(ft_strchr(tmp, 10)))
	{
		*s = ft_strjoin(s1, tmp);
		free(s1);
		return (NULL);
	}
	else
	{
		tmp = ft_strdup(ft_strchr(tmp1, 10) + 1);
		i = ft_strlen(tmp1) - ft_strlen(tmp);
		*(tmp1 + i) = '\0';
		*s = ft_strdup(s1 + i);
		free(s1);
		return (tmp1);
	}
}

char	*ftset(char *s)
{
	if (s != NULL)
		return (s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*s;
	char	buffer[BUFFER_SIZE + 1];
	int			len;
	static char	*tmp;
	int			i;

	if (fd == -1)
		return (NULL);
	s = malloc(sizeof(char));
	if (!s)
		return (NULL);
	*s = 0;
	i = 0;
	tmp = ftset(tmp);
	while (tmp != NULL)
	{
		//printf(" la chaine s : %s", s);
		tmp = ft_cleantmp(&s, tmp);
		//printf(" la chaine s : %s", s);
		if (tmp != NULL /*&& *tmp*/)
			return (s);
		else
		{
			s = ft_strjoin(s, tmp);
			break ;
		}
	}
	//if (tmp == NULL)
	len = read(fd, buffer, BUFFER_SIZE);
	//printf("taille de len :%d \n", len);
	buffer[len] = '\0';
	//printf("buffer : %s", buffer);
	if (len < 0)
		return (NULL);
	if (len == 0)
		return (s);
	while (len)
	{
		if (len < BUFFER_SIZE)
		{
			// a modifier la copie du buffeur pas -> le buffeur contient plusieurs /n
			s = ft_strjoin(s, buffer);
			return (s);
		}
		if (!ft_strchr(buffer, 10))
		{
			//printf("La chaine s: %s \n", s);
			s = ft_strjoin(s, buffer);
			//printf("La chaine s: %s \n", s);
		}
		else
		{
			tmp = ft_strdup(ft_strchr(buffer, 10) + 1);
			i = ft_strlen(buffer) - ft_strlen(tmp);
			buffer[i] = '\0';
			s = ft_strjoin(s, buffer);
			return (s);
		}
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (s);
}

//ssize_t read(int fd, void *buf, size_t count);

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
	return (0);
}

//gcc -g3 -fsanitize=address  get_next_line.c get_next_line_utils.c get_next_line.h 