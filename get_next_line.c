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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE];
	char		*line;
	int			bytes_read;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!(*save))
			bytes_read = read(fd, save, BUFFER_SIZE);
		if (bytes_read > 0)
			line = ft_join(line, save, ft_strlen(save), 0);
		if (bytes_read <= 0 || (line && line[ft_strlen(line) - 1] == 10))
			break ;
	}
	return (line);
}
