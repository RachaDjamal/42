/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lsrclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:44:39 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:01:57 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		ft_lstdelone(temp, &(*del));
		temp = temp->next;
	}
	*lst = NULL;
}
