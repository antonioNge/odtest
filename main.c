/* main.c - main function file
 * Copyright (C) 2014 Adrian Alonso <aalonso00@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with self library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>

#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE  (1)
#endif

int
main(int argc, char **argv)
{
    FILE *fd;
    char *file = NULL;
    char buff[16];
    int is_end_of_file = FALSE;
    int file_index = 0;
    int buffer_index = 0;

    if(argc != 2)
    {
        printf ("Usage: %s <file>\n", argv[0]);
        exit (1);
    }

    file = (char *)argv[1];

    fd = fopen(file, "r" );

    if(fd < 0)
    {
        printf ("Error");
        exit(1);
    }

    /* Print complete file content following od hex format */
    /* od -A x -t x1z -v file.dat */

    printf( "The hexadecimal format output of the command od for file %s is:\n\n", file);

    while (FALSE == is_end_of_file)
    {
        printf("%06x ", file_index);
        for(buffer_index = 0; buffer_index < 16; buffer_index++)
        {
           	buff[buffer_index] = getc(fd); 
           	if(EOF == buff[buffer_index])
           	{
				is_end_of_file = TRUE;
				buff[buffer_index] = '\0';
               	printf("   ");
              
           	}
           	else
           	{
           		printf("%02x ", (int)buff[buffer_index]);
           		file_index++;
           		if('\n' == buff[buffer_index])
           		{
           			buff[buffer_index] = '.';
           		}
           	}
        }
        printf(">");
        printf("%s",buff);    	
        printf("<\n"); 
    }

    close (fd);

    return 0;
}
