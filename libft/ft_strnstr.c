/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:24:04 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/04 21:24:05 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((little[j] == big[i + j]) && (j + i < len))
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <bsd/string.h>
// int	main(void)
// {
// 	const char	big[] = "Foo Bar Baz";
// 	const char	little[] = "oo";
// 	char	*prt;

// 	prt = ft_strnstr(big, little, 0);
// 	printf("String: %s\n", prt);
// }