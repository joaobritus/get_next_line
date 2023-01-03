/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:00:44 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/03 16:07:54 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_restart(char *buffer)
{
	char	*line;

	line = malloc(ft_strlen(buffer) + 1);
	if (ft_strchar(buffer, '\n'))
	{
		line = ft_strjoin(line, buffer);
		line = ft_clean(line);
		ft_index(buffer);
		return (line);
	}
	line = ft_strjoin(line, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) <= 0)
		return (NULL);
	if (buffer[0] != '\0')
	{
		line = ft_restart(buffer);
		if (ft_strchar(line, '\n'))
			return (line);
		if (!line)
			return (NULL);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchar(buffer, '\n'))
			break ;
	}
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	line = ft_clean(line);
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
