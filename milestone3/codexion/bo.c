#include <stdio.h>

#define RESET       "\033[0m"

/* Colori attenuati (stile 2) */
#define RED_DIM     "\033[2;31m"
#define GREEN_DIM   "\033[2;32m"
#define YELLOW_DIM  "\033[2;33m"
#define BLUE_DIM    "\033[2;34m"
#define MAGENTA_DIM "\033[2;35m"
#define CYAN_DIM    "\033[2;36m"
#define WHITE_DIM   "\033[2;37m"

/* Colori brillanti / grassetto (stile 1) */
#define RED_BOLD    "\033[1;31m"
#define GREEN_BOLD  "\033[1;32m"
#define YELLOW_BOLD "\033[1;33m"
#define BLUE_BOLD   "\033[1;34m"
#define MAGENTA_BOLD "\033[1;35m"
#define CYAN_BOLD   "\033[1;36m"
#define WHITE_BOLD  "\033[1;37m"

int main(void)
{
    printf("--- Test Colori Attenuati (2;) ---\n");
    printf(RED_DIM     "Testo Rosso (Dim)\n"     RESET);
    printf(GREEN_DIM   "Testo Verde (Dim)\n"   RESET);
    printf(YELLOW_DIM  "Testo Giallo (Dim)\n"  RESET);
    printf(BLUE_DIM    "Testo Blu (Dim)\n"     RESET);
    printf(MAGENTA_DIM "Testo Magenta (Dim)\n" RESET);
    printf(CYAN_DIM    "Testo Ciano (Dim)\n"    RESET);
    printf(WHITE_DIM   "Testo Bianco (Dim)\n"   RESET);

    printf("\n--- Test Colori Brillanti / Bold (1;) ---\n");
    printf(RED_BOLD     "Testo Rosso (Bold)\n"     RESET);
    printf(GREEN_BOLD   "Testo Verde (Bold)\n"   RESET);
    printf(YELLOW_BOLD  "Testo Giallo (Bold)\n"  RESET);
    printf(BLUE_BOLD    "Testo Blu (Bold)\n"     RESET);
    printf(MAGENTA_BOLD "Testo Magenta (Bold)\n" RESET);
    printf(CYAN_BOLD    "Testo Ciano (Bold)\n"    RESET);
    printf(WHITE_BOLD   "Testo Bianco (Bold)\n"   RESET);

    return (0);
}
