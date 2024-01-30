/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:26:26 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 12:26:27 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
// #include <stdio.h>
// int	main(void)
// {
//     int c;
//     c = 'A';
// 	printf("Return: %c\n", ft_tolower(c));
// }