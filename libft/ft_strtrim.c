/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:48:59 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/07 11:49:00 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptrs;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	ptrs = (char *)malloc(end - start + 2);
	if (!ptrs)
		return (NULL);
	ft_strlcpy(ptrs, &s1[start], end - start + 2);
	return (ptrs);
}
// #include <stdio.h>
// int	main(void)
// {
// 	const char	s1[] = "SocorrammesubiemonibusemmarrocoS";
// 	const char	set[] = "Socorra";
// 	char	*prt;

// 	prt = ft_strtrim(s1, set);
// 	printf("String: %s\n", prt);
// }