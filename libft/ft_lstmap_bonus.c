/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: smallet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 17:26:30 by smallet      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:57:25 by smallet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*temp;

	del = 0;
	new_lst = NULL;
	temp = NULL;
	if (!lst || !f)
		return (NULL);
	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_lst = temp;
	while (lst != NULL)
	{
		temp->content = (f)(lst->content);
		lst = lst->next;
		if (lst)
		{
			if (!(temp->next = (t_list *)malloc(sizeof(t_list))))
				return (NULL);
			temp = temp->next;
		}
	}
	temp->next = NULL;
	return (new_lst);
}
