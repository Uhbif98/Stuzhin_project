
#include "main_function.h"

int main(int argc, char* argv[]) {
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {"e", no_argument, NULL, 'e'},
                                  {"E", no_argument, NULL, 'E'},
                                  {"t", no_argument, NULL, 't'},
                                  {"T", no_argument, NULL, 'T'},
                                  {NULL, 0, NULL, 0}};

  char* short_options = "bnseEtT";

  struct file_options f_options =
      parsing_options(argc, argv, short_options, long_options);

  int cnt_number = 1;
  for (int i = f_options.options_cnt; i < argc; i++) {
    FILE* f;
    f = f_reader(argv[i]);
    if (f != NULL) {
      int cnt_squeeze = 0;
      int64_t fs_cnt = f_counter(f);
      char* buffer = malloc(fs_cnt + 1);
      char first_itter;
      if (i == f_options.options_cnt) {
        first_itter = '\n';
      }
      while ((fgets(buffer, fs_cnt, f)) != NULL) {
        if (f_options.s && buffer[0] == '\n' && cnt_squeeze) {
          continue;
        } else if (f_options.s && buffer[0] == '\n' && !cnt_squeeze) {
          cnt_squeeze++;
        } else
          cnt_squeeze = 0;

        if (f_options.b && buffer[0] != '\n' && first_itter == '\n') {
          printf("% 6d\t", cnt_number);
          cnt_number++;
        }
        if (f_options.n && first_itter == '\n' && !f_options.b) {
          printf("% 6d\t", cnt_number);
          cnt_number++;
        }
        cat_print(buffer, f_options);
        int len = strlen(buffer);
        first_itter = buffer[len - 1];
      }
      free(buffer);
      fclose(f);
    }
  }
  return 0;
}