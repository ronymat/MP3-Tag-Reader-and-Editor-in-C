#ifndef MP3_H
#define MP3_H

#include<stdio.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

void print_help(void);
void invalid_print(void);
int mp3_view(char *argv[]);
int mp3_edit(char *argv[],char *str_op);

#endif