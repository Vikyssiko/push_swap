/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:48:50 by vkozlova          #+#    #+#             */
/*   Updated: 2023/08/12 17:48:50 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	get_num(char *str, int sign, t_stack **stack)
{
	long	num;
	int		result;

	num = 0;
	if (!(*str))
		exit_and_clean(stack);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
			exit_and_clean(stack);
		str++;
	}
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1)
		|| (*str && (*str < '0' || *str > '9')))
		exit_and_clean(stack);
	result = num * sign;
	return (result);
}

int	check_num(char *str, t_stack **stack)
{
	int	sign;
	int	result;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!(*str))
			exit_and_clean(stack);
	}
	result = get_num(str, sign, stack);
	return (result);
}

t_stack	*put_to_stack(int args, char *argv[])
{
	int		num;
	t_stack	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (args > 1)
	{
		num = check_num(argv[i++], &stack);
		stack = ft_stcknew(num);
	}
	while (i < args)
	{
		num = check_num(argv[i++], &stack);
		ft_stckadd_back(&stack, ft_stcknew(num));
	}
	if (!stack)
		exit(0);
	return (stack);
}

void	check_dup(t_stack *stack)
{
	t_stack	*compared;
	t_stack	*temp;

	temp = stack;
	compared = stack;
	stack = stack->next;
	while (stack && compared)
	{
		while (stack)
		{
			if (stack->content == compared->content)
				exit_and_clean(&temp);
			stack = stack->next;
		}
		compared = compared->next;
		stack = compared->next;
	}
}
