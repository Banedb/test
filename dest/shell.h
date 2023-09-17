#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/* error.c */
int err_gen(char **argv, int err_no);

/*errcode.c */
char *error_127(char **argv);

/* parser.c */
char *get_input(void);
char **tokenizer(char *line);

/* path.c */
char *_which(char *cmd);
char *_getenv(const char *name);

/* strings.c */
void _puts(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

/* strings2.c */
char *_strdup(char *str);
char *_strndup(const char *str, size_t n);
char *myitoa(int num);


/* run.c */
int cmdexe(char **argv, char **envp);

/* env.c */
char **_env(char **envStrings);


/* exit.c */
void exitShell(void);

/* signal.c */
void sig_h(int signum);

/* global variable */
int hist; /* history counter */
char *name;/* name of program */



/**
 * struct env - Allocate memory for the environment variables
 * @key: environ variable
 * @val: environ varaible value.
 */
typedef struct env
{
	char *key;
	char *val;
} env_t;





#endif /*SHELL_H*/
