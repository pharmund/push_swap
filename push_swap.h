/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:55:01 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:55:08 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_elm{
	int				number;
	struct s_elm	*next;
	struct s_elm	*prev;
	int				sort_ind;
	int				flag;
}			t_elm;

typedef struct s_dlist{
	struct s_elm	*head;
	struct s_elm	*tail;
	int				length;
}			t_dlist;

typedef struct s_ptrs{
	t_dlist		*a_ptr;
	t_dlist		*b_ptr;
	t_dlist		*copy_a;
	int			*int_arr;
}		t_ptrs;

typedef struct s_stacks{
	t_dlist	*a_ptr;
	t_dlist	*b_ptr;
	int		nbr_of_elmnts;
}		t_stacks;

void	ft_malloc_error(int i);
void	min_max_int_error(int error, char **array_split, int *int_array);
void	ft_error(int i);
void	ft_malloc_error(int i);
void	check_empty_list(int argc);
int		atoi_overflow(char *ptr, char **array_split, int *int_array);
void	create_stacks(int *int_array, int *size);
void	ft_sa(t_stacks s_ab);
void	ft_sb(t_stacks s_ab);
void	ft_ss(t_stacks s_ab);
void	ft_pb(t_stacks s_ab);
void	ft_pa(t_stacks s_ab);
void	ft_ra(t_stacks s_ab);
void	ft_rb(t_stacks s_ab);
void	ft_rr(t_stacks s_ab);
void	ft_rra(t_stacks s_ab);
void	ft_rrb(t_stacks s_ab);
void	ft_rrr(t_stacks s_ab);
void	ft_sorting(t_ptrs s_ab_arr, int size);
void	create_first_elm_add_to_stack_a(t_ptrs s_ab_arr);
void	fill_stack_a_other_elms(t_ptrs s_ab_arr, int size);
void	free_exit_yes_no(int *arr, t_elm *tail_sort, t_elm *tail_a, char c);
void	sort_three_iterated_in_a(t_stacks s_ab, t_dlist *stack, int current_i);
void	sort_four_five_in_a(t_stacks s_ab, t_dlist *ptr_stack);
void	check_exit_final_sorting_of_stack_a(t_stacks s_ab, t_dlist *ptr_stack);
char	three_stack_is_sorted(t_dlist *ptr_stack);
int		r_or_rr_stack_a(t_dlist *stack, int start_interval, int interval);
int		r_or_rr_stack_b(t_dlist *stack, int what_i);

#endif
