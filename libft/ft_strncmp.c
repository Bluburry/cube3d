/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:15:16 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 13:15:17 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	ptrs1[] = "abc2d";
// 	char	ptrs2[] = "abcd";
// 	printf("Return: %d\n", ft_strncmp(ptrs1, ptrs2, 3));
// 	printf("Return: %d", strncmp(ptrs1, ptrs2, 3));	
// }