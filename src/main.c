/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:06:55 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/22 22:13:37 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	clean(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack));
		*stack = temp;
	}
}

void	exit_and_clean(t_stack **stack)
{
	if (stack)
		clean(stack);
	write(2, "Error\n", 6);
	exit(0);
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_stcksize(*a) == 2)
	{
		sort_two(a);
		clean(a);
		exit (0);
	}
	if (ft_stcksize(*a) == 3)
	{
		sort_three(a);
		clean(a);
		exit (0);
	}
	if (ft_stcksize(*a) > 5)
		push_three_elem(a, b);
	while (ft_stcksize(*a) != 3)
	{
		find_positions(a, b);
		count_operations(*a);
		move_to_b(find_easiest_to_move(*a), a, b);
	}
	sort_three(a);
	push_to_a(a, b);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int args, char *argv[])
{
	t_stack	*b;
	t_stack	*stack;

	b = NULL;
	stack = put_to_stack(args, argv);
	check_dup(stack);
	find_position_for_all(&stack);
	if (is_sorted(stack))
	{
		clean(&stack);
		return (1);
	}
	sort(&stack, &b);
	clean(&b);
	clean(&stack);
}
