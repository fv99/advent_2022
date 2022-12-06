/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rucksack_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:25:17 by practical         #+#    #+#             */
/*   Updated: 2022/12/06 12:34:09 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

int get_priority(char c)
{
	if (c > 96 && c < 123)
		return (c - 96);
	else if (c > 64 && c < 91)
		return (c - 38);
	else
	{
		printf("ERROR: invalid input\n");
		exit (-1);
	}
}

int	main(void)
{
	int counter = 0;
	int count = 0;

	char buf[64];
	char buf1[64];
	char buf2[64];
	char buf3[64];

	FILE *input = fopen("input.txt", "r");		

	while(fgets(buf, sizeof(buf), input))		// read each line into buffer
	{	
		char common;
		
		if (counter == 0)
		{
			buf[strlen(buf) - 1] = '\0';		
			strcpy(buf1, buf);					// copy the string into buf1
			counter++;
		}
		else if (counter == 1)
		{
			buf[strlen(buf) - 1] = '\0';
			strcpy(buf2, buf);					// copy the string into buf2
			counter++;
		}
		else if (counter == 2)
		{
			buf[strlen(buf) - 1] = '\0';
			strcpy(buf3, buf);					// copy the string into buf3

			for(int i = 0; buf1[i]; i++)		// check for the identical letter
			{
				for (int x = 0; buf2[x]; x++)
				{
					for (int y = 0; buf3[y]; y++)
					{
						if (buf1[i] == buf2[x] && buf2[x] == buf3[y])
							common = buf1[i];
					}
				}
			}
			count += get_priority(common);
			counter = 0;
		}
	}
	
	printf("Your priorities part two:  %i \n", count);
	
	fclose(input);
	return (0);
}
