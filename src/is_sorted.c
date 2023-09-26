/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:00:40 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/23 14:00:40 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	is_sorted(t_stack *stack)
{
	long	position;

	position = 0;
	while (stack)
	{
		if (stack->position <= position)
			return (0);
		position = stack->position;
		stack = stack->next;
	}
	return (1);
}
