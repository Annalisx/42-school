/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:17:21 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:23:49 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void *func(void *p)
{	
	char	*result;

	if (p)
		result = ft_strdup(p);
	else 
		return (NULL);
	return ((void *)result);
}

void del(void *p)
{
	if (p)
		free(p);
} */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* int main()
{	
	char strhead[] = "head";
	char strn2[] = "n2";
	char strn3[] = "n3";
	t_list *head = ft_lstnew(strhead);
	t_list *n2 = ft_lstnew(strn2);
	t_list *n3 = ft_lstnew(strn3);
	head->next = n2;
	n2->next = n3;
	t_list *lstm = ft_lstmap(head,&func,&del); 
} */