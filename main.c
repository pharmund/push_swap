/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:49:01 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/03 09:13:09 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**get_data(char **argv, int *space_flag, int size);
char	**get_data_2(char **array);
int		*check_int_dubble(char **array, int *size);
void	create_stacks_sorting(int *int_array, int *size);

void	ft_error(int i)
{
	write(2, "Error\n", 6);
	if (i == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	ft_malloc_error(int i)
{
	write(2, "malloc error\n", 13);
	if (i == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	min_max_int_error(int error, char **array_split, int *int_array)
{
	int	i;

	free (int_array);
	i = 0;
	while (array_split[i])
		free (array_split[i++]);
	free (array_split);
	ft_error(error);
}

void	check_empty_list(int argc)
{
	if (argc == 1)
	{
		write(1, "Print integers, e.g. ./push_swap -7 11 0 345 ...\n", 49);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	char			**array;
	int				sp_flag;
	int				*int_array;
	int				size;

	sp_flag = 0;
	size = 0;
	check_empty_list(argc);
	array = get_data(argv, &sp_flag, size);
	if (sp_flag == 1)
		(array = get_data_2(array));
	int_array = check_int_dubble(array, &size);
	create_stacks_sorting(int_array, &size);
	return (0);
}
