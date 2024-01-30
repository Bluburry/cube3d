/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:33:45 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 11:33:47 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	c;
//     c = '1';
// 	printf("Return: %d\n", isascii(c));
//     c = 0x88;
// 	printf("Return: %d\n", isascii(c));
//     c = 'a';
// 	printf("Return: %d\n", isascii(c));
//     c = '1';
// 	printf("Return: %d\n", ft_isascii(c));
//     c = 0x88;
// 	printf("Return: %d\n", ft_isascii(c));
//     c = 'a';
// 	printf("Return: %d\n", ft_isascii(c));
// }