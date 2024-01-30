/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:51 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/08 16:12:55 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	if (nptr[i] < '0' && nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10 + (nptr[i] - '0'));
		i++;
	}
	return (nb * neg);
}
// #include <stdio.h>
// int	main()
// {
// 	char	str1[] = "\e475";

// 	printf("String : %s\n", str1);
// 	printf("Ft_atoi: %d\n", ft_atoi(str1));
// 	printf("String : %s\n", str1);
// 	printf("Atoi   : %d\n", atoi(str1));
// 	return (0);
// }