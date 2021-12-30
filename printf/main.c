/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <tlufulua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:18:33 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/30 17:47:22 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);

void	finale(void)
{
	system("leaks ft_printf");
}
int	main()
{
//	atexit(finale);
	printf(" (%i)\n", ft_printf("1: %s\n", "toto"));
	printf(" (%i)\n", printf("2: %s\n", "toto"));
//	printf(" (%i)\n", ft_printf("1: %s\n", 0));
//	printf(" (%i)\n", printf("2: %s\n", 0));
//	printf(" (%i)\n", ft_printf("1: %s\n", "\0"));
//	printf(" (%i)\n", printf("2: %s\n", "\0"));
//	printf(" (%i)\n", ft_printf("1: Magic %s is %d", "number", 42));
//	printf(" (%i)\n", printf("2: Magic %s is %d", "number", 42));
//	printf(" (%i)\n", ft_printf("1: Hexadecimal for %d is %x\n", 42, 42));
//	printf(" (%i)\n", printf("2: Hexadecimal for %d is %x\n", 42, 42));
//	printf(" (%i)\n", ft_printf("1: %d is %x in hex", 0, 0));
//	printf(" (%i)\n", printf("2: %d is %x in hex", 0, 0));
//	printf(" (%i)\n", ft_printf("1: %d is %x in hex", -42, -42));
//	printf(" (%i)\n", printf("2: %d is %x in hex", -42, -42));
//	printf(" (%i)\n", ft_printf("1: %d is %x in hex", -0, -0));
//	printf(" (%i)\n", printf("2: %d is %x in hex", -0, -0));
	return (0);
}
