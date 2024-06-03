/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:00 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/03 10:53:20 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "count_moves.h"

//? ## VERIFS ##

int		ft_isok(char *arg);
int		is_empty(t_stack **stack);
int		is_sorted(t_stack **stacka);
int		is_double(t_stack **stack);
bool	is_valid(char *str);

//? ## UTILS ##

void	make_a_move(t_stack **stacka, t_stack **stackb);
void	go_up_or_down(t_stack **stack, int data, int type);
void	to_the_top(t_stack *it, t_stack **stack, int type);
void	put_back_to_stacka(t_stack **stacka, t_stack **stackb);

void	destroyer_of_worlds(t_stack	*stack);

#endif