/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:16:48 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 18:54:15 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/* void func(void *node)
{
    printf("%s\n",(char*)node);
}
int main()
{
    printf("ft_lstiter\n");
    t_list *head = ft_lstnew("ciao");
    head->next = ft_lstnew("come");
    head->next->next = ft_lstnew("stai");
    ft_lstiter(head, &func);
} */