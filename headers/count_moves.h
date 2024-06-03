/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:29:30 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 18:40:23 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_MOVES_H
# define COUNT_MOVES_H

# include "list.h"

t_stack	*find_bloc_from_data(t_stack **stack, int data);
int		get_index_of_bloc(t_stack **stack, t_stack *bloc);

int		compare_datasize(int data, t_stack **stack);
int		search_value(int data, t_stack **stack);

t_stack	*find_best_move(t_stack **stacka, t_stack **stackb);
int		count_number_of_moves(t_stack *it, t_stack **stacka, t_stack **stackb);
int		count_moves_to_the_top(t_stack *it, t_stack **stack);

int		moves_for_new_bigger_in_b(t_stack *it, t_stack **stacka, \
		t_stack **stackb);
int		moves_for_new_smaller_in_b(t_stack *it, t_stack **stacka, \
		t_stack **stackb);
int		moves_for_insertion_in_b(t_stack *it, t_stack **stacka, \
		t_stack **stackb);

#endif