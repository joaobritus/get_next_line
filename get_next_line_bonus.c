/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:58:37 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/23 15:16:46 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = ft_strjoin(line, buffer);
	if (ft_strchar(buffer, '\n'))
	{
		ft_index(buffer);
		return (line);
	}
	ft_index(buffer);
	if (read(fd, 0, 0) < 0)
		return (filed(line));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchar(buffer, '\n'))
			break ;
		ft_index(buffer);
	}
	ft_index(buffer);
	return (line);
}