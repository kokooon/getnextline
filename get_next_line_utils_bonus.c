/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:57:53 by gmarzull          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:31 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_bonus(char *t)
{
	int	i;

	i = 0;
	if (!t || !(t[i]))
		return (0);
	while (t[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
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

char	*ft_strjoin_bonus(const char *s1, const char *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	if (ft_strlen_bonus((char *) s1) + ft_strlen_bonus((char *) s2) == 0)
		return (NULL);
	s3 = (char *)malloc(sizeof(char)
			* (ft_strlen_bonus((char *)s1) + ft_strlen_bonus((char *)s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
