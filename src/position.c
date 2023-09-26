/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:12:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/22 20:12:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	find_min(t_stack *stack, int min)
{
	while (stack)
	{
		if ((stack)->position == 0)
		{
			min = (stack)->content;
			break ;
		}
		(stack) = (stack)->next;
	}
	while (stack)
	{
		if ((stack)->content < min && (stack)->position == 0)
		{
			min = (stack)->content;
		}
		(stack) = (stack)->next;
	}
	return (min);
}

void	find_position_for_all(t_stack **stack)
{
	int		position;
	int		min;
	int		stack_len;
	t_stack	*first;

	first = *stack;
	position = 1;
	min = 2147483647;
	stack_len = ft_stcksize(*stack);
	while (position <= stack_len)
	{
		min = find_min(first, min);
		while (first)
		{
			if (first->content == min)
				first->position = position;
			first = first->next;
		}
		first = *stack;
		position++;
	}
}
