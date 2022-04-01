/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:50:28 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 13:20:43 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	d_lstnew(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*tail;

	tail = *stack;
	node = (t_stack *)malloc(sizeof(*node));
	if (node == NULL)
		return ;
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		tail = *stack;
	}
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void	lst_addfront(t_stack **stack, int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (node == NULL)
		return ;
	node->num = num;
	node->prev = NULL;
	node->next = *stack;
	(*stack)->prev = node;
	*stack = node;
}

void	lst_delfirst(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
		temp->next = NULL;
	}
	free(temp);
}

void	lst_delone(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	free(temp);
	*stack = NULL;
}
