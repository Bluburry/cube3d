/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:22 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 14:56:23 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptrs;
	unsigned char		*ptrd;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "Source";
// 	char	dest[] = "This is a new string";

// 	ft_memcpy(dest, src, 6);
// 	//memcpy(dest, src, 6);
// 	puts(dest);
// 	//printf("%s", src);
// }