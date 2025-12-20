/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:21:02 by julauren          #+#    #+#             */
/*   Updated: 2025/12/20 16:27:33 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->nb - 1)
	{
		if (a->list[i] < a->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_stack(t_stack *a)
{
	if (!(ft_stack_sorted(a)))
	{
		a->median = (a->nb - 1) / 2;
		if (a->max > a->median)
		{
			while (a->max < a->nb)
			{
				ft_rotate_a(a);
				(a->max)++;
			}
		}
		else
		{
			while (a->max > 0)
			{
				ft_reverse_rotate_a(a);
				(a->max)--;
			}
		}
	}
}
