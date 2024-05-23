/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:14:24 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/23 14:18:52 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_node **a_or_b)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *a_or_b;
	max = head->nbr;
	max_bits = 0;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = -1;
	temp = *stack_a;
	size = count_nodes(temp);
	max_bits = get_max_bits(stack_a);
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp = *stack_a;
			if (((temp->nbr >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (count_nodes(*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}