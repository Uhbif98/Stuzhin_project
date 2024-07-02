#ifndef MAIN_FUNCTION_H
#define MAIN_FUNCTION_H

#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

struct file_options {
  bool b;
  bool n;
  bool s;
  bool e;
  bool t;
  bool v;
  int options_cnt;
};

FILE *f_reader(char *f_path);
int64_t f_counter(FILE *f);
void show_nonprinting(char c);
struct file_options parsing_options(int argc, char **argv, char *short_options,
                                    struct option *long_options);
void cat_print(char *buffer, struct file_options f_options);

#endif