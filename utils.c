/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:09:57 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 17:54:26 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_weak(t_stack **stack)
{
	int		the_weak;
	t_stack	*tmp;

	tmp = (*stack);
	the_weak = tmp->data;
	while (tmp)
	{
		if (tmp->data < the_weak)
			the_weak = tmp->data;
		tmp = tmp->next;
	}
	return (the_weak);
}

int	find_the_stronk(t_stack **stack)
{
	int		the_stronk;
	t_stack	*tmp;

	tmp = (*stack);
	the_stronk = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data > the_stronk)
			the_stronk = tmp->data;
		tmp = tmp->next;
	}
	return (the_stronk);
}

int	get_index(t_stack **stack, int data)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp->data != data)
	{
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			return (1);
	}
	return (i);
}

t_stack	*find_bloc_from_data(t_stack **stack, int data)
{
	t_stack	*it;

	it = (*stack)->next;
	while (it != NULL)
	{
		if (it->data == data)
			return (it);
		it = it->next;
	}
	return (NULL);
}

void	go_up_or_down(t_stack **stack, int data, int type)
{
	t_stack	*tmp;
	int		index;
	int		middle;

	tmp = (*stack);
	index = get_index(&tmp, data);
	middle = (ft_lstsize(tmp) / 2);
	if (middle >= index)
	{
		if (type == STACK_A)
			ra(&(*stack));
		else
			rb(&(*stack));
	}
	else
	{
		if (type == STACK_A)
			rra(&(*stack));
		else
			rrb(&(*stack));
	}
}
