/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:51:05 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:51:16 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	*ft_calloc(size_t n, size_t size);

void	create_first_elm_add_to_sorted_stack(t_ptrs s_ab_arr)
{
	t_elm	*ptr_to_elm;

	ptr_to_elm = ft_calloc(1, sizeof(t_elm));
	if (ptr_to_elm == NULL)
	{
		free (s_ab_arr.int_arr);
		ft_malloc_error(EXIT_FAILURE);
	}
	ptr_to_elm->number = s_ab_arr.int_arr[0];
	s_ab_arr.copy_a->head = ptr_to_elm;
	s_ab_arr.copy_a->tail = ptr_to_elm;
	s_ab_arr.copy_a->length = 1;
}

void	check_tmp_next(t_ptrs s_ab_arr, t_elm	*ptr_new_elm, t_elm *tmp)
{
	if (tmp->next != NULL)
	{
		tmp->next->prev = ptr_new_elm;
		ptr_new_elm->next = tmp->next;
		tmp->next = ptr_new_elm;
		ptr_new_elm->prev = tmp;
	}
	else
	{
		tmp->next = ptr_new_elm;
		s_ab_arr.copy_a->head = ptr_new_elm;
		ptr_new_elm->prev = tmp;
		ptr_new_elm->next = NULL;
	}
}

void	fill_sorted_int_in_stack(t_ptrs s_ab_arr, int i, t_elm	*ptr_new_elm)
{
	t_elm	*tmp;
	int		len;

	len = 0;
	ptr_new_elm->number = s_ab_arr.int_arr[i];
	tmp = s_ab_arr.copy_a->head;
	while (tmp)
	{
		if (ptr_new_elm->number < tmp->number)
		{
			check_tmp_next(s_ab_arr, ptr_new_elm, tmp);
			s_ab_arr.copy_a->length++;
			return ;
		}
			tmp = tmp->prev;
			len++;
		continue ;
	}
	ptr_new_elm->prev = NULL;
	ptr_new_elm->next = s_ab_arr.copy_a->tail;
	s_ab_arr.copy_a->tail->prev = ptr_new_elm;
	s_ab_arr.copy_a->tail = ptr_new_elm;
	s_ab_arr.copy_a->length++;
}

void	create_sorted_stack(t_ptrs s_ab_arr, int *size)
{
	t_elm			*ptr_new_elm;
	t_elm			*tmp;
	int				i;

	create_first_elm_add_to_sorted_stack(s_ab_arr);
	i = 1;
	while (i < *size)
	{
		ptr_new_elm = ft_calloc(1, sizeof(t_elm));
		tmp = s_ab_arr.copy_a->tail;
		if (ptr_new_elm == NULL)
			free_exit_yes_no(s_ab_arr.int_arr, tmp, NULL, 'y');
		fill_sorted_int_in_stack(s_ab_arr, i, ptr_new_elm);
		i++;
	}
	tmp = s_ab_arr.copy_a->head;
	i = 0;
	while (tmp)
	{
		tmp->sort_ind = i++;
		tmp = tmp->prev;
	}
}

void	create_stacks_sorting(int *int_array, int *size)
{
	t_dlist	struct_b;
	t_dlist	struct_a;
	t_dlist	copy_a;
	t_ptrs	s_ab_arr;

	struct_b.length = 0;
	struct_b.head = NULL;
	struct_b.tail = NULL;
	struct_a.length = 0;
	struct_a.head = NULL;
	struct_a.tail = NULL;
	copy_a.length = 0;
	copy_a.head = NULL;
	copy_a.tail = NULL;
	s_ab_arr.a_ptr = &struct_a;
	s_ab_arr.b_ptr = &struct_b;
	s_ab_arr.copy_a = &copy_a;
	s_ab_arr.int_arr = int_array;
	create_sorted_stack(s_ab_arr, size);
	create_first_elm_add_to_stack_a(s_ab_arr);
	fill_stack_a_other_elms(s_ab_arr, *size);
	free_exit_yes_no(s_ab_arr.int_arr, s_ab_arr.copy_a->tail, NULL, 'n');
	ft_sorting(s_ab_arr, *size);
}
