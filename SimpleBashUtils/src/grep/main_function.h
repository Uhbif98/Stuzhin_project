#ifndef MAIN_FUNCTION_H
#define MAIN_FUNCTION_H
#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

struct file_options {
  bool e;
  bool i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
  bool o;
  int options_cnt;
  int cnt_pattern;
};

struct grep_options {
  size_t line;
  int cnt_match_line;
  int cnt_line;
  int f_ind;
};

FILE *f_reader(char *f_path);
FILE *f_options_s(char *argv, struct file_options *f_options);
int64_t f_counter(FILE *f);
void show_nonprinting(char c);
char **parsing_options(int argc, char **argv, char *short_options,
                       struct file_options *f_options);

void switch_case_options(int rez, char ***pattern,
                         struct file_options *f_options);

void option_e(char ***pattern, struct file_options *f_options);
void option_f(char ***pattern, struct file_options *f_options);

int get_regex_status(char **pattern, char *buffer,
                     struct file_options *f_options);

int print_result_grep(int status, struct grep_options *g_options, int argc,
                      char *argv, char *buffer, struct file_options *f_options);

#endif