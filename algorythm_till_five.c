/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_till_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:38:11 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 13:54:02 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stacka)
{
	if (is_sorted(stacka) == 0)
		return ;
	if (((*stacka)->next->data > (*stacka)->next->next->data \
		&& (*stacka)->next->data > (*stacka)->next->next->next->data) \
		&& is_sorted(stacka) == 1)
		ra(&(*stacka)->next);
	if (((*stacka)->next->data > (*stacka)->next->next->data \
		&& (*stacka)->next->data < (*stacka)->next->next->next->data) \
		&& is_sorted(stacka) == 1)
		sa(&(*stacka)->next);
	if (((*stacka)->next->data < (*stacka)->next->next->data) \
		&& is_sorted(stacka) == 1)
		rra(&(*stacka)->next);
	if (((*stacka)->next->data > (*stacka)->next->next->data) \
		&& is_sorted(stacka) == 1)
		sa(&(*stacka)->next);
}

void	sort_four(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmpa;

	tmpa = (*stacka);
	if (is_sorted(&tmpa) == 0)
		return ;
	while (tmpa->next->data != find_the_weak(&tmpa->next))
		go_up_or_down(&tmpa->next, find_the_weak(&tmpa->next), STACK_A);
	pb(stacka, stackb);
	sort_three(stacka);
	pa(stacka, stackb);
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmpa;

	tmpa = (*stacka);
	if (is_sorted(&tmpa) == 0)
		return ;
	while (tmpa->next->data != find_the_weak(&tmpa->next))
		go_up_or_down(&tmpa->next, find_the_weak(&tmpa->next), STACK_A);
	pb(stacka, stackb);
	sort_four(stacka, stackb);
	pa(stacka, stackb);
}
