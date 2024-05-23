/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:31:44 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:12:09 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_node *a)
{
	if (!a)
		return (-1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

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

void	sort(t_node **a, t_node **b)
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
