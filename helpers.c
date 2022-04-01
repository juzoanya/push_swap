/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:58:38 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 13:34:17 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort_4 helper - sort variation 1 (s_po 3, l_pos 1)
void	sf_var_one(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

//sort_4 helper - sort variation 2 (s_po 3, l_pos 4)
void	sf_var_two(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
	rra(stack_a);
	rra(stack_a);
	sa(stack_a);
	ra(stack_a);
}

//sort_4 helper - sort variation 2 (s_po 3, l_pos 2)
void	sf_var_three(t_stack **stack_a)
{
	if (check_head_tail(stack_a))
	{
		ra(stack_a);
		ra(stack_a);
	}
	else
	{
		rra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
}

void	rev_sort_three(t_stack **stack_b)
{
	t_stack	*track;

	track = (*stack_b)->next;
	if (track->num > track->prev->num && track->num > track->next->num)
	{
		if (track->prev->num < track->next->num)
			rb(stack_b);
		else
			sb(stack_b);
	}
	else if (track->num < track->prev->num && track->num < track->next->num)
	{
		if (track->next->num > track->prev->num)
			rrb(stack_b);
		else
		{
			rrb(stack_b);
			sb(stack_b);
		}
	}
	else if (track->num < track->next->num && track->num > track->prev->num)
	{
		rb(stack_b);
		sb(stack_b);
	}
}