#include "shell.h"

/**
 * check_err - checks for getline error or EOF or C-d
 *
 * return:
 */
int check_err()
{
    char *lineptr;
    size_t n = 0; /*initial buffer size resizable by getline to accommodate the input. should be charc + 1*/
    ssize_t charc = 0/*actual number of characters getline read from the input stream.*/;

      /*getline puts what was typed in into lineptr*/
      charc = getline(&lineptr, &n, stdin);
       /* check if the getline function failed or reached EOF or user use CTRL + D */
      /*getline returns the total number of characters that were read by the function or -1 on error*/
      if (charc == -1)
      {
          free(lineptr);
          return (-1);
      }



      free(lineptr);
     return (0);

}

