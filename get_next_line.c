/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:44 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/19 14:40:47 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) <= 0)
		return (NULL);
	line = ft_strjoin(line, buffer);
	if (ft_strchar(buffer, '\n'))
	{
		ft_index(buffer);
		return (line);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchar(buffer, '\n'))
			break ;
	}
	ft_index(buffer);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("text", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}*/