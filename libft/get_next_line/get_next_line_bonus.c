/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:55:43 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/15 14:55:44 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*set_stash_to_rest(char *stash)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_line = malloc(sizeof(char) * (ft_strlen(stash) - i) + 1);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_line[j++] = stash[i++];
	new_line[j] = '\0';
	free(stash);
	return (new_line);
}

char	*get_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[j] && stash[j] != '\n')
		line[i++] = stash[j++];
	if (stash[j] == '\n')
		line[i++] = stash[j];
	line[i] = '\0';
	return (line);
}

char	*join_buff_stash(int fd, char *stash)
{	
	char	*buff;
	size_t	len;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = 1;
	while ((!ft_strchr(stash, '\n')) && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if ((int)len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = join_buff_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = set_stash_to_rest(stash[fd]);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int    main(void)
// {
//     char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
//
// 	fd1 = open("texto.txt", O_RDONLY);
// 	fd2 = open("texto2.txt", O_RDONLY);
// 	fd3 = open("texto3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 4)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }