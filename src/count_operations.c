/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:35:20 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/28 10:35:20 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	count_operations_for_one(t_stack *a)
{
	int	max_begin;
	int	max_end;
	int	min_max;
	int	min_total;

	max_begin = max(a->a_begin, a->b_begin);
	max_end = max(a->a_end, a->b_end);
	min_max = min(max_begin, max_end);
	min_total = min(min_max, min(a->a_begin + a->b_end, a->a_end + a->b_begin));
	return (min_total);
}

void	count_operations(t_stack *a)
{
	while (a)
	{
		a->operations = count_operations_for_one(a) + 1;
		a = a->next;
	}
}

t_stack	*find_easiest_to_move(t_stack *a)
{
	int		min;
	t_stack	*easiest_to_move;

	min = 2147482647;
	while (a)
	{
		if (a->operations < min)
		{
			min = a->operations;
			easiest_to_move = a;
		}
		a = a->next;
	}
	return (easiest_to_move);
}
