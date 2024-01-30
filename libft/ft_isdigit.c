/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:58:11 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 10:58:14 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {	
// 	int	c;
//     c = '1';
// 	printf("Return: %d\n", isdigit(c));
//     c = '9';
// 	printf("Return: %d\n", isdigit(c));
//     c = 'a';
// 	printf("Return: %d\n", isdigit(c));

//     c = '1';
// 	printf("Return: %d\n", ft_isdigit(c));
//     c = '9';
// 	printf("Return: %d\n", ft_isdigit(c));
//     c = 'a';
// 	printf("Return: %d\n", ft_isdigit(c));
// }