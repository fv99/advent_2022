/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calories_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:57:27 by practical         #+#    #+#             */
/*   Updated: 2022/12/02 16:01:04 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	int calories = 0;
	int highest[3] = {0,0,0};
	int index = 0;

	char buf[9];
	char c;

	FILE *input = fopen("input.txt", "r");		// Read from file

	while((c = getc(input)) != EOF)				// While we didnt hit end of file
	{
		if (c == '\n')							// reading each line
		{
			if (index != 0)						// if were not on empty line
			{
				int scancal;
				sscanf(buf, "%d", &scancal);	// scan line in buffer for decimal integer, add to calories
				memset(buf, '\0', sizeof(buf));	// fills buffer with null character (in case previous int had more figs)
				calories += scancal;
				index = 0;
			}
			else 
			{
				if (calories > highest[0])			// if current calories are highest
				{
					highest[2] = highest [1];		// move it down the list
					highest[1] = highest [0];
					highest[0] = calories;
				}
				else if (calories > highest[1])		// if its second highest, ditto
				{
					highest[2] = highest[1];
					highest[1] = calories;
				}
				else if (calories > highest [2])
					highest[2] = calories;
				calories = 0;
			}
		}
		else
		{
			buf[index] = c;
			index++;
		}
	}
	
	printf("Highest: %d \n", highest[0]);
	printf("Second: %d \n", highest[1]);
	printf("Third: %d \n", highest[2]);
	printf("Sum: %d \n", highest[0]+highest[1]+highest[2]);
	
	return (0);
}
