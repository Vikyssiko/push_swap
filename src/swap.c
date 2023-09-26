/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:26:05 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/23 13:32:20 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	if ((*stack) && (*stack)->next)
	{
		second = (*stack)->next;
		(*stack)->prev = second;
		third = second->next;
		if (third)
			third->prev = (*stack);
		second->next = *stack;
		second->prev = NULL;
		(*stack)->next = third;
		(*stack) = second;
	}
	return (1);
}

int	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src)
	{
		temp = (*src)->next;
		if ((*src)->next)
			(*src)->next->prev = NULL;
		(*src)->next = (*dest);
		if (*dest)
			(*dest)->prev = (*src);
		*dest = *src;
		*src = temp;
	}
	return (1);
}

int	rotate(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		second = (*stack)->next;
		first = (*stack);
		last = ft_stcklast(*stack);
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack) = second;
		second->prev = NULL;
	}
	return (1);
}

int	reverse_rotate(t_stack **stack)
{
	t_stack	*last_but_one;
	t_stack	*last;
	t_stack	*current;

	if (*stack && (*stack)->next)
	{
		current = (*stack);
		while (current && current->next && current->next->next)
			current = current->next;
		last_but_one = current;
		last = current->next;
		last_but_one->next = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		last->prev = NULL;
		*stack = last;
	}
	return (1);
}
