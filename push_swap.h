/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:27:11 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/21 18:00:59 by sandre-a         ###   ########.fr       */
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
	int				bits;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

void				init_a(t_node **a, char **argv);
void				del_args(char **argv, int argc, int flag);
void				append_nbr(t_node **a, int nbr);
t_node				*last_node(t_node *a);
long				ft_atol(const char *nptr);
bool				sorted(t_node *a);
bool				duplicated(t_node *a, int nbr);
void				free_stack(t_node **a);
void				print_stack(t_node *a);
int					arg_error(char **argv, int argc);
void				sort(t_node **a, t_node **b);
void				sort_rest(t_node **a, t_node **b);
void				sort_three(t_node **a);
t_node				*get_min(t_node *a_or_b);
t_node				*get_max(t_node *a_or_b);
void				radix_sort(t_node **stack_a, t_node **stack_b);
int					get_max_bits(t_node **a_or_b);
int					count_nodes(t_node *a);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

#endif