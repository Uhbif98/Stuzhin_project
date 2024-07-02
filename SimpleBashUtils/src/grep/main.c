
#include "main_function.h"

int main(int argc, char **argv) {
  char *short_options = "e:ivclnhsf:o";
  struct file_options f_options = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  struct grep_options g_options = {0, 0, 1, 1};
  char *buffer = NULL;
  char **pattern = parsing_options(argc, argv, short_options, &f_options);
  if (pattern[0] != NULL) {
    g_options.f_ind = optind;
    if (f_options.e == 0 && f_options.f == 0) g_options.f_ind++;
    for (int i = g_options.f_ind; i < argc; i++) {
      FILE *f = f_options_s(argv[i], &f_options);
      if (f != NULL) {
        while (getline(&buffer, &g_options.line, f) != -1) {
          int status = get_regex_status(pattern, buffer, &f_options);
          if (print_result_grep(status, &g_options, argc, argv[i], buffer,
                                &f_options)) {
            break;
          }
        }
        if (f_options.c == 1 && !f_options.l) {
          if (argc - g_options.f_ind - 1 > 0 && !f_options.h)
            printf("%s:%d\n", argv[i], g_options.cnt_match_line);
          else
            printf("%d\n", g_options.cnt_match_line);
        }
        fclose(f);
      }
      g_options.cnt_match_line = 0;
      g_options.cnt_line = 1;
    }
    if (f_options.cnt_pattern > 1) {
      for (int i = 1; i < f_options.cnt_pattern; i++) {
        free(pattern[i]);
      }
    }
    free(pattern[0]);
    free(buffer);
  }
  free(pattern);
  return 0;
}
