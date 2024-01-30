/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:59:22 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/04 18:59:23 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (n > 0)
	{		
		if (*str == character)
			return (str);
		n--;
		str++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	int	c;
// 	char	str[] = "I choose you";
// 	char	*ptrs;
// 	char	*ptrs2;
// 	c = 'c';
// 	ptrs = memchr(str, c, sizeof(str));
// 	//ptrs2 = ft_memchr(str, c, sizeof(str));
//
// 	ptrs2 = ft_memchr("bonjourno", 'n', 2);
//
// 	printf("String: %s|\n", ptrs);
// 	printf("String: %s|\n", ptrs2);	
// }