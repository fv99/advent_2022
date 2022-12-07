/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:57:55 by practical         #+#    #+#             */
/*   Updated: 2022/12/07 15:17:39 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

int	main(void)
{
	int count = 0;
	int overlap = 0;

	char buf[64];

	FILE *input = fopen("input.txt", "r");		

	while(fgets(buf, sizeof(buf), input))		// read each line into buffer
	{	
		char *split = strtok(buf, ",");			// strtok to split buffer by ,

		int a1 = abs(atoi(&split[0]));
		int a2 = abs(atoi(&split[2]));			// convert 1st part of input, abs value

		split = strtok(NULL, ",");				// strtok to point to second part

		int b1 = abs(atoi(&split[0]));
		int b2 = abs(atoi(&split[2]));			// ditto

		if ((b1 >= a1 && b2 <= a2) || (a1 >= b1 && a2 <= b2))
			count++;							

		if ((b1 <= a2 && b1 >= a1) || (a1 <= b2 && a1 >= b1))
			overlap++;
	}
	
	printf("Part one:  %i \n", count);
	printf("Part two:  %i \n", overlap);
	
	fclose(input);
	return (0);
}
