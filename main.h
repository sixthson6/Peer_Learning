#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define RESET_BUF -1
#define MAX_BUFFER_SIZE 1024
#define CUSTOM_UNSIGNED 2
#define CUSTOM_LOWERCASE 1
#define BUFFER_READ 1024

/**
 * struct num_str - linked list
 * @num: number
 * @str: string
 * @next: next node
 */

typedef struct num_str
{
            	int num;
            	char *str;
            	struct num_str *next;
} list_struct;

/**
 * struct program_info - pseudo-arguements
 * @arg: a string from getline with arg
 * @argv: arr of str generated from arg
 * @path: path
 * @argc: arg count
 * @line_count: the error count
 * @err_num: error code
 * @linecount_flag: if ...
 * @fname: program filename
 * @env: linked list 
 * @environ: custom modified copy env
 * @history: history
 * @alias: alias
 * @env_changed: on if environ was changed
 * @status: the rturn status
 * @cmd_buf: adr of ptr to cmd
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: fd 
 * @histcount: history
 */

 typedef struct program_info
{
            	char *arg;
            	char **argv;
            	char *path;
            	int argc;
            	unsigned int line_count;
            	int err_num;
            	int linecount_flag;
            	char *fname;
            	list_t *env;
            	list_t *history;
            	list_t *alias;
            	char **environ;
            	int env_changed;
            	int status;
            	char **cmd_buf;
            	int cmd_buf_type;
            	int readfd;
            	int histcount;
} info_struct;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - builtin string
 * @type: the builtin cmd
 * @func: function
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/*printers.c*/
void error_puts(char *string);
int error_putchar(char charac);
/*histories.c*/
int history_print(info_struct *information);
int build_history_list(info_struct *information, char *buffer, int lcount);
int history_renumber(info_struct *information);
int history_write(info_struct *information);
char *fetch_history(info_struct *information);
/*loops.c*/
int hash_batch(info_struct *information, char **agv);

/*string1.c*/
char *custom_strcat(char *dest, char *src);
int custom_strlen(char *str);
int custom_strcmp(char *str1, char *str2);
char *needle_check(const char *search_string, const char *sub_str);
/*string2.c*/
char *custom_strcpy(char *d, char *s);
int custom_putchar(char c);
void custom_puts(char *s);
char *custom_strdup(const char *s);
/*string3.c*/
char *custom_strncat(char *d, char *s, int bytes);
char *custom_strchr(char *str, char c);
char *custom_strncpy(char *d, char *s, int bytes);

/*error_printer.c*/
char *conv_num(long int num, int b, int f);
int error_atoi(char *str);
void error_print(info_struct *information, char *str);
int _print(int msg, int filedesc);
void hush_comments(char *buffer);

/*custom_getline.c*/
int custom_getline(info_struct *information, char **ptr, size_t *size);
void signal_helper(int sig);
ssize_t buffer_inbut(info_struct *information, char **buffer, size_t *length);
ssize_t obtain_input(info_struct *information);

/*get_info*/
void info_start(info_struct *information, char **agv);
void reset_info(info_struct *information);
void free1(info_struct *information, int entire);

/*interactive_mode.c*/
int interactive_mode(info_struct *information);
int custom_atoi(char *str);
int custom_isalpha(int c);

/*custom_strtok.c*/
char **custom_strtow(char *str, char *delim);
char **custom_strtow2(char *str, char delim);

/*utils.c*/
int search_chain(info_struct *information, char *buffer, size_t *pos);
void check_chain(info_struct *information, char *buffer, size_t *pos, size_t i, size_t length);
int alias_exchange(info_struct *information);
int vars_exchange(info_struct *information);
int string_exchange(char **old, char *new);

/*env_vars.c*/
int custom_env_list(info_struct *information);
int custom_myunsetenv(info_struct *information);
int custom_mysetenv(info_struct *information);
char *get_environ(info_struct *information, const char *name);
int custom_env(info_struct *information);

/*new9_1.c*/

/*new2.c*/
custom_unset_alias(info_struct *commandInfo, char *text);
int custom_myalias(info_struct *commandInfo);
int custom_print_alias(list_struct *node);
int custom_set_alias(info_struct *commandInfo, char *text);
int custom_my_history(info_struct *commandInfo);
