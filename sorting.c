/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:56:02 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/07 13:55:59 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stacks(t_stacks s_ab)
{
	t_elm	*tmp;

	while (s_ab.a_ptr->tail)
	{
		tmp = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail = s_ab.a_ptr->tail->next;
		free (tmp);
	}
	while (s_ab.b_ptr->tail)
	{
		tmp = s_ab.b_ptr->tail;
		s_ab.b_ptr->tail = s_ab.b_ptr->tail->next;
		free (tmp);
	}
}

void	push_in_b_for_sort(t_stacks s_ab, int start_i, int interval)
{
	while (s_ab.a_ptr->length != 0)
	{
		if (s_ab.a_ptr->head->sort_ind >= start_i \
			&& s_ab.a_ptr->head->sort_ind <= start_i + interval)
		{
			ft_pb(s_ab);
			start_i++;
			continue ;
		}
		else if (s_ab.a_ptr->head->sort_ind < start_i)
		{
			ft_pb(s_ab);
			ft_rb(s_ab);
			start_i++;
			continue ;
		}
		else if (s_ab.a_ptr->head->sort_ind > start_i + interval)
		{
			if (r_or_rr_stack_a(s_ab.a_ptr, start_i, interval) \
				<= (s_ab.a_ptr->length) / 2)
				ft_ra(s_ab);
			else
				ft_rra(s_ab);
		}
	}
}

void	final_sorting(t_stacks s_ab)
{
	int		max_index;
	int		interval;

	if (s_ab.nbr_of_elmnts <= 30)
		interval = 1;
	else if (s_ab.nbr_of_elmnts <= 100)
		interval = 15;
	else
		interval = 30;
	push_in_b_for_sort(s_ab, 0, interval);
	max_index = s_ab.nbr_of_elmnts - 1;
	while (s_ab.b_ptr && s_ab.b_ptr->length > 0)
	{
		if (s_ab.b_ptr->head->sort_ind == max_index)
		{
			ft_pa(s_ab);
			max_index--;
			continue ;
		}
		else if (r_or_rr_stack_b(s_ab.b_ptr, max_index) <= \
			(s_ab.b_ptr->length) / 2)
			ft_rb(s_ab);
		else
			ft_rrb(s_ab);
	}
}

void	ft_sorting(t_ptrs s_ab_arr, int size)
{
	t_stacks	s_ab;

	s_ab.a_ptr = s_ab_arr.a_ptr;
	s_ab.b_ptr = s_ab_arr.b_ptr;
	s_ab.nbr_of_elmnts = size;
	if (size <= 3)
		sort_three_iterated_in_a(s_ab, s_ab.a_ptr, 0);
	else if (size <= 5)
		sort_four_five_in_a(s_ab, s_ab.a_ptr);
	else
		final_sorting(s_ab);
	free_stacks(s_ab);
}
