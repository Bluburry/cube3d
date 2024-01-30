/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:38:38 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 10:38:41 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptrs;
	char	*string;
	int		i;

	i = 0;
	string = (char *)s;
	ptrs = (char *)malloc(sizeof(char) * ft_strlen(string) + 1);
	if (!ptrs)
		return (NULL);
	while (string[i])
	{
		ptrs[i] = string[i];
		i++;
	}
	ptrs[i] = '\0';
	return (ptrs);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	string[] = "String";
// 	//char	string2[] = "String";
// 	printf("Return: %s\n", ft_strdup(string));
// 	//printf("Return: %s", strdup(string2));
// }
