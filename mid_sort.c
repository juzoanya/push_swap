/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:09:53 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 19:33:47 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_chunks(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	t_stack	*track;
	t_stack	*temp;
	int		num;

	track = *stack_a;
	while (track != NULL)
	{
		if (track->num >= min && track->num <= max)
		{
			num = track->num;
			temp = *stack_a;
			while (temp->num != num)
			{
				ra(stack_a);
				temp = *stack_a;
			}
			pb(stack_a, stack_b);
			track = *stack_a;
		}
		else
			track = track->next;
	}
}

// static int	is_smallest(t_stack **stack, int num)
// {
// 	t_stack	*track;

// 	if (*stack == NULL)
// 		return (0);
// 	track = *stack;
// 	while (track != NULL)
// 	{
// 		if (num > track->num)
// 			return (0);
// 		track = track->next;
// 	}
// 	return (1);
// }

static int	is_greatest(t_stack **stack, int num)
{
	t_stack	*track;

	if (*stack == NULL)
		return (0);
	track = *stack;
	while (track != NULL)
	{
		if (num < track->num)
			return (0);
		track = track->next;
	}
	return (1);
}

// static int	less_mid_exist(t_stack **stack, int mid)
// {
// 	t_stack	*track;

// 	if (*stack == NULL)
// 		return (0);
// 	track = *stack;
// 	while (track != NULL)
// 	{
// 		if (track->num < mid)
// 			return (1);
// 		track = track->next;
// 	}
// 	return (0);
// }

// static int	bigger_mid_exist(t_stack **stack, int mid)
// {
// 	t_stack	*track;

// 	if (*stack == NULL)
// 		return (0);
// 	track = *stack;
// 	while (track != NULL)
// 	{
// 		if (track->num > mid)
// 			return (1);
// 		track = track->next;
// 	}
// 	return (0);
// }

// static int	find_mid(t_stack **stack_a, int mid)
// {
// 	t_stack *track;

// 	track = *stack_a;
// 	while (mid > 0)
// 	{
// 		track = track->next;
// 		mid--;
// 	}
// 	return (track->prev->num);
// }

// static int	check_less_three(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*track;
// 	int		len;

// 	if ((*stack_b)->next == NULL)
// 		return (1);
// 	else
// 		track = (*stack_b)->next;
// 	if (track->next == NULL)
// 		return (1);
// 	return (0);
// }

static int	compare_pos(t_stack **stack, int num)
{
	t_stack	*track;
	int		i;

	if (*stack == NULL)
		return (0);
	track = *stack;
	i = 0;
	while (track != NULL)
	{
		if (track->num != num)
			i++;
		else
			return (i);
		track = track->next;
	}
	return (0);
}

void	five_chunks(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	largest;
	int	div;

	smallest = find_smallest(stack_a);
	largest = find_largest(stack_a);
	div = ((largest - smallest) / 5);
	create_chunks(stack_a, stack_b, smallest, smallest + div);
	create_chunks(stack_a, stack_b, (smallest + div + 1), smallest + (div * 2));
	create_chunks(stack_a, stack_b, smallest + (div * 2) + 1, smallest + (div * 3));
	create_chunks(stack_a, stack_b, smallest + (div * 3) + 1, smallest + (div * 4));
	create_chunks(stack_a, stack_b, smallest + (div * 4) + 1, largest);
	//printf("------Stack_A\n");
	//print_node(stack_a);
	//printf("------Stack_B\n");
	//print_node(stack_b);
}

void	mid_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	big;
	int	pos;
	int	rb_len;
	int	rrb_len;
	t_stack	*track;

	five_chunks(stack_a, stack_b);
	rb_len = 0;
	rrb_len = 0;
	track = *stack_b;
	while (track != NULL)
	{
		if (is_greatest(stack_b, track->num))
			pa(stack_a, stack_b);
		else
		{
			big = find_largest(stack_b);
			pos = compare_pos(stack_b, big);
			if (pos > stack_len(stack_b)/2)
			{
				while (track->num != big)
				{
					rrb(stack_b);
					rrb_len++;
					track = *stack_b;
				}
				pa(stack_a, stack_b);
				while (rrb_len - 1 != 0)
				{
					rb(stack_b);
					rrb_len--;
				}
			}
			else
			{
				while (track->num != big)
				{
					rb(stack_b);
					rb_len++;
					track = *stack_b;
				}
				pa(stack_a, stack_b);
				while (rb_len != 0)
				{
					rrb(stack_b);
					rb_len--;
				}
			}
		}
		if (check_less_three(stack_b))
		{
			if (stack_len(stack_b) == 2)
			{
				if ((*stack_b)->num < (*stack_b)->next->num)
				{
					sb(stack_b);
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
				}
				else
				{
					pa(stack_a, stack_b);
					pa(stack_a, stack_b);
				}
			}
			else if (stack_len(stack_b) == 1)
				pa(stack_a, stack_b);
			break;
		}
		track = *stack_b;
	}
	//printf("------Stack_B\n");
	//print_node(stack_b);
}
