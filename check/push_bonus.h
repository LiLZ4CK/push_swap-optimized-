/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:30 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/23 22:18:58 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_BONUS_H
# define PUSH_BONUS_H

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	"../ft_printf/ft_printf.h"
# include	"../get_next_line/get_next_line.h"

typedef struct t_swap
{
	int				stack;
	struct t_swap	*next;
}t_swap;

typedef struct t_stacks
{
	t_swap	*a;
	t_swap	*b;
	int		arg;
}t_stacks;

t_stacks	*stack_init_bonus(t_stacks *p);
void		check_dup_bonus(char *argv[], int j);
int			bonus_atoi(char *str);
void		bonus_lstadd_back(t_swap *lst, t_swap *new);
int			bonus_lstsize(t_swap *lst);
t_swap		*bonus_lstlast(t_swap *lst);
t_swap		*bonus_lstnew(int content);
t_swap		*bonus_lstadd_front(t_swap *lst, t_swap *new);
int			check_sorted_bonus(t_stacks *p);
t_stacks	*bonus_operations(t_stacks *p, char *op);
char		*bonus_substr(char *s, unsigned int start, size_t len);
size_t		bonus_strlen(char *s);
t_stacks	*bonus_operations2(t_stacks *p, char *op);
t_stacks	*fix_zsh_bonus(char *argv[], t_stacks *p);
char		**bonus_split(char *s, char c);
t_stacks	*bonus_main(t_stacks *p, char *argv[], int argc);
t_swap		*swap_a_bonus(t_swap *a);
t_swap		*swap_b_bonus(t_swap *b);
t_stacks	*swap_ab_bonus(t_stacks *p);
t_swap		*push_b_bonus(t_stacks *p);
t_swap		*push_a_bonus(t_stacks *p);
t_swap		*rotate_a_bonus(t_swap *a);
t_swap		*rotate_b_bonus(t_swap *b);
t_stacks	*rotate_ab_bonus(t_stacks *p);
t_swap		*r_rotate_a_bonus(t_swap *a);
t_swap		*r_rotate_b_bonus(t_swap *b);
t_stacks	*r_rotate_ab_bonus(t_stacks *p);
t_swap		*sub_three(t_swap	*a);
int			le_index(int i, t_swap *a);
int			low_find(t_swap *a);
t_swap		*push_three(t_swap *a);
t_stacks	*push_five2(t_stacks *p);
t_stacks	*push_five(t_stacks *p, int i);
void		bonus_herror(int i);
int			ps_isdigit(char c);
int			le_len(t_swap *a);
t_stacks	*sort_tab(t_stacks *p);
void		ps_looot(t_stacks *p);
t_stacks	*get_lower(t_stacks *p, int low);
t_swap		*get_highest(t_swap *b, int i);
t_stacks	*ps_indixing(t_stacks *p);
int			bonus_strncmp(char *str1, char *str2);

#endif