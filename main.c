#include "shell.h"

/**
 * main - main function
 * @ac: number of arguments passed to function
 * @argv: array of arguments passed to function
 *
 * Return: 0 on Success
 */

int main(int ac, char **argv)
{
    long /*ssize_t*/ gi;
    char *prompt = "$ ";

    while (1)
    {
      write(STDOUT_FILENO, prompt, 2);
      gi = check_err();


      printf("%ld\n", gi);
    }

    (void)ac, (void)argv;
   return (0);
}
