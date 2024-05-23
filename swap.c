/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:43:06 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:17:26 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_node **a_or_b)
{
	t_node	*first;
	t_node	*second;

	if (*a_or_b && ((*a_or_b)->next))
	{
		first = *a_or_b;
		second = (*a_or_b)->next;
		first->next = second->next;
		first->prev = second;
		if (second->next)
			second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		(*a_or_b) = second;
		return (1);
	}
	return (0);
}

void	sa(t_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	if (swap(a) && swap(b))
		ft_printf("ss\n");
}
