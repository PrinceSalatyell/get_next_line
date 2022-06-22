/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 06:41:25 by marvin            #+#    #+#             */
/*   Updated: 2022/03/09 06:41:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *line, char *save, int size_save, int k)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char) * ft_strlen(line) + size_save + 1);
	if (!temp)
		return (NULL);
	while (line && line[i])
		temp[j++] = line[i++];
	i = 0;
	while (save && save[i])
	{
		if (i < size_save)
			temp[j++] = save[i];
		else
			save[k++] = save[i];
		save[i++] = 0;
	}
	temp[j] = 0;
	if (line)
		free(line);
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	l;

	l = 0;
	while (str && *str)
	{
		if (*str == 10)
			return (l + 1);
		l++;
		str++;
	}
	return (l);
}
