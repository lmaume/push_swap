/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:32:55 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 18:02:54 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*bloc;

	bloc = ft_calloc(sizeof(t_stack), 1);
	bloc->data = content;
	return (bloc);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, t_stack *newbloc)
{
	newbloc->next = (*lst);
	(*lst)->preview = newbloc;
}

void	ft_lstadd_back(t_stack **lst, t_stack *newbloc)
{
	t_stack	*bloc;

	bloc = (*lst);
	while (bloc->next != NULL)
	{
		bloc = bloc->next;
	}
	bloc->next = newbloc;
	newbloc->next = NULL;
	newbloc->preview = bloc;
}
