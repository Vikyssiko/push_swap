/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:33:36 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/30 10:33:36 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	position_of_min(t_stack *a)
{
	int	position;

	position = 0;
	while (a)
	{
		if (a->position == 1)
			return (position);
		a = a->next;
		position++;
	}
	return (0);
}

void	rotate_a(t_stack **a)
{
	while ((*a)->position != 1)
	{
		if (position_of_min(*a) < ft_stcksize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}

void	push_all(t_stack **a, t_stack **b, int elem)
{
	int	size;

	size = ft_stcksize(*a) + ft_stcksize(*b);
	while (*b)
	{
		elem = ft_stcklast(*a)->position;
		if ((*b) && ((*b)->position == (*a)->position - 1
				|| ((*b)->position == size && elem + 1 != (*a)->position)))
			pa(a, b);
		else
			rra(a);
	}
}

void	prepare_for_pushing(t_stack **a, t_stack **b)
{
	if (ft_stcksize(*b) == 2 && (*b)->position < (*b)->next->position)
		sb(b);
	if (find_max(*b) < ft_stcksize(*b) / 2)
	{
		while ((*b)->position != find_max(*b))
			rb(b);
	}
	if ((*b) && (*b)->position < find_max(*a))
	{
		while ((*b) && (*b)->position > (*a)->position)
			ra(a);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	prepare_for_pushing(a, b);
	if ((*b)->position < find_min_pos(*a) || ((*b)->position < (*a)->position
			&& (*b)->position > ft_stcklast(*a)->position))
	{
		if (ft_stcklast(*a)->position == ft_stcksize(*a) + ft_stcksize(*b))
		{
			while ((*b) && (*a)->position != 1
				&& (*a)->position != ft_stcklast(*a)->position - 1)
				pa(a, b);
		}
		else
		{
			while ((*b) && (*a)->position != ft_stcklast(*a)->position + 1)
				pa(a, b);
		}
	}
	else if ((*b)->position > find_max(*a))
	{
		while ((*b) && (*a)->position != ft_stcklast(*a)->position + 1)
			pa(a, b);
	}
	push_all(a, b, ft_stcklast(*a)->position);
	rotate_a(a);
}
