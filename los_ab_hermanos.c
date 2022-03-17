/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   los_ab_hermanos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:03:26 by zwalad            #+#    #+#             */
/*   Updated: 2022/03/16 22:27:40 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_stacks	*swap_ab(t_stacks *p)
{
	p->a = swap_a(p->a);
	p->b = swap_b(p->b);
	ft_printf("ss\n");
	return (p);
}

t_stacks	*rotate_ab(t_stacks *p)
{
	p->a = rotate_a(p->a);
	p->b = rotate_b(p->b);
	ft_printf("rr\n");
	return (p);
}

t_stacks	*r_rotate_ab(t_stacks *p)
{
	p->a = r_rotate_a(p->a);
	p->b = r_rotate_b(p->b);
	ft_printf("rrr\n");
	return (p);
}
