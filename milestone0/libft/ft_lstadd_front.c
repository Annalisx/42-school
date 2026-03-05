/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:12:09 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:22:41 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int main()
{
    t_list *list = ft_lstnew("string");
    t_list *new  = ft_lstnew("new_string");
    ft_lstadd_front(&list,new);
    printf("list->content %s\n",list->content);
    printf("list->next->content %s\n",list->next->content);
} */