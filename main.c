/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:26:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 18:01:44 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (arg_error(argv, argc))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		del_args(argv, argc, 0);
	init_a(&a, argv);
	if (argc == 2)
		del_args(argv, argc, 1);
	if (!sorted(a))
		sort(&a, &b);
	free_stack(&a);
	return (0);
}

int	arg_error(char **argv, int argc)
{
	int	i;
	int	x;

	if (argc < 2 || argc == 2 && !argv[1][0])
	{
		ft_printf("Error\n");
		return (1);
	}
	x = 0;
	if (argc > 2)
		while (argv[++x])
		{
			i = 0;
			while (argv[x][i])
			{
				if (argv[x][i] == 32 && argv[x][i] != '+' && argv[x][i] != '-')
				{
					ft_printf("Error\n");
					return (1);
				}
				i++;
			}
		}
	return (0);
}

void	del_args(char **argv, int argc, int flag)
{
	int	i;

	if (!flag)
	{
		i = 0;
		while (argv[i])
		{
			argv[i] = argv[i + 1];
			i++;
		}
	}
	else
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			argv[i] = NULL;
			i++;
		}
		free(argv);
	}
}

void	init_a(t_node **a, char **argv)
{
	long	nbr;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		if (!duplicated(*a, (int)nbr) && (nbr >= INT_MIN && nbr <= INT_MAX))
			append_nbr(a, (int)nbr);
		else
		{
			ft_printf("Error\n");
			free_stack(a);
			break ;
		}
		argv++;
	}
}


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

void	print_stack(t_node *a)
{
	while (a)
	{
		ft_printf("%d", a->nbr);
		if (a->next)
			ft_printf(" ");
		a = a->next;
	}
}

t_node	*get_min(t_node *a_or_b)
{
	t_node	*min_node;

	if (!a_or_b)
		return (NULL);
	min_node = a_or_b;
	while (a_or_b)
	{
		if (a_or_b->nbr < min_node->nbr)
			min_node = a_or_b;
		a_or_b = a_or_b->next;
	}
	return (min_node);
}

t_node	*get_max(t_node *a_or_b)
{
	t_node *max_node;

	if (!a_or_b)
		return (NULL);
	max_node = a_or_b;
	while (a_or_b)
	{
		if (a_or_b->nbr > max_node->nbr)
			max_node = a_or_b;
		a_or_b = a_or_b->next;
	}
	return (max_node);
}