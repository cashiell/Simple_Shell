#ifndef HERBAN_H
#define HERBAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

char **strtow(char *str);
void cpy_str(int end, char *s, char **word_box);
int word_count(char *str);
void get_word(char **words, char *str);

#define MAX_CMD_LEN 100

/**
 * struct builtins - builtin command and functions for shell
 * @cmd: command name
 * @f: function pointer
 *
 * Description: struct for builtin functs
 */
typedef struct builtins
{
	char *cmd;
	int (*f)(char **args, char **env);
} built_t;

int herban_env(char **args, char **env);
int herban_exit(char **args, char **env);
int herban_built(char **args, char **env);

void free_array(char **array);
void free_cptrn(int, const unsigned int n, ...);

char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name, char **env);
char *str_concat(char *s1, char *s2);

int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strcmp2(const char *s1, const char *s2);

void check_path(char **string, char **env);
void signal_handler(int signo);
void err_exit(char *, int status);

int prompt(char **ptr);
int _atoi(char *s);

#endif
