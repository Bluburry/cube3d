/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:30:39 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 14:30:40 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *str, char sep)
{
	int	word;
	int	flag;

	word = 0;
	flag = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			flag = 1;
			word++;
		}
		else if (*str == sep)
			flag = 0;
		str++;
	}
	return (word);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**ptrs;	

	ptrs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !ptrs)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			ptrs[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	ptrs[j] = 0;
	return (ptrs);
}
#include <stdio.h>
int	main(void)
{
	char	str[] = "Teste 1-Teste 2-Kramp 2";
	char	**ptr;
	int	i;	

	ptr = ft_split(str, '-');

	i = 0;
	while (ptr[i])
	{
		printf("Return: %s\n", ptr[i]);
		i++;
	}
}