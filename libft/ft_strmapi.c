/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:20:49 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 18:20:49 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptrs;
	int		i;

	if (!s || !f)
		return (NULL);
	ptrs = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptrs)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptrs[i] = f(i, s[i]);
		i++;
	}
	ptrs[i] = '\0';
	return (ptrs);
}

// #include <stdio.h>
// char my_func(unsigned int i, char str)
// {
// 	printf("My inner function: index = %d and %c\n", i, str);
// 	return (str);
// }
// int	main(void)
// {
// 	char	string[] = "This is a new string ok?";
// 	char	*ptrs;
// 	ptrs = ft_strmapi(string, my_func);
// 	printf("Result: %s\n", ptrs);
// }