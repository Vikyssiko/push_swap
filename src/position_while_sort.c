/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:35:15 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/25 12:36:02 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	init_one(t_stack *b, t_stack *a, int max, int min);

void	initialize_a_entry(t_stack *a);

void	initialize_b_entry(t_stack *a, t_stack *b);

void	find_positions(t_stack **a, t_stack **b)
{
	initialize_a_entry(*a);
	initialize_b_entry(*a, *b);
}

void	initialize_a_entry(t_stack	*a)
{
	int		a_size;
	int		cursor;

	a_size = ft_stcksize(a);
	cursor = 0;
	while (a)
	{
		(a)->a_begin = cursor;
		(a)->a_end = a_size - cursor;
		(a) = (a)->next;
		cursor++;
	}
}

void	initialize_b_entry(t_stack *a, t_stack *b)
{
	int	max;

	while (a)
	{
		max = find_max(b);
		init_one(b, a, max, find_min_pos(b));
		(a) = (a)->next;
	}
}

void	init(t_stack *a, int b_size, int cursor)
{
	(a)->b_begin = cursor;
	(a)->b_end = b_size - cursor;
}

void	init_one(t_stack *b, t_stack *a, int max, int min)
{
	int	b_size;
	int	cursor;
	int	b_prev_pos;

	b_size = ft_stcksize(b);
	cursor = 0;
	while (b)
	{
		if ((b)->prev == NULL)
			b_prev_pos = ft_stcklast(b)->position;
		else
			b_prev_pos = (b)->prev->position;
		if (a->position > max || a->position < min)
		{
			if (b->position == max)
				return (init(a, b_size, cursor));
		}
		else if ((a->position > b->position && (a->position < b_prev_pos
					|| a->position > max)))
			return (init(a, b_size, cursor));
		(b) = (b)->next;
		cursor++;
	}
}
