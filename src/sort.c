/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:45:52 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/25 12:45:52 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->position > (*a)->next->position)
		sa(a);
}

void	push_three_elem(t_stack **a, t_stack **b)
{
	int	first_pos;
	int	sec_pos;
	int	third_pos;

	pb(b, a);
	pb(b, a);
	if ((*b)->position < (*b)->next->position)
		sb(b);
	pb(b, a);
	first_pos = (*b)->position;
	sec_pos = (*b)->next->position;
	third_pos = (*b)->next->next->position;
	if (first_pos < sec_pos && first_pos < third_pos)
		rb(b);
	else if (first_pos < sec_pos && first_pos > third_pos)
		sb(b);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = -2147483648;
	while (stack)
	{
		if ((stack)->position > max)
			max = (stack)->position;
		(stack) = (stack)->next;
	}
	return (max);
}

int	find_min_pos(t_stack *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if ((stack)->position < min)
			min = (stack)->position;
		(stack) = (stack)->next;
	}
	return (min);
}
