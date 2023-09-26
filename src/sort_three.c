/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:17:03 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/23 14:17:03 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	one_operation(t_stack **stack);

void	sort_three(t_stack **stack)
{
	while (!is_sorted(*stack))
		one_operation(stack);
}

void	one_operation(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->position;
	second = (*stack)->next->position;
	third = (*stack)->next->next->position;
	if (second < first && third > first)
		sa(stack);
	else if (first > second && first > third)
		ra(stack);
	else if (second > first && second > third)
		rra(stack);
	else if (third < second && third < first)
		sa(stack);
}
