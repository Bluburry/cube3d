/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:36:57 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:36:58 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	*get_to_map(int fd)
{
	char	*ln;

	if (fd < 0)
		return (NULL);
	while (1)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
		if (ln[0] != 'N' && ln[0] != 'S' && \
			ln[0] != 'W' && ln[0] != 'E' && \
			ln[0] != 'F' && ln[0] != 'C' && \
			ln[0] != '\n')
		{
			if (ft_strchr(ln, '1'))
				return (ln);
		}
		free(ln);
	}
	return (NULL);
}

int	get_map_rows(char *file)
{
	auto char *ln;
	auto int fd = open(file, O_RDONLY), i = 1, j, cnt;
	ln = get_to_map(fd);
	if (!ln)
		return (i);
	free(ln);
	while (1)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
		j = -1;
		cnt = 0;
		while (!cnt && ln[++j])
			if (ft_strchr("NSWE10", ln[j]))
				cnt = 1;
		if (cnt)
			i++;
		free(ln);
	}
	close(fd);
	return (i);
}

char	**get_map(char *file, int rows)
{
	auto int fd = open(file, O_RDONLY), i = -1, j, cnt;
	auto char **mp = (char **) malloc((rows + 1) * \
		(sizeof(char *))), *ln = get_to_map(fd);
	if (!mp || !ln)
		return (clear_matrix(mp, rows + 1), NULL);
	while (1)
	{
		j = -1;
		cnt = 0;
		while (!cnt && ln[++j])
			if (ft_strchr("NSWE10", ln[j]))
				cnt = 1;
		if (cnt)
			mp[++i] = ln;
		else
			free(ln);
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
	}
	mp[rows] = 0;
	return (close(fd), mp);
}
