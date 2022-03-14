/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:52:52 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:53:04 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_rra(t_stacks s_ab)
{
	t_elm	*temp_last;

	if (s_ab.a_ptr->length > 1)
	{
		temp_last = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail = s_ab.a_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.a_ptr->head = temp_last;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stacks s_ab)
{
	t_elm	*temp_last;

	if (s_ab.b_ptr->length > 1)
	{
		temp_last = s_ab.b_ptr->tail;
		s_ab.b_ptr->tail = s_ab.b_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.b_ptr->head;
		s_ab.b_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.b_ptr->head = temp_last;
		write(1, "rrb\n", 4);
	}
}

static void	sub_rrr_struct_a(t_stacks s_ab)
{
	t_elm	*temp_last;

		temp_last = s_ab.a_ptr->tail;
		s_ab.a_ptr->tail = s_ab.a_ptr->tail->next;
		temp_last->next->prev = NULL;
		temp_last->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head->next = temp_last;
		temp_last->next = NULL;
		s_ab.a_ptr->head = temp_last;
}

void	ft_rrr(t_stacks s_ab)
{
	t_elm	*temp_last;

	if (s_ab.b_ptr->length > 1 || s_ab.a_ptr->length > 1)
	{
		if (s_ab.a_ptr->length > 1)
			sub_rrr_struct_a(s_ab);
		if (s_ab.b_ptr->length > 1)
		{
			temp_last = s_ab.b_ptr->tail;
			s_ab.b_ptr->tail = s_ab.b_ptr->tail->next;
			temp_last->next->prev = NULL;
			temp_last->prev = s_ab.b_ptr->head;
			s_ab.b_ptr->head->next = temp_last;
			temp_last->next = NULL;
			s_ab.b_ptr->head = temp_last;
		}
		write(1, "rrr\n", 4);
	}
}
