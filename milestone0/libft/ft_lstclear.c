/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:12:27 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:22:31 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void del(void *content)
{
    if(content)
        free(content);
} */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		del(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

/* int main()
{
    printf("ft_lstclear\n");
    char*str1 = ft_strdup("ciao");
    char*str2 = ft_strdup("come");
    char*str3 = ft_strdup("stai");
    t_list *head = ft_lstnew(str1);
    head->next = ft_lstnew(str2);
    head->next->next = ft_lstnew(str3);
    t_list *tmp = head;
    while(tmp)
    {
        printf("%s \n",tmp->content);
        tmp = tmp->next;
    }
    ft_lstclear(&head,&del);
    if(head == NULL)
        printf("Lista svuotata correttamente\n");
} */