/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:55:25 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:55:30 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_iterated_in_a(t_stacks s_ab, t_dlist *stack, int current_i)
{
	if (three_stack_is_sorted(stack) != 'n')
		return ;
	if (stack->length == 2)
		return (ft_sa(s_ab));
	else if (stack->head->sort_ind == current_i)
	{
		ft_rra(s_ab);
		ft_sa(s_ab);
	}
	else if (stack->head->sort_ind == current_i + 1)
	{
		if (stack->head->prev->sort_ind == current_i)
			ft_sa(s_ab);
		else
			ft_rra(s_ab);
	}
	else
	{
		if (stack->head->prev->sort_ind == current_i)
			return (ft_ra(s_ab));
		ft_sa(s_ab);
		ft_rra(s_ab);
	}
}

void	five_better_r_or_rr_for_index(t_stacks s_ab, t_dlist *stack, int index)
{
	t_elm	*tmp;
	int		help_index;

	help_index = 0;
	tmp = stack->head;
	while (tmp->sort_ind != index)
	{
		tmp = tmp->prev;
		help_index++;
	}
	tmp = stack->head;
	while (tmp->sort_ind != index)
	{
		if (help_index <= 2)
		{
			tmp = tmp->prev;
			ft_ra(s_ab);
		}
		else
		{
			tmp = stack->tail;
			ft_rra(s_ab);
		}
	}
}

void	sort_four_five_in_a(t_stacks s_ab, t_dlist *stack)
{
	if (stack == 0)
		return ;
	five_better_r_or_rr_for_index(s_ab, stack, 0);
	check_exit_final_sorting_of_stack_a(s_ab, stack);
	ft_pb(s_ab);
	five_better_r_or_rr_for_index(s_ab, stack, 1);
	if (three_stack_is_sorted(stack) == 'y')
	{
		ft_pa(s_ab);
		return ;
	}
	ft_pb(s_ab);
	sort_three_iterated_in_a(s_ab, s_ab.a_ptr, 2);
	ft_pa(s_ab);
	ft_pa(s_ab);
}
