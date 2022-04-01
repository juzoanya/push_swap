/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:52:47 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/18 12:28:20 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int	temp;

	temp = (*stack_a)->num;
	(*stack_a)->num = (*stack_a)->next->num;
	(*stack_a)->next->num = temp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	int	temp;

	temp = (*stack_b)->num;
	(*stack_b)->num = (*stack_b)->next->num;
	(*stack_b)->next->num = temp;
	ft_putendl_fd("sa", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
