/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:00:01 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/12 15:00:01 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				a_begin;
	int				a_end;
	int				b_begin;
	int				b_end;
	int				operations;
	int				content;
	int				position;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stcknew(int content);
void	ft_stckadd_front(t_stack **stck, t_stack *new);
void	ft_stckadd_back(t_stack **stack, t_stack *new);
void	clean(t_stack **stack);
void	sort(t_stack **a, t_stack **b);
t_stack	*put_to_stack(int args, char *argv[]);
void	check_dup(t_stack *stack);
int		swap(t_stack **stack);
int		push(t_stack **dest, t_stack **src);
t_stack	*ft_stcklast(t_stack *stack);
int		ft_stcksize(t_stack *stck);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
int		find_min(t_stack *stack, int min);
void	find_position_for_all(t_stack **stack);
int		is_sorted(t_stack *stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	push_three_elem(t_stack **a, t_stack **b);
int		find_max(t_stack *stack);
void	find_positions(t_stack **a, t_stack **b);
void	count_operations(t_stack *a);
t_stack	*find_easiest_to_move(t_stack *a);
int		max(int a, int b);
int		min(int a, int b);
void	move_to_b(t_stack *elem, t_stack **a, t_stack **b);
int		find_min_pos(t_stack *stack);
void	push_to_a(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	exit_with_error(void);
void	exit_and_clean(t_stack **stack);

int		ft_strcmp(const char *s1, const char *s2);
void	check_sorted(t_stack **a, t_stack **b);
int		instruction_for_both(char *str, t_stack **a, t_stack **b);
int		check_instructions(char *str, t_stack **a, t_stack **b);
void	clean_stack(t_stack **stack);

#endif
