/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:44 by jaragao-          #+#    #+#             */
/*   Updated: 2022/12/07 17:09:55 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*index(char *line)
{
	char	*rightindex;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while ((line[i] != '\n') || line[i])
		i++;
	if (line[i] == '\0')
		return (NULL);
	i++;
	while (line[i])
		rightindex[y++] = line[i++];
	return (rightindex);
}

char	*cut(char *line)
{
	char	*niceline;
	int		i;
	int		max;

	i = 0;
	while (line[i] != '\n')
		i++;
	max = i;
	i = 0;
	while (i < max)
		niceline[i++] = line[i++];
	return (niceline);
}

char	*glue(char *buffer, char *line)
{
	int		i;
	int		y;
	char	*newline;

	newline = malloc(BUFFER_SIZE + ft_strlen(line) + 1);
	if (!newline)
		return (NULL);
	i = 0;
	while (line && line[i])
		newline[i++] = line[i++];
	y = 0;
	while (buffer[i])
		newline[i++] = buffer[y++];
	return (newline);
}

char	*get_line(int fd, char *buffer)
{
	char	*line;
	int		bytenumber;

	bytenumber = 1;
	while (bytenumber > 0)
	{
		bytenumber = read(fd, buffer, BUFFER_SIZE + 1);
		if (bytenumber < 0)
			return (NULL);
		buffer[bytenumber] = '\0';
		line = glue(buffer, line);
		if (ft_strchar(buffer, '\n'))
			break ;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*niceline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line);
	if (!line)
		return (NULL);
	niceline = cut(line);
	line = index(line);
	return (niceline);
}
