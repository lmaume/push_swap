/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:29 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 17:54:01 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	swap(t_stack **pos)
{
	int		mem;
	t_stack	*temp;
	t_stack	*start;

	mem = 0;
	temp = (*pos)->next;
	start = (*pos)->preview;
	if (is_empty(&(*pos)) == 1)
		return ;
	if (ft_lstsize(*pos) == 2)
	{
		mem = temp->data;
		temp->data = (*pos)->data;
		(*pos)->data = mem;
		return ;
	}
	(*pos)->next = (*pos)->next->next;
	(*pos)->next->preview = (*pos);
	(*pos)->preview = temp;
	temp->next = (*pos);
	temp->preview = start;
	(*pos) = temp;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
