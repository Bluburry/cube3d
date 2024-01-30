/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:11:19 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 12:11:20 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	j = ft_strlen(dst);
	while (src[i] != '\0' && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	//char	src[] = "String";
// 	//char	dest[] = "This is a ";
// 	// char	src2[] = "String";
// 	// char	dest2[] = "This is a ";
// 	char	dest5[15];
//
// 	dest5[10] = 'a';
//
// 	//printf("Dest: %s\n", dest);
// 	//printf("Return - strlcat: %zu\n", strlcat(dest, src, 0));
// 	//printf("Dest: %s\n", dest);
// 	//printf("\n");
// 	//printf("Dest: %s\n", dest2);
// 	//printf("Return - ft_strlcat: %zu\n", ft_strlcat(dest2, src2, 0));
// 	//printf("Dest: %s\n", dest2);
// }