/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calories.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:35:09 by practical         #+#    #+#             */
/*   Updated: 2022/12/02 13:56:54 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	int calories = 0;
	int highest = 0;
	int index = 0;

	char buf[9];
	char c;

	FILE *input = fopen("input.txt", "r");		// Read from file

	while((c = getc(input)) != EOF)				// While we didnt hit end of file
	{
		if (c == '\n')							// reading each line
		{
			if (index != 0)
			{
				int scancal;
				sscanf(buf, "%d", &scancal);	// scan line in buffer for decimal integer, add to calories
				memset(buf, '\0', sizeof(buf));	// fills buffer with null character (in case previous int had more figs)
				calories += scancal;
				index = 0;
			}
			else 
			{
				if (calories > highest)			// if current calories are highest, make it the new max
					highest = calories;
				calories = 0;
			}
		}
		else
		{
			buf[index] = c;
			index++;
		}
	}
	
	printf("%d \n", highest);

	return (0);
}
