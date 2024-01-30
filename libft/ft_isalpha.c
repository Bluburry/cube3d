/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:47:51 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 10:47:56 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (0);
	return (1);
}
// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	c;
//     c = 'a';
// 	printf("Return: %d\n", isalpha(c));
//     c = 'A';
// 	printf("Return: %d\n", isalpha(c));
//     c = '1';
// 	printf("Return: %d\n", isalpha(c));
//     c = 'a';
// 	printf("Return: %d\n", ft_isalpha(c));
//     c = 'A';
// 	printf("Return: %d\n", ft_isalpha(c));
//     c = '1';
// 	printf("Return: %d\n", ft_isalpha(c));
// }