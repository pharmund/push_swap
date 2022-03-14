/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:51:49 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/07 13:56:39 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size);

void	free_exit_yes_no(int *arr, t_elm *tail_sort, t_elm *tail_a, char c)
{
	t_elm	*tmp;

	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	while (tail_sort)
	{
		tmp = tail_sort;
		tail_sort = tail_sort->next;
		free (tmp);
	}
	while (tail_a)
	{
		tmp = tail_a;
		tail_a = tail_a->next;
		free (tmp);
	}
	if (c == 'm')
		ft_malloc_error(EXIT_FAILURE);
	if (c == 'y')
		ft_error(EXIT_SUCCESS);
}

void	create_first_elm_add_to_stack_a(t_ptrs s_ab_arr)
{
	t_elm	*ptr_on_first_elem;
	t_elm	*tmp;

	ptr_on_first_elem = (t_elm *)ft_calloc(1, sizeof(t_elm));
	if (ptr_on_first_elem == NULL)
		free_exit_yes_no(s_ab_arr.int_arr, s_ab_arr.copy_a->tail, NULL, 'm');
	tmp = s_ab_arr.copy_a->head;
	while (tmp)
	{
		if (tmp->number == s_ab_arr.int_arr[0])
		{
			ptr_on_first_elem->number = s_ab_arr.int_arr[0];
			ptr_on_first_elem->sort_ind = tmp->sort_ind;
			s_ab_arr.a_ptr->length = 1;
			s_ab_arr.a_ptr->head = ptr_on_first_elem;
			s_ab_arr.a_ptr->tail = ptr_on_first_elem;
			return ;
		}
		tmp = tmp->prev;
	}
}

void	create_elements_for_stack_a(t_ptrs s_ab_arr, int i, t_elm *first_ptr)
{
	t_elm	*ptr_on_new;
	t_elm	*tmp;

	ptr_on_new = (t_elm *)calloc(1, sizeof(t_elm));
	tmp = s_ab_arr.copy_a->tail;
	if (ptr_on_new == NULL)
		free_exit_yes_no(s_ab_arr.int_arr, tmp, s_ab_arr.a_ptr->tail, 'm');
	if (i == 1)
		first_ptr->prev = ptr_on_new;
	tmp = s_ab_arr.copy_a->head;
	while (tmp)
	{
		if (tmp->number == s_ab_arr.int_arr[i])
		{
			ptr_on_new->number = s_ab_arr.int_arr[i];
			ptr_on_new->sort_ind = tmp->sort_ind;
			ptr_on_new->next = s_ab_arr.a_ptr->tail;
			ptr_on_new->prev = NULL;
			s_ab_arr.a_ptr->tail->prev = ptr_on_new;
			s_ab_arr.a_ptr->tail = ptr_on_new;
			s_ab_arr.a_ptr->length += 1;
			return ;
		}
		tmp = tmp->prev;
	}
}

void	fill_stack_a_other_elms(t_ptrs s_ab_arr, int size)
{
	int	i;

	i = 1;
	while (i < (size))
	{
		create_elements_for_stack_a(s_ab_arr, i, s_ab_arr.a_ptr->head);
		i++;
	}
}
