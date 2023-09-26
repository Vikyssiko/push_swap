/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:44:29 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/12 19:44:29 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

t_stack	*ft_stcknew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->a_begin = 0;
	node->a_end = 0;
	node->position = 0;
	node->b_begin = 0;
	node->b_end = 0;
	node->operations = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_stckadd_front(t_stack **stck, t_stack *new)
{
	new->next = *stck;
	(*stck)->prev = new;
	*stck = new;
}

t_stack	*ft_stcklast(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_stcksize(t_stack *stck)
{
	int	size;

	size = 0;
	while (stck != NULL)
	{
		stck = stck->next;
		size++;
	}
	return (size);
}

void	ft_stckadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}
