#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * struct builtins - builtin command and functions for shell
 * @cmd: command name
 * @f: function pointer to builtin functions
 */
typedef struct builtins
{
	char *cmd;
	int (*f)(char **args, char **env);
} built_t;

int prompt(char **ptr);

/* Function declarations for builtin shell commands */
int herban_env(char **args, char **envp);
int herban_exit(char **args, char **envp);
int herban_built(char **args, char **envp);

void free_array(char **array);
void free_cptrn(int, const unsigned int n, ...);
char *str_concat(char *s1, char *s2);
void check_path(char **string, char **envp);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name, char **envp);
int _strcmp2(const char *s1, const char *s2);
char **strtow(char *str);
void get_word(char **array, char *str);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int word_count(char *str);
void cpy_str(int end, char *s, char **word_box);
void signal_handler(int signo);
void err_exit(char *, int status);
int _atoi(char *s);

#endif
