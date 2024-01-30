/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:41:16 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 18:41:17 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const	char str[] = "Where is the Z anyway?";
// 	char	*prts;
// 	char	*prts2;

// 	prts = strchr(str, ' ');
// 	prts2 = ft_strchr(str, ' ');
// 	printf("String: %s\n", prts);
// 	printf("String: %s", prts2);
// }