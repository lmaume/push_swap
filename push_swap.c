/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:46:52 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/03 17:00:48 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
int	converter(char **tab, t_stack **head, t_stack **stackb)
{
	int	i;
	int	val;
	int	error;

	i = 1;
	val = 0;
	error = 0;
	while (tab[i])
	{
		if (is_valid(tab[i]) == true && error == 0)
		{
			ft_lstadd_back(&(*head), ft_lstnew(ft_atoi(tab[i], &error)));
			i++;
		}
		else
		{
			destroyer_of_worlds((*head));
			destroyer_of_worlds((*stackb));
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	if (argc < 2)
		return (0);
	stacka = ft_calloc(1, sizeof(t_stack));
	stackb = ft_calloc(1, sizeof(t_stack));
	i = 1;
	if (converter(argv, &stacka, &stackb) == -1)
		return (ft_putstr_fd("Error\n", 2), -1);
	if (is_double(&stacka->next) == 1)
	{
		destroyer_of_worlds(stacka);
		destroyer_of_worlds(stackb);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	wich_algo(&stacka, &stackb);
	destroyer_of_worlds(stacka);
	destroyer_of_worlds(stackb);
	return (0);
}

void	wich_algo(t_stack **stacka, t_stack **stackb)
{
	if (is_sorted(stacka) == 0)
		return ;
	else if (ft_lstsize((*stacka)->next) == 2)
		ra(&(*stacka)->next);
	else if (ft_lstsize((*stacka)->next) == 3)
		sort_three(stacka);
	else if (ft_lstsize((*stacka)->next) == 4)
		sort_four(stacka, stackb);
	else if (ft_lstsize((*stacka)->next) == 5)
		sort_five(stacka, stackb);
	else
		sort_more(stacka, stackb);
}

void	destroyer_of_worlds(t_stack	*stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
