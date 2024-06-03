/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:46:46 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/31 18:57:11 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_A 1
# define STACK_B 2

# include "printf/libft/libft.h"
# include "printf/libftprintf.h"
# include "headers/operations.h"
# include "headers/utils.h"

# include <stdlib.h>
# include <unistd.h>

//? ## ALGORYTHME ##

void	wich_algo(t_stack **stacka, t_stack **stackb);

void	sort_three(t_stack **stacka);
void	sort_four(t_stack **stacka, t_stack **stackb);
void	sort_five(t_stack **stacka, t_stack **stackb);

void	sort_more(t_stack **stacka, t_stack **stackb);

#endif