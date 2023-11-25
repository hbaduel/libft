/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:52:17 by hbaduel           #+#    #+#             */
/*   Updated: 2023/11/25 11:12:15 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!del || !lst || !lst[0])
		return ;
	while (lst != 0 && lst[0] != 0)
	{
		temp = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = temp;
	}
}
