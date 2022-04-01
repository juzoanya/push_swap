/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:13:36 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/17 20:16:38 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_a;
	temp = (*stack_a)->next;
	if (*stack_b == NULL)
		d_lstnew(stack_b, track->num);
	else
		lst_addfront(stack_b, track->num);
	lst_delfirst(stack_a);
	*stack_a = temp;
	ft_putendl_fd("pb", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack_b;
	temp = NULL;
	if ((*stack_b)->next != NULL)
		temp = (*stack_b)->next;
	if (*stack_a == NULL)
		d_lstnew(stack_a, track->num);
	else
		lst_addfront(stack_a, track->num);
	if ((*stack_b)->next == NULL && (*stack_b)->prev == NULL)
		lst_delone(stack_b);
	else
		lst_delfirst(stack_b);
	if (temp != NULL)
		*stack_b = temp;
	ft_putendl_fd("pa", 1);
}
