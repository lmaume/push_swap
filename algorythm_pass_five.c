/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm_pass_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:03 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/03 12:00:25 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_stack **stacka, t_stack **stackb)
{
	pb(stacka, stackb);
	pb(stacka, stackb);
	if (is_sorted(stackb) == 0)
		sb(&(*stackb)->next);
	while (ft_lstsize(*stacka) > 4)
	{
		to_the_top(find_best_move(stacka, stackb), &(*stacka), STACK_A);
		make_a_move(stacka, stackb);
	}
	sort_three(stacka);
	while ((*stackb)->next->data != find_the_stronk(&(*stackb)->next))
		go_up_or_down(&(*stackb)->next, \
		find_the_stronk(&(*stackb)->next), STACK_B);
	put_back_to_stacka(stacka, stackb);
}

void	aff_all(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *stacka;
	tmpb = *stackb;
	ft_printf("____A____ ____B____\n");
	while (tmpa || tmpb)
	{
		if (tmpa)
		{
			ft_printf("[%d]\t", tmpa->data);
			tmpa = tmpa->next;
		}
		else
			ft_printf("[NULL]\t");
		if (tmpb)
		{
			ft_printf(" |    [%d]\n", tmpb->data);
			tmpb = tmpb->next;
		}
		else
			ft_printf(" |    [NULL]\n");
	}
	ft_printf("____A____|____B____\n");
}

void	put_back_to_stacka(t_stack **stacka, t_stack **stackb)
{	
	if (ft_lstlast((*stacka))->data > find_the_stronk(stackb))
		rra(&(*stacka)->next);
	while (is_empty(stackb) != 1)
	{	
		if (ft_lstlast(*stacka)->data > (*stackb)->next->data \
		&& ft_lstlast(*stacka)->data < (*stacka)->next->data)
			rra(&(*stacka)->next);
		else
			pa(stacka, stackb);
	}
	to_the_top(find_bloc_from_data(stacka, \
	find_the_weak(&(*stacka)->next)), stacka, STACK_A);
}

void	to_the_top(t_stack *it, t_stack **stack, int type)
{
	if (it == NULL)
		return ;
	while (it != (*stack)->next)
		go_up_or_down(&(*stack)->next, it->data, type);
}

void	make_a_move(t_stack **stacka, t_stack **stackb)
{
	if (compare_datasize(find_best_move(stacka, stackb)->data, stackb) == 0)
	{
		while ((*stackb)->next->data != find_the_stronk(&(*stackb)->next))
			go_up_or_down(&(*stackb)->next, \
			find_the_stronk(&(*stackb)->next), STACK_B);
		pb(stacka, stackb);
	}	
	else if (compare_datasize(find_best_move(stacka, stackb)->data, \
	stackb) == 1)
	{
		while (find_the_stronk(&(*stackb)->next) != (*stackb)->next->data)
			go_up_or_down(&(*stackb)->next, \
			find_the_stronk(&(*stackb)->next), STACK_B);
		pb(stacka, stackb);
		rb(&(*stackb)->next);
	}
	else if (compare_datasize(find_best_move(stacka, stackb)->data, \
	stackb) == 2)
	{
		while (ft_lstlast(*stackb)->data != \
		search_value((*stacka)->next->data, stackb))
			go_up_or_down(&(*stackb)->next, \
			search_value((*stacka)->next->data, stackb), STACK_B);
		pb(stacka, stackb);
	}
}
