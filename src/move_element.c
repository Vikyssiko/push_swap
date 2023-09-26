/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:47:47 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/29 11:47:47 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	rotate_both(t_stack *elem, t_stack **a, t_stack **b)
{
	while (elem->a_begin && elem->b_begin)
	{
		rr(a, b);
		elem->a_begin--;
		elem->b_begin--;
	}
	while (elem->a_begin)
	{
		ra(a);
		elem->a_begin--;
	}
	while (elem->b_begin)
	{
		rb(b);
		elem->b_begin--;
	}
	pb(b, a);
}

void	reverse_rotate_both(t_stack *elem, t_stack **a, t_stack **b)
{
	while (elem->a_end && elem->b_end)
	{
		rrr(a, b);
		elem->a_end--;
		elem->b_end--;
	}
	while (elem->a_end)
	{
		rra(a);
		elem->a_end--;
	}
	while (elem->b_end)
	{
		rrb(b);
		elem->b_end--;
	}
	pb(b, a);
}

void	rra_rb(t_stack *elem, t_stack **a, t_stack **b)
{
	while (elem->a_end)
	{
		rra(a);
		elem->a_end--;
	}
	while (elem->b_begin)
	{
		rb(b);
		elem->b_begin--;
	}
	pb(b, a);
}

void	ra_rrb(t_stack *elem, t_stack **a, t_stack **b)
{
	while (elem->a_begin)
	{
		ra(a);
		elem->a_begin--;
	}
	while (elem->b_end)
	{
		rrb(b);
		elem->b_end--;
	}
	pb(b, a);
}

void	move_to_b(t_stack *elem, t_stack **a, t_stack **b)
{
	if (elem->operations == 1)
		pb(b, a);
	else if (elem->operations == elem->b_begin + elem->a_end + 1)
		rra_rb(elem, a, b);
	else if (elem->operations == elem->a_begin + elem->b_end + 1)
		ra_rrb(elem, a, b);
	else if (elem->operations == max(elem->a_begin, elem->b_begin) + 1)
		rotate_both(elem, a, b);
	else if (elem->operations == max(elem->a_end, elem->b_end) + 1)
		reverse_rotate_both(elem, a, b);
}
