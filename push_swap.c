/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:01:57 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 17:54:39 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_stack **stack)//To be removed
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next != NULL)
	{
		printf("->%d\n", curr->num);
		curr = curr->next;
	}
	printf("->%d\n", curr->num);
}

int	check_duplicate(t_stack **stack_a)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_a;
	while (track->next != NULL)
	{
		temp = track->next;
		while (temp->next != NULL)
		{
			if (track->num == temp->num)
				return (1);
			temp = temp->next;
		}
		if (track->num == temp->num)
			return (1);
		track = track->next;
	}
	if (track->num == track->prev->num)
		return (1);
	return (0);
}

int	is_sorted(t_stack **stack_a)
{
	t_stack	*track;

	track = *stack_a;
	while (track->next != NULL)
	{
		if (track->num > track->next->num)
			return (0);
		track = track->next;
	}
	if (track->num < track->prev->num)
		return (0);
	return (1);
}

void	stack_init(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		d_lstnew(stack_a, num);
		i++;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(stack_a);
	if (len <= 5)
		small_sort(stack_a, stack_b);
	// else if (len <= 6)
	// 	mid_sort2(stack_a, stack_b);
	else if (len <= 100)
		mid_sort(stack_a, stack_b);
	// else
	// 	large_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 2)
	{
		check_argv(argc, argv);
		stack_init(argc, argv, &stack_a);
		if (check_duplicate(&stack_a))
			print_error();
		if (is_sorted(&stack_a))
			return (0);
		push_swap(&stack_a, &stack_b);
	}
	//print_node(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
