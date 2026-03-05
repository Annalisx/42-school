/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastald <acastald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:59:16 by acastald          #+#    #+#             */
/*   Updated: 2025/12/20 16:16:19 by acastald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void    ft_baby(unsigned int i, char *str)
{
    write(1, &str[i], 1);    
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/* int main()
{
    char *s = "bubi";
    void (*baby)(unsigned int, char*) = ft_baby;
    ft_striteri(s, baby);
} */
