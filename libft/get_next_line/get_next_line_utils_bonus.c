/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:18:17 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/16 13:18:18 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*ptrs;
	int		i;
	int		j;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	ptrs = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff)) + 1);
	if (!ptrs)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[j])
		ptrs[i++] = stash[j++];
	j = 0;
	while (buff[j])
		ptrs[i++] = buff[j++];
	ptrs[i] = '\0';
	free(stash);
	return (ptrs);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}
