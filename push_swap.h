/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:47 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/15 21:39:04 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	"ft_printf/ft_printf.h"

typedef struct t_swap
{
	int				stack;
	struct t_swap	*next;
}t_swap;

typedef struct t_stacks
{
	t_swap	*a;
	t_swap	*b;
	t_swap	*free_a;
	t_swap	*free_b;
	int		*tab;
	int		arg;
}t_stacks;

int			check_dup2(char *str1, char *str2);
size_t		ps_strlen(char *s);
int			ps_atoi(char *str);
void		check_dup(char *argv[]);
void		ps_lstadd_back(t_swap *lst, t_swap *new);
int			ps_lstsize(t_swap *lst);
t_swap		*ps_lstlast(t_swap *lst);
t_swap		*ps_lstnew(int content);
t_swap		*ps_lstadd_front(t_swap *lst, t_swap *new);
t_swap		*swap_a(t_swap *a);
t_swap		*swap_b(t_swap *b);
t_stacks	*swap_ab(t_stacks *p);
t_swap		*push_b(t_stacks *p);
t_swap		*push_a(t_stacks *p);
t_swap		*rotate_a(t_swap *a);
t_swap		*rotate_b(t_swap *b);
t_stacks	*rotate_ab(t_stacks *p);
t_swap		*r_rotate_a(t_swap *a);
t_swap		*r_rotate_b(t_swap *b);
t_stacks	*r_rotate_ab(t_stacks *p);
char		*ps_strdup(char *s1);
char		**ps_split(char *s, char c);
t_swap		*sub_three(t_swap	*a);
t_stacks	*stack_init(t_stacks *p, char *argv[], int argc);
int			le_index(int i, t_swap *a);
int			low_find(t_swap *a);
t_swap		*push_three(t_swap *a);
t_stacks	*push_five2(t_stacks *p);
t_stacks	*push_five(t_stacks *p, int i);
int			check_sorted(t_stacks *p);
void		herror(int i);
int			ps_isdigit(char c);
char		*ps_substr(char *s, unsigned int start, size_t len);
int			le_len(t_swap *a);
t_stacks	*sort_tab(t_stacks *p);
void		ps_looot(t_stacks *p);
t_stacks	*get_lower(t_stacks *p, int low);
t_swap		*get_highest(t_swap *b, int i);
t_stacks	*ps_indixing(t_stacks *p);

#endif