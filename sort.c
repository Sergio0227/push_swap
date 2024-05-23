/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:31:44 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/23 21:47:37 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(int *arr, int size)
{
	int	result;

	if (size % 2 == 0)
		result = ((arr[size / 2 - 1] + arr[size / 2]) / 2);
	else
		result = (arr[size / 2]);
	free(arr);
	return (result);
}

int	set_below_median(t_node *a, int median)
{
	int	below;

	below = 0;
	while (a)
	{
		if (a->nbr >= median)
			a->above_medium = true;
		else
		{
			a->above_medium = false;
			below++;
		}
		a = a->next;
	}
	return (below);
}

int	set_above_median(t_node *a, int median)
{
	int	above;

	above = 0;
	while (a)
	{
		if (a->nbr >= median)
		{
			a->above_medium = true;
			above++;
		}
		else
			a->above_medium = false;
		a = a->next;
	}
	return (above);
}

void	bubbleSort(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
int	*copy_and_sort(t_node *a)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * count_nodes(a));
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[i] = a->nbr;
		a = a->next;
		i++;
	}
	bubbleSort(arr, i);
	return (arr);
}

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

void	push_back(t_node **a, t_node **b)
{
	int	*arr;
	int	above;
	
	if (!sorted(*a))
		sa(a);
	while (count_nodes(*b))
	{
		arr = copy_and_sort(*b);
		above = set_above_median(*b, get_median(arr, count_nodes(*b)));
		while (above)
		{
			if ((*b)->above_medium == true)
			{
				above--;
				pa(a, b);
			}
			else
				rb(b);
		}
	}
}

void	sort(t_node **a, t_node **b)
{
	int	*arr;
	int	below;

	if (count_nodes(*a) <= 3)
		sort_three(a);
	else
	{
		while (count_nodes(*a) != 2)
		{
			arr = copy_and_sort(*a);
			below = set_below_median(*a, get_median(arr,
						count_nodes(*a)));
			while (below)
			{
				if ((*a)->above_medium == false)
				{
					below--;
					pb(a, b);
				}
				else
					ra(a);
			}
		}
		push_back(a, b);
	}
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
