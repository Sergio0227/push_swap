/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:43:06 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/16 14:38:48 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **a_or_b)
{
	t_node	*first;
	t_node	*second;

	if (!*a_or_b || !((*a_or_b)->next))
		return ;
	first = *a_or_b;
	second = (*a_or_b)->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	(*a_or_b) = second;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss");
}