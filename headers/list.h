/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:03:37 by lmaume            #+#    #+#             */
/*   Updated: 2024/05/30 14:03:33 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_stack
{
	int					data;
	struct s_stack		*preview;
	struct s_stack		*next;
}					t_stack;

//? ## LIST CREATION ##

t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *newbloc);
void	ft_lstadd_back(t_stack **lst, t_stack *newbloc);

//? ## LIST GET-INFOS ##

int		ft_lstsize(t_stack *lst);
int		get_index(t_stack **stack, int data);
int		find_the_weak(t_stack **stack);
int		find_the_stronk(t_stack **stack);
int		find_cheapest(t_stack **stacka, t_stack **stackb);

#endif