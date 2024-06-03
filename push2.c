/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:41:01 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 13:56:18 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_full_a_onedata(t_stack **a, t_stack **b)
{
	t_stack	*start_a;
	t_stack	*start_b;

	start_a = (*a);
	start_b = (*b);
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	start_b->next = (*a);
	(*a)->preview = start_b;
	(*b)->preview = (*a);
	(*a)->next = (*b);
	start_a->next = NULL;
}
