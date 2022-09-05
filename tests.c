/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:58:33 by vegret            #+#    #+#             */
/*   Updated: 2022/09/05 16:58:33 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

int	main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	char src[] = "test";
	char dest[] = "test";
	int n = 5;
	
	printf("FT: %s\n", ft_strtrim("wsh la street", " "));
	
	return (0);
}
