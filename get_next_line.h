/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:01:38 by rbaticle          #+#    #+#             */
/*   Updated: 2024/10/17 12:55:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
