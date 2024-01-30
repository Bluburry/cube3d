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
	while ((!gnl_strchr(stash, '\n')) && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if ((int)len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		stash = gnl_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = join_buff_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = set_stash_to_rest(stash);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptrs;
// 	int		fd;
// 	int		counter;

// 	counter = 1;
// 	fd = open("test.txt", O_RDONLY);	
// 	while (counter)
// 	{
// 		if (fd == -1)
// 			printf("Enable to open file or file does not exist.\n");
// 		else if (fd == 0)
// 			printf("Nothing to read.\n");
// 		else
// 		{
// 			ptrs = get_next_line(fd);
// 			if (!ptrs)
// 			{
// 				printf("\n-END-");	
// 				counter = 0;
// 			}
// 			else
// 				printf("- %s", ptrs);
// 		}		
// 	}
// 	close(fd);
// }