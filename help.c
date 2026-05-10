#include "mp3.h"

void print_help(void)
{
   printf("\n===============   HELP LIST   =================\n");
   printf("1. -v -> to view mp3 file contents\n");
   printf("2. -e -> to edit mp3 file contents\n");
   printf("        2.1. -t -> to edit song title\n");
   printf("        2.2. -a -> to edit artist name\n");
   printf("        2.3. -A -> to edit album name\n");
   printf("        2.4. -y -> to edit year\n");
   printf("        2.5. -m -> to edit content\n");
   printf("        2.6. -c -> to edit comment\n");
   printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void invalid_print(void)
{
    printf("INVALID ARGUMENTS\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("USAGE :\n");
        printf("To view please pass like: ./a.out -v Mp3filename\n");
        printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text Mp3filename\n");
        printf("To get help pass like: ./a.out --help\n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}