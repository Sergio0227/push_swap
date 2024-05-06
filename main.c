/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:26:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/06 18:04:31 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2 || argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		del_arg_zero(argv, argc);
	init_a(&a, argv);
	while (a != NULL)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
	return (0);
}

void	del_arg_zero(char **argv, int argc)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = argv[i + 1];
		i++;
	}
}

void	init_a(t_node **a, char **argv)
{
	long	nbr;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		append_nbr(a, (int)nbr);
		argv++;
	}
}

void	append_nbr(t_node **a, int nbr)
{
	t_node	*new;
	t_node	*last;

	last = get_last_nbr(*a);
	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->nbr = nbr;
	if (!last)
		*a = new;
	else
		last->next = new;
	new->next = NULL;
}

t_node	*get_last_nbr(t_node *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
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

