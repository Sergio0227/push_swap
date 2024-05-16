/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:27:11 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/16 15:43:11 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				nbr;
	int				init_index;
	struct s_node	*node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

int				init_a(t_node **a, char **argv);
void				del_args(char **argv, int argc, int flag);
void				append_nbr(t_node **a, int nbr, int index);
t_node				*get_last_nbr(t_node *a);
long				ft_atol(const char *nptr);
bool				sorted(t_node *a);
bool				duplicated(t_node *a, int nbr);
void				free_stack(t_node **a);
void				print_stack(t_node *a);
void				swap(t_node **a_or_b);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
int					arg_error(char **argv, int argc);
void				sort(t_node **a, t_node **b, int nb_elements);

#endif