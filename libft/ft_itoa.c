/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:37:26 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 17:37:28 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		i;

	len = count_digits(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 1;
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		i = -1;
	}
	else if (n == 0)
		str[len] = '0';
	while (n != 0)
	{
		str[len] = ((n % 10) * i) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*ptr;

// 	ptr = ft_itoa(-500);
// 	printf("FT_ITOA: %s", ptr);
// }