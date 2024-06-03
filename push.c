/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:20 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 17:52:49 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	b_is_empty(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*start_a;
	t_stack	*start_b;

	temp = (*a)->next->next;
	start_a = (*a);
	start_b = (*b);
	(*a) = (*a)->next;
	start_b->next = (*a);
	(*a)->next = NULL;
	(*a)->preview = start_b;
	start_a->next = temp;
	temp->preview = start_a;
}

static
void	b_is_not_empty(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*start_a;
	t_stack	*start_b;

	temp = (*a)->next->next;
	start_a = (*a);
	start_b = (*b);
	(*b) = (*b)->next;
	(*a) = (*a)->next;
	start_b->next = (*a);
	(*a)->next = (*b);
	(*b)->preview = (*a);
	(*a)->preview = start_b;
	start_a->next = temp;
	temp->preview = start_a;
}

static
void	push(t_stack **a, t_stack **b)
{
	t_stack	*start_a;
	t_stack	*start_b;

	start_a = (*a);
	start_b = (*b);
	if (is_empty(&(*a)) == 1)
		return ;
	if ((is_empty(&(*b)) == 1) && ((*a)->next->next != NULL))
		b_is_empty(&start_a, &start_b);
	else if ((is_empty(&(*b)) == 0) && ((*a)->next->next != NULL))
		b_is_not_empty(&start_a, &start_b);
	else if ((is_empty(&(*b)) == 0) && ((*a)->next->next == NULL))
		b_full_a_onedata(&start_a, &start_b);
	else
		return ;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
