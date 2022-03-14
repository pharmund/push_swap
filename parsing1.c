/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:53:48 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/05 20:06:23 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "./libft/libft.h"

int	check_chars(char *argv, int i, int *digit_flag, int *space_flag)
{
	if (argv[i] == '-' || argv[i] == '+' || argv[i] == ' '\
	|| ft_isdigit(argv[i]) == 1)
	{
		if (ft_isdigit(argv[i]) == 1 && *digit_flag == 0)
			*digit_flag = 1;
		if (argv[i] == ' ' && *space_flag == 0)
			*space_flag = 1;
		if (argv[i] == '-' || argv[i] == '+')
		{
			if (ft_isdigit(argv[i + 1]) == 0 || (i != 0 && argv[i - 1] != ' '))
				ft_error(1);
		}
		return (1);
	}
	ft_error(1);
	return (0);
}

void	ft_free(char **array, int size)
{
	while (array[++size] != NULL)
		free (array[size]);
	ft_error(EXIT_FAILURE);
}

char	**get_data(char **argv, int *space_flag, int size)
{
	int		i;
	int		digit_flag;
	char	**space_array;

	while (argv[++size])
	{
		i = -1;
		digit_flag = 0;
		while (argv[size][++i])
			check_chars(argv[size], i, &digit_flag, space_flag);
		if (digit_flag == 0)
			ft_error(EXIT_SUCCESS);
	}
	size = size - 1;
	space_array = (char **)malloc((size + 1) * sizeof(char *));
	if (space_array == 0)
		ft_malloc_error(EXIT_FAILURE);
	space_array[size] = NULL;
	while (--size >= 0)
	{
		space_array[size] = ft_strdup(argv[size + 1]);
		if (space_array[size] == NULL)
			ft_free(space_array, size);
	}
	return (space_array);
}
