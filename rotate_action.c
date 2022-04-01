/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:12:41 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/17 20:15:17 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_a;
	while (track->next != NULL)
		track = track->next;
	temp = (*stack_a)->next;
	track->next = *stack_a;
	(*stack_a)->prev = track;
	(*stack_a)->next = NULL;
	temp->prev = NULL;
	*stack_a = temp;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_b;
	while (track->next != NULL)
		track = track->next;
	temp = (*stack_b)->next;
	track->next = *stack_b;
	(*stack_b)->prev = track;
	(*stack_b)->next = NULL;
	temp->prev = NULL;
	*stack_b = temp;
	ft_putendl_fd("ra", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
