/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:25:52 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 12:25:53 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}
// #include <stdio.h>
// int	main(void)
// {   
//     int c;

//     c = '1';
// 	printf("Return: %c\n", ft_toupper(c));
// }