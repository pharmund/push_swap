/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:50:05 by pharmund          #+#    #+#             */
/*   Updated: 2022/03/02 21:50:44 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	check_min_max_int(char *ptr, char *sign, char **array, int *int_arr);
void	min_max_int_error(int error, char **array_split, int *int_array);

static long long int	power(int a, int n)
{
	if (n == 0)
		return (1);
	return (a * power(a, n - 1));
}

static int	find_end_number(char *sign, char *ptr, char **array, int *int_arr)
{
	int	nbr;
	int	i;

	i = 0;
	while (*ptr >= 48 && *ptr <= 57)
	{
		i++;
		if (i > 10)
			min_max_int_error(EXIT_SUCCESS, array, int_arr);
		ptr++;
	}
	if (i == 10)
		check_min_max_int(ptr - i, sign, array, int_arr);
	ptr = ptr - i;
	nbr = 0;
	while (i > 0)
	{
		nbr += (*ptr - 48) * power(10, i - 1);
		ptr++;
		i--;
	}
	if (*sign == '-')
		nbr = -nbr;
	return (nbr);
}

static int	if_sign_is_found(char *ptr, char **array, int *int_arr)
{
	char	sign;

	if (*ptr == '+')
		sign = '+';
	else
		sign = '-';
	ptr = ptr + 1;
	while (*ptr == 48)
		ptr++;
	if (*ptr >= 49 && *ptr <= 57)
		return (find_end_number(&sign, ptr, array, int_arr));
	return (0);
}

int	atoi_overflow(char *ptr, char **array, int *int_arr)
{
	char	plus;

	plus = '+';
	while (ptr && (*ptr == '-' || *ptr == '+' || *ptr == 48 || \
	(*ptr >= 49 && *ptr <= 57) || (*ptr >= 9 && *ptr <= 13) || *ptr == 32))
	{
		if (*ptr == '-' || *ptr == '+')
			return (if_sign_is_found(ptr, array, int_arr));
		if (*ptr >= 49 && *ptr <= 57)
			return (find_end_number(&plus, ptr, array, int_arr));
		if (*ptr == 48)
		{
			while (*ptr == 48)
				ptr++;
			if (*ptr >= 49 && *ptr <= 57)
				return (find_end_number(&plus, ptr, array, int_arr));
			return (0);
		}
		ptr++;
	}
	return (0);
}
