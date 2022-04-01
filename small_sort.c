/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:09:45 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 10:08:05 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*track;

	track = (*stack_a)->next;
	if (track->num < track->prev->num && track->num < track->next->num)
	{
		if (track->prev->num > track->next->num)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else if (track->num > track->prev->num && track->num > track->next->num)
	{
		if (track->next->num < track->prev->num)
			rra(stack_a);
		else
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	else if (track->num > track->next->num && track->num < track->prev->num)
	{
		ra(stack_a);
		sa(stack_a);
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	s_pos;
	int	l_pos;

	s_pos = smallest_pos(stack_a);
	l_pos = largest_pos(stack_a);
	if (s_pos == 3)
	{
		if (l_pos == 1)
			sf_var_one(stack_a, stack_b);
		else if (l_pos == 4)
			sf_var_two(stack_a);
		else if (l_pos == 2)
			sf_var_three(stack_a);
	}
	else
	{
		if (s_pos == 2)
			ra(stack_a);
		else if (s_pos == 4)
			rra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	pos = smallest_pos(stack_a);
	if (pos > 3)
	{
		rra(stack_a);
		if (pos == 4)
			rra(stack_a);
	}
	else if (pos == 2)
		sa(stack_a);
	else if (pos == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(stack_a);
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else
		sort_five(stack_a, stack_b);
}
