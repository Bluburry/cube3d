/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:48:34 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 11:48:35 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	c;
//     c = '1';
// 	printf("Return: %d\n", isprint(c));
//     c = '\t';
// 	printf("Return: %d\n", isprint(c));
//     c = 'a';
// 	printf("Return: %d\n", isprint(c));

//     c = '1';
// 	printf("Return: %d\n", ft_isprint(c));
//     c = '\t';
// 	printf("Return: %d\n", ft_isprint(c));
//     c = '\n';
// 	printf("Return: %d\n", ft_isprint(c));
// }