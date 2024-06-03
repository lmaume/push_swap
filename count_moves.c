/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:39:33 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/03 14:31:41 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number_of_moves(t_stack *it, t_stack **stacka, t_stack **stackb)
{
	int	type;

	type = compare_datasize(it->data, stackb);
	if (type == 0)
		return (moves_for_new_bigger_in_b(it, stacka, stackb));
	else if (type == 1)
		return (moves_for_new_smaller_in_b(it, stacka, stackb));
	else
		return (moves_for_insertion_in_b(it, stacka, stackb));
}

int	count_moves_to_the_top(t_stack *it, t_stack **stack)
{
	int	count;

	count = 0;
	if (get_index(stack, it->data) > ft_lstsize((*stack)) / 2)
		count += ft_lstsize((*stack)) - get_index(stack, it->data);
	else
		count += get_index(stack, it->data);
	return (count);
}

//? +1 for the push
int	moves_for_new_bigger_in_b(t_stack *it, t_stack **stacka, t_stack **stackb)
{
	int	count;

	count = count_moves_to_the_top(it, stacka);
	count += count_moves_to_the_top(find_bloc_from_data(stackb, \
								find_the_stronk(stackb)), stackb);
	count += 1;
	return (count);
}

//? +2 for the push, and the rotate
int	moves_for_new_smaller_in_b(t_stack *it, t_stack **stacka, t_stack **stackb)
{
	int	count;

	count = count_moves_to_the_top(it, stacka);
	count += count_moves_to_the_top(find_bloc_from_data(stackb, \
								find_the_stronk(stackb)), stackb);
	count += 2;
	return (count);
}

//? +1 for the push
int	moves_for_insertion_in_b(t_stack *it, t_stack **stacka, t_stack **stackb)
{
	int	count;

	count = count_moves_to_the_top(it, stacka);
	count += count_moves_to_the_top(find_bloc_from_data(stackb, \
						search_value(it->data, stackb)), stackb);
	count += 1;
	return (count);
}
