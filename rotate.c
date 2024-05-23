/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:47:00 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:11:46 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_node **a_or_b)
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
		*a_or_b = (*a_or_b)->next;
		(*a_or_b)->prev->next = NULL;
		(*a_or_b)->prev = NULL;
		return (1);
	}
	return (0);
}

void	ra(t_node **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_node **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
}
