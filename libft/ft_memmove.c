/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:08:46 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/04 20:08:50 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "Source";
// 	char	dest[] = "Destination";

// 	printf("Dest: %s\n", dest);
// 	ft_memmove(dest, src, 6);
// 	printf("Dest: %s\n", dest);
// 	memmove(dest, src, 5);
// 	printf("Dest: %s\n", dest);
// }