/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:26:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/23 18:03:19 by sandre-a         ###   ########.fr       */
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
		del_args(argv, 0);
	init_a(&a, argv);
	if (argc == 2)
		del_args(argv, 1);
	if (!sorted(a))
		sort(&a, &b);
	free_stack(&a);
	return (0);
}

int	arg_error(char **argv, int argc)
{
	int	i;
	int	x;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
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

void	del_args(char **argv, int flag)
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
