/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:27:23 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/09 20:27:25 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_errors(char *str)
{
	printf("Error\n");
	if (str)
		printf("%s", str);
	if (!str)
		return ;
	auto int i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != '\n')
		printf("\n");
}
