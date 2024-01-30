/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:07:14 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 11:07:15 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')
		&& (c < 48 || c > 57))
		return (0);
	return (1);
}
// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	c;
//     c = '4';
// 	printf("Return: %d\n", isalnum(c));
//     c = '$';
// 	printf("Return: %d\n", isalnum(c));
//     c = 'A';
// 	printf("Return: %d\n", isalnum(c));
//     c = '1';
// 	printf("Return: %d\n", ft_isalnum(c));
//     c = '$';
// 	printf("Return: %d\n", ft_isalnum(c));
//     c = 'a';
// 	printf("Return: %d\n", ft_isalnum(c));
// }