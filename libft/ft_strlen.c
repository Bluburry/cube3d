/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:54:36 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 11:54:37 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("Count: %d\n", ft_strlen("USED16CHARACTERS"));

// 	printf("Count: %d\n", strlen("USED16CHARACTERS"));
// }