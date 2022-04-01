/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:27:42 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/21 11:37:16 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	check_int(int argc, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		j = ft_atoi(argv[i]);
// 		if (j > INT_MAX || j < INT_MIN)
// 			print_error();
// 		i++;
// 	}
// }

void	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		j = 0;
		str = argv[i];
		while (str[j] != '\0')
		{
			if ((str[j] == '+' || str[j] == '-') && j == 0)
				j++;
			if (!(ft_isdigit(str[j])))
				print_error();
			j++;
		}
		i++;
	}
	//check_int(argc, argv);
}
