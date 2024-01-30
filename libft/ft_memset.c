/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:45:07 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 13:45:12 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	i = 0;
	ptrs = (unsigned char *)s;
	while (i < n)
	{
		ptrs[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "New String";

// 	//memset(str, '-', 4);
// 	ft_memset(str, '-', 5);
// 	puts(str);

//     return (0);
// }