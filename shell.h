#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* error.c */
void check_err(void);

/* parser.c */
void get_input(void);
char **tokenizer(char *lineptr, ssize_t charc);

/* strings.c */
char *_strcpy(char *dest, char *src);










#endif /*SHELL_H*/
