/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:41:45 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/20 15:37:49 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_m_str(int fd, char *m_str)
{
	char	*buff;
	char	*temp;
	ssize_t	bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
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
	free(buff);
	return (m_str);
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

char	*set_new_m_str(char *m_str[4096], int fd)
{
	size_t	i;
	size_t	j;
	char	*new_m_str;

	i = 0;
	while (m_str[fd][i] && m_str[fd][i] != '\n')
		i++;
	if (!m_str[fd][i] || !m_str[fd][i + 1])
	{
		free(m_str[fd]);
		return (NULL);
	}
	new_m_str = malloc(ft_strlen(m_str[fd]) - i + 1);
	if (!new_m_str)
		return (free_m_str(m_str), NULL);
	j = 0;
	while (m_str[fd][++i])
		new_m_str[j++] = m_str[fd][i];
	new_m_str[j] = '\0';
	return (free(m_str[fd]), new_m_str);
}

char	*get_next_line(int fd)
{
	static char	*m_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	m_str[fd] = read_m_str(fd, m_str[fd]);
	if (!m_str[fd])
		return (NULL);
	line = get_line(m_str[fd]);
	if (line)
	{
		if (*line == 0)
		{
			free(line);
			return (0);
		}
		m_str[fd] = set_new_m_str(m_str, fd);
	}
	else
		free_m_str(m_str);
	return (line);
}
