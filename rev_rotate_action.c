/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:38:18 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/18 12:25:31 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_a;
	while (track->next != NULL)
		track = track->next;
	temp = track->prev;
	track->next = *stack_a;
	temp->next = NULL;
	track->prev = NULL;
	(*stack_a)->prev = track;
	*stack_a = track;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_b;
	while (track->next != NULL)
		track = track->next;
	temp = track->prev;
	track->next = *stack_b;
	temp->next = NULL;
	track->prev = NULL;
	(*stack_b)->prev = track;
	*stack_b = track;
	ft_putendl_fd("rra", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
