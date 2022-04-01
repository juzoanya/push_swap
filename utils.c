/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:29:42 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/23 18:15:37 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*track;
	t_stack	*temp;

	track = *stack;
	while (track != NULL)
	{
		temp = track->next;
		free(track);
		track = temp;
	}
	*stack = NULL;
}

int	stack_len(t_stack **stack)
{
	t_stack	*track;
	int		i;

	i = 0;
	track = *stack;
	while (track->next != NULL)
	{
		i++;
		track = track->next;
	}
	i += 1;
	return (i);
}

int	find_smallest(t_stack **stack)
{
	t_stack	*track;
	t_stack	*temp;

	if (*stack == NULL)
		return (1);
	temp = *stack;
	track = (*stack)->next;
	while (track->next != NULL)
	{
		if (track->num < temp->num)
			temp = track;
		track = track->next;
	}
	if (track->num < temp->num)
		temp = track;
	return (temp->num);
}

int	find_largest(t_stack **stack)
{
	t_stack	*track;
	t_stack	*temp;

	if (*stack == NULL)
		return (1);
	temp = *stack;
	track = (*stack)->next;
	while (track->next != NULL)
	{
		if (track->num > temp->num)
			temp = track;
		track = track->next;
	}
	if (track->num > temp->num)
		temp = track;
	return (temp->num);
}

t_stack	*get_tail(t_stack **stack)
{
	t_stack	*track;

	track = *stack;
	while (track->next != NULL)
		track = track->next;
	return (track);
}

//find the position of the smallest number in the stack
int	smallest_pos(t_stack **stack)
{
	t_stack	*track;
	t_stack	*temp;
	int		temp_pos;
	int		track_pos;

	temp = *stack;
	temp_pos = 1;
	track = (*stack)->next;
	track_pos = 2;
	while (track->next != NULL)
	{
		if (track->num < temp->num)
		{
			temp = track;
			temp_pos = track_pos;;
		}
		track = track->next;
		track_pos++;
	}
	if (track->num < temp->num)
	{
		temp = track;
		temp_pos = track_pos;;
	}
	return (temp_pos);
}

//find the position of the largest number in the stack
int	largest_pos(t_stack **stack)
{
	t_stack	*track;
	t_stack	*temp;
	int		temp_pos;
	int		track_pos;

	temp = *stack;
	temp_pos = 1;
	track = (*stack)->next;
	track_pos = 2;
	while (track->next != NULL)
	{
		if (track->num > temp->num)
		{
			temp = track;
			temp_pos = track_pos;;
		}
		track = track->next;
		track_pos++;
	}
	if (track->num > temp->num)
	{
		temp = track;
		temp_pos = track_pos;;
	}
	return (temp_pos);
}

//check of head is greater than tail
int	check_head_tail(t_stack **stack)
{
	t_stack	*track;

	track = *stack;
	while (track->next != NULL)
		track = track->next;
	if ((*stack)->num > track->num)
		return (1);
	return (0);
}

//check if stack has less than three values
int	check_less_three(t_stack **stack)
{
	t_stack	*track;

	if ((*stack)->next == NULL)
		return (1);
	else
		track = (*stack)->next;
	if (track->next == NULL)
		return (1);
	return (0);
}