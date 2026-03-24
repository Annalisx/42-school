/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:18:23 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:24:00 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	temp = lst;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/* int main()
{
    t_list *node = ft_lstnew("ok");
    node->next = ft_lstnew("ok2");
    node->next->next = ft_lstnew("ok3");
    node->next->next->next = ft_lstnew("ok4");
    int size = ft_lstsize(node);
    printf("lst size %i\n",size);
} */