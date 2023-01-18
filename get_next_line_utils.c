/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:05 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/18 16:28:21 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	int		i;
	int		y;

	i = 0;
	y = 0;
	str = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while ((buffer[y] != '\0') && (buffer[y]))
		str[i++] = buffer[y++];
	str[i] = '\0';
	free(line);
	return (str);
}

char	*ft_clean(char *line)
{
	int	i;

	i = 0;
	while ((line[i] != '\n') && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
		line[i++] = '\0';
	return (line);
}

void	ft_index(char *buffer)
{
	int	i;
	int	y;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	y = 0;
	while (buffer[i])
		buffer[y++] = buffer[i++];
	while (buffer[y])
		buffer[y++] = '\0';
}

int	ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '\n') && (str[i]))
		i++;
	return (i);
}
