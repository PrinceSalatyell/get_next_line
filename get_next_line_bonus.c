/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 06:42:29 by marvin            #+#    #+#             */
/*   Updated: 2022/03/09 06:42:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	save[FOPEN_MAX][BUFFER_SIZE];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	bytes_read = 1;
	line = 0;
	while (1)
	{
		if (!(save[fd][0]))
			bytes_read = read(fd, save[fd], BUFFER_SIZE);
		if (bytes_read > 0)
			line = ft_join(line, save[fd], ft_strlen(save[fd]), 0);
		if (bytes_read <= 0 || (line && line[ft_strlen(line) - 1] == 10))
			break ;
	}
	return (line);
}
