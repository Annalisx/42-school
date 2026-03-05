/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:16:21 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:20:10 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void func(void* content)
{
    if (content)
        free(content);
}*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int main()
{
    printf("ft_lstdelone\n");
    char*str = ft_strdup("fanculo");
    t_list *head = ft_lstnew(str);
    printf("%s \n",head->content);
    ft_lstdelone(head,&func);
    head = NULL;
} */