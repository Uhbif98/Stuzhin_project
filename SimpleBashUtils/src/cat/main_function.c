#include "main_function.h"

FILE *f_reader(char *f_path) {
  FILE *f;
  if ((f = fopen(f_path, "r")) == NULL) {
    printf("Cannot open file %s.\n", f_path);
  }
  return f;
}

int64_t f_counter(FILE *f) {
  int64_t file_size = 0;
  while (getc(f) != EOF) file_size++;
  rewind(f);
  return file_size;
}

void show_nonprinting(char c) {
  if (c < -96) {
    printf("M-^%c", c + 192);
  } else if (c < 0) {
    printf("M-%c", c + 128);
  } else if (c == 9 || c == 10) {
    printf("%c", c);
  } else if (c < 32) {
    printf("^%c", c + 64);
  } else if (c < 127) {
    printf("%c", c);
  } else {
    printf("^?");
  }
}

struct file_options parsing_options(int argc, char **argv, char *short_options,
                                    struct option *long_options) {
  struct file_options f_options = {0, 0, 0, 0, 0, 0, 1};
  int rez = 0;
  int option_index;
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (rez) {
      case 'b': {
        f_options.b = 1;
        break;
      }
      case 'n': {
        f_options.n = 1;
        break;
      }
      case 's': {
        f_options.s = 1;
        break;
      }
      case 'e': {
        f_options.e = 1;
        f_options.v = 1;
        break;
      }
      case 'E': {
        f_options.e = 1;
        break;
      }
      case 't': {
        f_options.t = 1;
        f_options.v = 1;
        break;
      }
      case 'T': {
        f_options.t = 1;
        break;
      }
      case '?':
        printf("Can't found argument");
        exit(1);
      default: {
      }
    }
    f_options.options_cnt = optind;
  }
  return f_options;
}

void cat_print(char *buffer, struct file_options f_options) {
  for (int k = 0; buffer[k] != '\0'; k++) {
    if (f_options.e && buffer[k] == '\n') {
      printf("$");
    }
    if (f_options.t && buffer[k] == 9) {
      printf("^I");
    } else if (f_options.v)
      show_nonprinting(buffer[k]);
    else
      printf("%c", buffer[k]);
  }
}