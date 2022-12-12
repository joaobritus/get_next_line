/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:11:05 by jaragao-          #+#    #+#             */
/*   Updated: 2022/12/12 17:08:26 by jaragao-         ###   ########.fr       */
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
		s1 = malloc(1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
		str[i++] = s1[i++];
	while (s2[y])
		str[i++] = s2[y++];
	free (s1);
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

char	*ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		str++;
	return (str);
}
