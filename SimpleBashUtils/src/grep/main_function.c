#include "main_function.h"

FILE *f_reader(char *f_path) {
  FILE *f;
  if ((f = fopen(f_path, "r")) == NULL) {
    printf("No such file or directory %s.\n", f_path);
  }
  return f;
}

FILE *f_options_s(char *argv, struct file_options *f_options) {
  FILE *f;
  if (f_options->s) {
    f = fopen(argv, "r");
  } else
    f = f_reader(argv);
  return f;
}

char **parsing_options(int argc, char **argv, char *short_options,
                       struct file_options *f_options) {
  char **pattern = malloc(sizeof(char *));
  pattern[0] = NULL;
  int rez = 0;
  while ((rez = getopt(argc, argv, short_options)) != -1) {
    switch_case_options(rez, &pattern, f_options);
  }
  if (pattern[0] == NULL && argv[optind] != NULL) {
    if (!f_options->e && !f_options->f) {
      pattern[0] = malloc(strlen(argv[optind]) + 1);
      strcpy(pattern[0], argv[optind]);
    }
  }
  return pattern;
}

void switch_case_options(int rez, char ***pattern,
                         struct file_options *f_options) {
  switch (rez) {
    case 'e': {
      option_e(pattern, f_options);
      break;
    }
    case 'i': {
      f_options->i = 1;
      break;
    }
    case 'v': {
      f_options->v = 1;
      break;
    }
    case 'c': {
      f_options->c = 1;
      break;
    }
    case 'l': {
      f_options->l = 1;
      break;
    }
    case 'n': {
      f_options->n = 1;
      break;
    }
    case 'h': {
      f_options->h = 1;
      break;
    }
    case 's': {
      f_options->s = 1;
      break;
    }
    case 'f': {
      option_f(pattern, f_options);
      break;
    }
    case 'o': {
      f_options->o = 1;
      break;
    }
    case '?':
      printf("Can't found argument");
      exit(1);
    default: {
    }
  }
  f_options->options_cnt++;
}

void option_e(char ***pattern, struct file_options *f_options) {
  f_options->e = 1;
  if (f_options->cnt_pattern > 0) {
    *pattern = realloc(*pattern, (f_options->cnt_pattern + 1) * sizeof(char *));
  }
  (*pattern)[f_options->cnt_pattern] = malloc(strlen(optarg) + 1);
  strcpy((*pattern)[f_options->cnt_pattern], optarg);
  f_options->cnt_pattern++;
}

void option_f(char ***pattern, struct file_options *f_options) {
  f_options->f = 1;
  FILE *f = f_reader(optarg);
  if (f != NULL) {
    char *buffer = NULL;
    size_t line = 0;
    while (getline(&buffer, &line, f) != -1) {
      int len = strlen(buffer);
      if (buffer[len - 1] == '\n') buffer[len - 1] = '\0';
      if (f_options->cnt_pattern > 0) {
        *pattern =
            realloc(*pattern, (f_options->cnt_pattern + 1) * sizeof(char *));
      }
      (*pattern)[f_options->cnt_pattern] = malloc(line + 1);
      strcpy((*pattern)[f_options->cnt_pattern], buffer);
      f_options->cnt_pattern++;
    }
    free(buffer);
    fclose(f);
  }
}

int get_regex_status(char **pattern, char *buffer,
                     struct file_options *f_options) {
  int status;
  regex_t regex;
  if (f_options->i == 1) {
    status = regcomp(&regex, pattern[0], REG_ICASE);
    if (status == 0) {
      status = regexec(&regex, buffer, 0, NULL, 0);
      regfree(&regex);
    }
  } else if (f_options->v == 1) {
    status = regcomp(&regex, pattern[0], REG_EXTENDED);
    if (status == 0) {
      status = regexec(&regex, buffer, 0, NULL, 0);
      regfree(&regex);
    }
  } else {
    status = regcomp(&regex, pattern[0], REG_EXTENDED);
    if (status == 0) {
      status = regexec(&regex, buffer, 0, NULL, 0);
      regfree(&regex);
    }
  }
  if (f_options->e == 1 || f_options->f == 1) {
    for (int i = 0; i < f_options->cnt_pattern; i++) {
      if (f_options->i == 1)
        status = regcomp(&regex, pattern[i], REG_ICASE);
      else
        status = regcomp(&regex, pattern[i], REG_EXTENDED);

      if (status == 0) {
        status = regexec(&regex, buffer, 0, NULL, 0);
        if (status == 0) {
          regfree(&regex);
          break;
        }
        regfree(&regex);
      }
    }
  }
  return status;
}

int print_result_grep(int status, struct grep_options *g_options, int argc,
                      char *argv, char *buffer,
                      struct file_options *f_options) {
  int exit_code = 0;
  if (f_options->v == 1) {
    int tmp = !status;
    status = tmp;
  }
  if (status == 0) {
    if (f_options->l == 1) {
      printf("%s\n", argv);
      exit_code = 1;
    } else if (f_options->c == 1) {
      g_options->cnt_match_line++;
    } else {
      if (argc - g_options->f_ind - 1 > 0 && !f_options->h) printf("%s:", argv);
      if (f_options->n == 1) printf("%d:", g_options->cnt_line);
      int cnt_c = 0;
      while (buffer[cnt_c] != '\0') {
        printf("%c", buffer[cnt_c]);
        cnt_c++;
      }
      if (buffer[cnt_c - 1] != '\n') printf("\n");
    }
  }
  g_options->cnt_line += 1;
  return exit_code;
}
