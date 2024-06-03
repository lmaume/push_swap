/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:19:32 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/03 10:52:58 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack **stack)
{
	int	ok;
	int	empty;

	ok = 0;
	empty = 1;
	if ((*stack)->preview == NULL && (*stack)->next == NULL)
		return (empty);
	return (ok);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next != NULL)
		tmp = (*stack)->next;
	else
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_double(t_stack **stack)
{
	t_stack	*it;
	int		value_to_check;

	if ((*stack) == NULL)
		return (0);
	value_to_check = (*stack)->data;
	it = (*stack)->next;
	while (it != NULL)
	{
		if (it->data == value_to_check)
			return (1);
		it = it->next;
	}
	return (is_double(&(*stack)->next));
}

bool	is_valid(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			counter++;
			if (i > 0)
				return (false);
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (false);
	}
	if (counter > 1)
		return (false);
	if (counter == 1 && str[1] == '\0')
		return (false);
	return (true);
}
