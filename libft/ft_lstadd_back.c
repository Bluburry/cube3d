/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:50:35 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/11 13:50:37 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast((*lst));
		temp->next = new;
	}
}

// #include <stdio.h>
// void	print_list(t_list *head)
// {
// 	if (!head)
// 		return ;
// 	while (head)
// 	{
// 		printf("Element->content: %s\n", (char*)head->content);
// 		head = head->next;
// 	}
// }
// int		main(void)
// {
// 	char	str1[] = "First Element";
// 	char	str2[] = "Second Element";
// 	char	str3[] = "Third Element";
// 	char	str4[] = "NewAndLastElement";
//
// 	t_list	*elem1;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	t_list	*elem4;	
//
// 	if(!(elem1 = malloc(sizeof(t_list))))
// 		return (0);
// 	if(!(elem2 = malloc(sizeof(t_list))))
// 		return (0);
// 	if(!(elem3 = malloc(sizeof(t_list))))
// 		return (0);
// 	if(!(elem4 = malloc(sizeof(t_list))))
// 		return (0);
//
// 	elem1->content = (void *)str1;
// 	elem1->next = elem2;
// 	elem2->content = (void *)str2;
// 	elem2->next = elem3;
// 	elem3->content = (void *)str3;	
// 	elem3->next = NULL;	
//
// 	elem4->content = (void *)str4;
// 	elem4->next = NULL;
//	
// 	print_list(elem1);
// 	printf("\n");
// 	ft_lstadd_back(&elem1, elem4);	
// 	printf("\n");
// 	print_list(elem1);
// }