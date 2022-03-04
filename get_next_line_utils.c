/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:03:05 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/04 16:10:45 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	if (ft_strlen((char *) s1) + ft_strlen((char *) s2) == 0)
	{
		s3 = malloc(sizeof(char));
		*s3 = 0;
		return (s3);
	}
	s3 = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*src;
	char	*tab;

	src = (char *)s1;
	i = 0;
	while (src[i])
		i++;
	tab = malloc(sizeof(*tab) * i + 1);
	if (tab == 0x0)
		return (0x0);
	i = 0;
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
