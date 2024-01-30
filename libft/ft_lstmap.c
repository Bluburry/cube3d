/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:36:26 by jegger-s          #+#    #+#             */
/*   Updated: 2022/11/11 18:36:27 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	begin = 0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst->next;
	}
	return (begin);
}

// #include <stdio.h>
// void *f(void *nome)
// {
// 	char *a = "-- Olah --";
// 	return ((char *)ft_strlcpy(nome, a, ft_strlen(a) + 1));
// }
//
// void	del(void *este)
// {
// 	free (este);
// }
//
// int		main()
// {
// 	t_list *head;
// 	t_list *um;
// 	t_list *dois;
// 	t_list *tres;
//
//
// 	char *c1 = ft_strdup("-- Adeus Um --");
// 	char *c2 = ft_strdup("-- Adeus Dois --");
// 	char *c3 = ft_strdup("-- Adeus Tres --");
// 	char *c4 = ft_strdup("-- Adeus Quatro --");
//
// 	head = ft_lstnew(c1);
// 	um = ft_lstnew(c2);
// 	dois = ft_lstnew(c3);
// 	tres = ft_lstnew(c4);
//
// 	ft_lstadd_back(&head, um);
// 	ft_lstadd_back(&head, dois);
// 	ft_lstadd_back(&head, tres);
//
// 	printf("\n%s\n%s\n%s\n%s\n", (char *)head->content, 
								//(char *)head->next->content,
// 								//(char *)head->next->next->content,
// 								//(char *)head->next->next->next->content);
//
// 	t_list *nova = ft_lstmap(head, f, del);
//
// 	printf("\n%s\n%s\n%s\n%s\n", (char *)head->content, 
								//(char *)head->next->content,
// 								//(char *)head->next->next->content,
// 								//(char *)head->next->next->next->content);
//
//
// 	nova->content = "-- Bahh --";
// 	nova->next->content = "-- Asd --";
// 	nova->next->next->content = "-- Dswh --";
// 	nova->next->next->next->content = "-- Wrq --";
// 	printf("\n%s%s%s%s\n", (char *)nova->content, 
							//(char *)nova->next->content,
// 							(char *)nova->next->next->content,
// 							(char *)nova->next->next->next->content);
//
//
// 	// Isto é só para criar uma nova lista com o 
	//mesmo tamanho da original (head). Não
// 	// é para copiar o -content e isso.
// }
