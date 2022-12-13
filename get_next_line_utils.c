/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:05 by jaragao-          #+#    #+#             */
/*   Updated: 2022/12/13 16:30:20 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_clean(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	while (line[i])
		line[i++] = '\0';
}

void	ft_index(char *buffer)
{
	int	i;
	int	y;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return ;
	}
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
	while (str[i])
		i++;
	return (i);
}
