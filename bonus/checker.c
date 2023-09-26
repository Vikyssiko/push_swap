/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:18 by vkozlova          #+#    #+#             */
/*   Updated: 2023/09/20 18:54:18 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/header/libft.h"
#include "../header/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (s1 || s2)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	check_instructions(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sb\n"))
		return (swap(b));
	else if (!ft_strcmp(str, "sa\n"))
		return (swap(a));
	else if (!ft_strcmp(str, "pa\n"))
		return (push(a, b));
	else if (!ft_strcmp(str, "pb\n"))
		return (push(b, a));
	else if (!ft_strcmp(str, "ra\n"))
		return (rotate(a));
	else if (!ft_strcmp(str, "rb\n"))
		return (rotate(b));
	else if (!ft_strcmp(str, "rra\n"))
		return (reverse_rotate(a));
	else if (!ft_strcmp(str, "rrb\n"))
		return (reverse_rotate(b));
	else if (!ft_strcmp(str, "rr\n"))
		return (rotate(a) && rotate(b));
	else if (!ft_strcmp(str, "ss\n"))
		return (swap(a) && swap(b));
	else if (!ft_strcmp(str, "rrr\n"))
		return (reverse_rotate(a) && reverse_rotate(b));
	else
		return (0);
}

void	check_sorted(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && ft_stcksize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
