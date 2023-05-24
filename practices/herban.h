#ifndef HERBAN_H
#define HERBAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <string.h>

char **strtow(char *str);
void cpy_str(int end, char *s, char **word_box);
int word_count(char *str);
void get_word(char **words, char *str);

#define MAX_CMD_LEN 100

#endif
