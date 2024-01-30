/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:07:34 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/04 18:07:35 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{	
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const	char str[] = "Something new";
// 	char	*prts;
// 	char	*prts2;

// 	prts = strrchr(str, '\0');
// 	prts2 = ft_strrchr(str, '\0');
// 	printf("   String: %s\n", prts);
// 	printf("Ft String: %s\n", prts2);
// }