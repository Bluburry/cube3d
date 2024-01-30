/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:59:11 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 18:59:12 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// void	my_func(unsigned int i, char *str)
// {
// 	printf("My inner function: index = %d and %s\n", i, str);
// }
// int	main(void)
// {
// 	char	string[] = "String";
// 	ft_striteri(string, my_func);
// }