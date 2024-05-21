/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:31:44 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/20 19:30:34 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nodes(t_node *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	sort(t_node **a, t_node **b, int *bits)
{
	if (count_nodes(*a) <= 3)
		sort_three(a);
	else
		radix_sort(a, b);
}

void	sort_three(t_node **a)
{
	if (count_nodes(*a) > 2)
	{
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
			ra(a);
		else if ((*a)->next->nbr > (*a)->nbr
			&& (*a)->next->nbr > (*a)->next->next->nbr)
			rra(a);
	}
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_rest(t_node **a, t_node **b, int *bits)
{
	t_node	*min;
	t_node	*max;
	int		min_bits;
	int		max_bits;

	max = get_max(*a);
	min = get_min(*a);
	min_bits = 0;
	while (count_nodes(*a))
	{
		while (bits[min_bits])
		{
			if ((*a)->bits == min_bits)
			{
				pb(a, b);
				bits[min_bits]--;
			}
			else
				ra(a);
		}
		min_bits++;
	}
	radix_sort(a, b);
}
