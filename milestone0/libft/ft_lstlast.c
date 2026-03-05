/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:17:05 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:23:04 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

/* int main()
{
    t_list *head = ft_lstnew("head");
    t_list *tmp = head;
	for (size_t n = 0; n < 10; n ++)
	{
		tmp->next = ft_lstnew("o");
		// printf(">> tmp->content  %s >> n %lu\n",tmp->next->content,n);
		tmp = tmp->next;
	}
    t_list *lst_node = ft_lstlast(head);
    printf("lst node : %s\n",lst_node->content);
} */