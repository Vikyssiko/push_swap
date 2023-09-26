/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:06:55 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/22 22:13:37 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

void	exit_and_clean(t_stack **stack)
{
	if (stack)
		clean_stack(stack);
	write(2, "Error\n", 6);
	exit(0);
}

void	exit_with_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	clean_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack));
		*stack = temp;
	}
}

void	clean_both_stacks(t_stack *a, t_stack *b)
{
	clean_stack(&a);
	clean_stack(&b);
}

int	main(int args, char *argv[])
{
	t_stack	*b;
	t_stack	*stack;
	char	*str;

	b = NULL;
	stack = put_to_stack(args, argv);
	check_dup(stack);
	find_position_for_all(&stack);
	str = get_next_line(0);
	while (str)
	{
		if (!check_instructions(str, &stack, &b))
		{
			clean_both_stacks(stack, b);
			free(str);
			exit_with_error();
		}
		free(str);
		str = get_next_line(0);
	}
	check_sorted(&stack, &b);
	clean_both_stacks(stack, b);
}
