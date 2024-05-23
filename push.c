/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:58:21 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:06:44 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		temp->next = *b;
		if (*b)
			(*b)->prev = temp;
		*b = temp;
		(*b)->prev = NULL;
		return (1);
	}
	return (0);
}

void	pb(t_node **a, t_node **b)
{
	if (push(a, b))
		ft_printf("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	if (push(b, a))
		ft_printf("pa\n");
}
