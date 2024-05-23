/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:58:27 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:10:12 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate(t_node **a_or_b)
{
	t_node	*temp;

	if (*a_or_b && (*a_or_b)->next)
	{
		temp = *a_or_b;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = *a_or_b;
		(*a_or_b)->prev = temp;
		*a_or_b = temp;
		temp = (*a_or_b)->prev;
		temp->next = NULL;
		(*a_or_b)->prev = NULL;
		return (1);
	}
	return (0);
}

void	rra(t_node **a)
{
	if (rev_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	if (rev_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	if (rev_rotate(a) && rev_rotate(b))
		ft_printf("rrr\n");
}
