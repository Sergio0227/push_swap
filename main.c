/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:26:56 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/05 16:46:53 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;

	if (argc < 2 || argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		del_arg_zero(argv, argc);
	
}

void	del_arg_zero(char **argv, int argc)
{
	int i;

	i = 0;
	while (argv[i])
	{
		argv[i] = argv[i + 1];
		i++;
	}
}