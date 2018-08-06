/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:19:25 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/06 15:25:53 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc > 1)
	{
		s = init_struct();
		s->size = ft_count_args(argv);
		s->stack_a = (int *)malloc(sizeof(int) * s->size);
		s->stack_b = (int *)malloc(sizeof(int) * s->size);
		s->len_a = s->size;
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || ft_is_dup(s)
				|| !ft_read(s))
		{
			write(1, "Error\n", 6);
			ft_free(s);
			return (0);
		}
		if (ft_check_sorted(s) && s->len_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free(s);
	}
	return (0);
}
