/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:52:19 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:53:05 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_sa(t_stacks s_ab)
{
	int		ind;
	int		value;

	if (s_ab.a_ptr->length >= 2)
	{
		ind = s_ab.a_ptr->head->prev->sort_ind;
		value = s_ab.a_ptr->head->prev->number;
		s_ab.a_ptr->head->prev->number = s_ab.a_ptr->head->number;
		s_ab.a_ptr->head->prev->sort_ind = s_ab.a_ptr->head->sort_ind;
		s_ab.a_ptr->head->number = value;
		s_ab.a_ptr->head->sort_ind = ind;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stacks s_ab)
{
	int		ind;
	int		value;

	if (s_ab.b_ptr->length >= 2)
	{
		ind = s_ab.b_ptr->head->prev->sort_ind;
		value = s_ab.b_ptr->head->prev->number;
		s_ab.b_ptr->head->prev->number = s_ab.b_ptr->head->number;
		s_ab.b_ptr->head->prev->sort_ind = s_ab.b_ptr->head->sort_ind;
		s_ab.b_ptr->head->number = value;
		s_ab.b_ptr->head->sort_ind = ind;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stacks s_ab)
{
	int		ind;
	int		value;

	if (s_ab.b_ptr->length >= 2 || s_ab.a_ptr->length >= 2)
	{
		if (s_ab.a_ptr->length >= 2)
		{
			ind = s_ab.a_ptr->head->prev->sort_ind;
			value = s_ab.a_ptr->head->prev->number;
			s_ab.a_ptr->head->prev->number = s_ab.a_ptr->head->number;
			s_ab.a_ptr->head->prev->sort_ind = s_ab.a_ptr->head->sort_ind;
			s_ab.a_ptr->head->number = value;
			s_ab.a_ptr->head->sort_ind = ind;
		}
		if (s_ab.b_ptr->length >= 2)
		{
			ind = s_ab.b_ptr->head->prev->sort_ind;
			value = s_ab.b_ptr->head->prev->number;
			s_ab.b_ptr->head->prev->number = s_ab.b_ptr->head->number;
			s_ab.b_ptr->head->prev->sort_ind = s_ab.b_ptr->head->sort_ind;
			s_ab.b_ptr->head->number = value;
			s_ab.b_ptr->head->sort_ind = ind;
		}
		write(1, "ss\n", 3);
	}
}

void	ft_pb(t_stacks s_ab)
{
	t_elm	*tmp;

	if (s_ab.a_ptr->length > 0)
	{
		tmp = s_ab.a_ptr->head;
		tmp->next = NULL;
		s_ab.a_ptr->head = tmp->prev;
		if (s_ab.a_ptr->length == 1)
			s_ab.a_ptr->tail = NULL;
		else
			tmp->prev->next = NULL;
		if (s_ab.b_ptr->length == 0)
			s_ab.b_ptr->tail = tmp;
		else
			s_ab.b_ptr->head->next = tmp;
		tmp->prev = s_ab.b_ptr->head;
		s_ab.b_ptr->head = tmp;
		s_ab.a_ptr->length -= 1;
		s_ab.b_ptr->length += 1;
		write(1, "pb\n", 3);
	}
}

void	ft_pa(t_stacks s_ab)
{
	t_elm	*tmp;

	if (s_ab.b_ptr->length > 0)
	{
		tmp = s_ab.b_ptr->head;
		tmp->next = NULL;
		s_ab.b_ptr->head = tmp->prev;
		if (s_ab.b_ptr->length == 1)
			s_ab.b_ptr->tail = NULL;
		else
			tmp->prev->next = NULL;
		if (s_ab.a_ptr->length == 0)
			s_ab.a_ptr->tail = tmp;
		else
			s_ab.a_ptr->head->next = tmp;
		tmp->prev = s_ab.a_ptr->head;
		s_ab.a_ptr->head = tmp;
		s_ab.b_ptr->length -= 1;
		s_ab.a_ptr->length += 1;
		write(1, "pa\n", 3);
	}
}
