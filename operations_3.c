/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:53:24 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/07 13:56:20 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	sub_rr_struct_a(t_stacks s_ab)
{
	t_elm	*tmp_first;

	tmp_first = s_ab.a_ptr->head;
	s_ab.a_ptr->head = tmp_first->prev;
	tmp_first->prev->next = NULL;
	tmp_first->prev = NULL;
	tmp_first->next = s_ab.a_ptr->tail;
	s_ab.a_ptr->tail->prev = tmp_first;
	s_ab.a_ptr->tail = tmp_first;
}

void	ft_rr(t_stacks s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.a_ptr->length > 1 || s_ab.b_ptr->length > 1)
	{
		if (s_ab.a_ptr->length > 1)
			sub_rr_struct_a(s_ab);
		if (s_ab.b_ptr->length > 1)
		{
			tmp_first = s_ab.b_ptr->head;
			s_ab.b_ptr->head = tmp_first->prev;
			tmp_first->prev->next = NULL;
			tmp_first->prev = NULL;
			tmp_first->next = s_ab.b_ptr->tail;
			s_ab.b_ptr->tail->prev = tmp_first;
			s_ab.b_ptr->tail = tmp_first;
		}
		write(1, "rr\n", 3);
	}
}

void	ft_ra(t_stacks s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.a_ptr->length > 1)
	{
		tmp_first = s_ab.a_ptr->head;
		s_ab.a_ptr->head = tmp_first->prev;
		tmp_first->prev->next = NULL;
		tmp_first->prev = NULL;
		tmp_first->next = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail->prev = tmp_first;
		s_ab.a_ptr->tail = tmp_first;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stacks s_ab)
{
	t_elm	*tmp_first;

	if (s_ab.b_ptr->length > 1)
	{
		tmp_first = s_ab.b_ptr->head;
		s_ab.b_ptr->head = tmp_first->prev;
		tmp_first->prev->next = NULL;
		tmp_first->prev = NULL;
		tmp_first->next = s_ab.b_ptr->tail;
		s_ab.b_ptr->tail->prev = tmp_first;
		s_ab.b_ptr->tail = tmp_first;
		write(1, "rb\n", 3);
	}
}
