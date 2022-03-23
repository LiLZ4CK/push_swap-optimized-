/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ab_hermanos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:03:26 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/19 00:27:02 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_bonus.h"

t_stacks	*swap_ab_bonus(t_stacks *p)
{
	p->a = swap_a_bonus(p->a);
	p->b = swap_b_bonus(p->b);
	return (p);
}

t_stacks	*rotate_ab_bonus(t_stacks *p)
{
	p->a = rotate_a_bonus(p->a);
	p->b = rotate_b_bonus(p->b);
	return (p);
}

t_stacks	*r_rotate_ab_bonus(t_stacks *p)
{
	p->a = r_rotate_a_bonus(p->a);
	p->b = r_rotate_b_bonus(p->b);
	return (p);
}
