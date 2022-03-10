/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:06:29 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/07 17:56:47 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	ret;
	static char	*s;
	char		*str;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read(&s, &ret, fd);
	return (str);
}

char	*ft_read(char **s, int *ret, int fd)
{
	char	*str;
	char	*tmp;
	int		flag;
	char	*tampon;

	*str = NULL;
	*tmp = NULL;
	flag = 0;
	tampon = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tampon == NULL)
		return (NULL);
	tampon [0] = '\0';
	if (*ret == 0)
	{
		*ret = read(fd, tampon, BUFFER_SIZE);
		tampon[*ret] = '\0';
	}
	if(!*s)
		*s = tampon;
	while (flag == 0 && *ret > 0)
	{
		if (ft_strseek(*s, '\n') != -1)
		{
			str = ft_strcpy(*s, ft_strseek(*s, '\n'));
			*c = ft_strcpystart(*s, ft_strseek(*s, '\n'));
			flag = 1;
		}		
		else 
		{	
			tmp =ft_strcpystart(*s, -1);
			*ret = read(fd, tampon, BUFFER_SIZE);
			tampon[*ret] = '\0';
			if (*ret != 0)
				*s = ft_strjoin(tmp, tampon);
			free(tmp);
		}
		if (*ret == 0)
		{
			str = ft_strcpy(*s, ft_strlen(*s));
			flag = 1;
		}
	}
	if (str != NULL && *str == 0)
	{
		free(str);
		str = NULL;
	}
	free(tampon);
	return (str);
}
