/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:40 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 14:00:04 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	rotate(t_stack **pos)
{
	t_stack	*start;
	t_stack	*temp;
	t_stack	*last;

	start = (*pos)->preview;
	temp = (*pos);
	last = ft_lstlast((*pos));
	if (is_empty(&(*pos)) == 1)
		return ;
	(*pos) = (*pos)->next;
	(*pos)->preview = start;
	last->next = temp;
	temp->next = NULL;
	temp->preview = last;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
