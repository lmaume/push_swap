/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:42:44 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 18:45:00 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_best_move(t_stack **stacka, t_stack **stackb)
{
	int		count_moves;
	t_stack	*good_choice;
	t_stack	*it;

	it = (*stacka)->next;
	count_moves = count_number_of_moves(it, stacka, stackb);
	good_choice = (*stacka)->next;
	while (it != NULL)
	{
		if (count_moves > count_number_of_moves(it, stacka, stackb))
		{
			count_moves = count_number_of_moves(it, stacka, stackb);
			good_choice = it;
		}
		it = it->next;
	}
	return (good_choice);
}

int	compare_datasize(int data, t_stack **stack)
{
	int	big;
	int	small;
	int	between;

	big = 0;
	small = 1;
	between = 2;
	if (data > find_the_stronk(&(*stack)->next))
		return (big);
	if (data < find_the_weak(&(*stack)->next))
		return (small);
	else
		return (between);
}

int	search_value(int data, t_stack **stackb)
{
	t_stack	*bloc;
	int		value;

	bloc = (*stackb)->next;
	value = find_the_stronk(&(*stackb)->next);
	while (bloc != NULL)
	{
		if (bloc->data > data && bloc->data < value)
			value = bloc->data;
		bloc = bloc->next;
	}
	return (value);
}
