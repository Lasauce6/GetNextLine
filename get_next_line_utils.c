/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:31:14 by rbaticle          #+#    #+#             */
/*   Updated: 2024/10/17 13:37:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c)
	{
		while (c[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	c = 0;
	i = 0;
	if (s1)
	{
		while (s1[i])
			str[c++] = s1[i++];
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			str[c++] = s2[i++];
	}
	str[c] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char) c;
	if (s)
	{
		i = -1;
		while (s[++i])
		{
			if (s[i] == ch)
				return ((char *) &s[i]);
		}
		if (ch == '\0')
			return ((char *) &s[i]);
	}
	return (0);
}
