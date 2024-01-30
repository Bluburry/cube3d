/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:24:44 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 11:24:45 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		totallength;
	char	*ptrs;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	totallength = ft_strlen(s1) + ft_strlen(s2);
	ptrs = (char *)malloc(sizeof(char) * totallength + 1);
	if (!ptrs)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptrs[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ptrs[i] = *s2;
		i++;
		s2++;
	}
	ptrs[i] = '\0';
	return (ptrs);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	string[] = "New";
// 	char	string2[] = "String";

// 	printf("Return: %s\n", ft_strjoin(string, string2));
// }