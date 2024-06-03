/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:47:33 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 13:59:20 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	reverse_rotate(t_stack **head)
{
	t_stack	*new_head;
	t_stack	*end_list;
	t_stack	*start;

	new_head = ft_lstlast(*head);
	end_list = new_head->preview;
	start = (*head)->preview;
	if (is_empty(&(*head)) == 1)
		return ;
	end_list->next = NULL;
	(*head)->preview = new_head;
	new_head->next = (*head);
	new_head->preview = start;
	(*head) = new_head;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
