/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:01:17 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 19:03:25 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_nbr(t_node **a, int nbr)
{
	t_node	*new;
	t_node	*last;

	last = last_node(*a);
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->nbr = nbr;
	if (!last)
	{
		new->prev = NULL;
		*a = new;
	}
	else
	{
		new->prev = last;
		last->next = new;
	}
	new->next = NULL;
}

t_node	*last_node(t_node *a_or_b)
{
	if (!a_or_b)
		return (NULL);
	while (a_or_b->next)
		a_or_b = a_or_b->next;
	return (a_or_b);
}

bool	duplicated(t_node *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->nbr == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}

void	free_stack(t_node **a)
{
	t_node	*current;
	t_node	*next;

	current = *a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}
