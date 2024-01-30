/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:42:03 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/03 14:42:07 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptrs[i] = 0;
		i++;
	}
}
// #include <strings.h>
// #include <stdio.h>
// int main(void)
// {
// 	char	string[] = "New String";

// 	ft_bzero(string, 1);
// 	//bzero(string, 4);
// 	//puts(string);
// }