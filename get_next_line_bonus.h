/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:58:42 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/23 15:20:27 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin(char *line, char *buffer);
int		ft_strchar(char *str, char c);
void	ft_index(char *buffer);
char	*ft_clean(char *line);
int		ft_strlen(char *str);
char	*filed(char *line);

#endif