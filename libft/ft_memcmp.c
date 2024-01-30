/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:07:06 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/04 20:07:07 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;
	size_t				i;

	i = 0;
	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	while (n > i)
	{	
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	s1[] = "string";
// 	char	s2[] = "st4ing";
// 	int	n = 5;
// 	printf("Result: %d\n", ft_memcmp(s1, s2, n));
// 	printf("Result: %d\n", memcmp(s1, s2, n));
// }