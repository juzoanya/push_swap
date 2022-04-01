/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:55:08 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/25 12:43:09 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int		stack_len(t_stack **stack);
void	print_error(void);
void	check_argv(int argc, char **argv);
void	small_sort(t_stack **stack_a, t_stack **stack_b);
void	mid_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	create_chunks(t_stack **stack_a, t_stack **stack_b, int min, int max);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	d_lstnew(t_stack **stack, int num);
void	lst_addfront(t_stack **stack, int num);
void	lst_delfirst(t_stack **stack);
void	lst_delone(t_stack **stack);
void	free_stack(t_stack **stack);
void	sort_three(t_stack **stack_a);
void	sf_var_one(t_stack **stack_a, t_stack **stack_b);
void	sf_var_two(t_stack **stack_a);
void	sf_var_three(t_stack **stack_a);
int		find_smallest(t_stack **stack);
int		find_largest(t_stack **stack);
int		smallest_pos(t_stack **stack);
int		largest_pos(t_stack **stack);
int		check_head_tail(t_stack **stack);
int		check_less_three(t_stack **stack);
void	rev_sort_three(t_stack **stack_b);
void	mid_sort2(t_stack **stack_a, t_stack **stack_b);
void	mid_sort3(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_tail(t_stack **stack);
void	print_node(t_stack **stack);//to be removed

#endif