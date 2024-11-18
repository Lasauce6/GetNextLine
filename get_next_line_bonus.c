/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:41:45 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/18 17:01:29 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	size_t	i;
	char	*line;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	free_m_str(char *m_str[4096])
{
	int	i;

	i = -1;
	while (++i < 4096)
	{
		if (m_str[i])
			free(m_str[i]);
	}
}

char	*read_m_str(int fd, char *m_str, char *buff)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	while (!ft_strchr(m_str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), NULL);
		buff[bytes] = '\0';
		temp = m_str;
		m_str = ft_strjoin(m_str, buff);
		free(temp);
	}
	return (free(buff), m_str);
}

char	*set_new_m_str(char *m_str)
{
	size_t	i;
	size_t	j;
	char	*new_m_str;

	i = 0;
	while (m_str[i] && m_str[i] != '\n')
		i++;
	if (!m_str[i])
		return (free(m_str), NULL);
	new_m_str = malloc(ft_strlen(m_str) - i + 1);
	if (!new_m_str)
		return (free(m_str), NULL);
	j = 0;
	while (m_str[++i])
		new_m_str[j++] = m_str[i];
	new_m_str[j] = '\0';
	free(m_str);
	return (new_m_str);
}

char	*get_next_line(int fd)
{
	static char	*m_str[4096];
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free_m_str(m_str), NULL);
	m_str[fd] = read_m_str(fd, m_str[fd], buff);
	if (!m_str[fd])
		return (NULL);
	line = get_line(m_str[fd]);
	if (line)
	{
		m_str[fd] = set_new_m_str(m_str[fd]);
		if (*line == 0)
			return (free(line), NULL);
	}
	else
		free_m_str(m_str);
	return (line);
}
