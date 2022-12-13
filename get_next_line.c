/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:44 by jaragao-          #+#    #+#             */
/*   Updated: 2022/12/13 17:08:17 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (ft_strchar(buffer, '\n'))
	{
		line = ft_strjoin(line, buffer);
		ft_clean(line);
		ft_index(buffer);
		return (line);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchar(buffer, '\n'))
			break ;
	}
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	ft_clean(line);
	ft_index(buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("text", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
