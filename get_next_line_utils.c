/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:05 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/19 15:00:42 by jaragao-         ###   ########.fr       */
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
	if (!buffer)
		return (line);
	if (!line)
		line = "";
	str = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!str)
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while ((buffer[y] != '\n') && (buffer[y]))
		str[i++] = buffer[y++];
	str[i] = '\0';
	free(line);
	return (str);
}

void	ft_index(char *buffer)
{
	int	i;
	int	y;

	if (!buffer)
		return ;
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	i++;
	y = 0;
	while (buffer[i] && buffer)
		buffer[y++] = buffer[i++];
	while (buffer[y] && buffer)
		buffer[y++] = '\0';
}

int	ft_strchar(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
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

	if (!str)
		return (-1);
	i = 0;
	while ((str[i] != '\n') && (str[i]))
		i++;
	return (i);
}
