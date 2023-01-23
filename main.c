#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINESIZE 1024
#define WORDSIZE 512
#define MAXWORD 2048

typedef struct word
{
    char value[WORDSIZE + 1];
} Word;

int main(int argc, char **argv)
{
    FILE *arq;
    int win = 0, trying = 0, r = 0, wc = 0, wordSize = 0;
    char entry, *filePath, line[LINESIZE + 1], selected[WORDSIZE + 1], openWord[WORDSIZE + 1];
    Word *list;

    if (argc <= 1)
    {
        perror("Informe o arquivo de palavras a serem sorteadas.\n\n");
        exit(1);
    }

    filePath = argv[1];

    arq = fopen(filePath, "r");

    if (!arq)
    {
        perror("Erro ao abrir arquivo\n\n");
        exit(1);
    }

    list = malloc(MAXWORD * sizeof(Word));

    wc = 0;
    fgets(line, LINESIZE, arq);
    while (!feof(arq))
    {
        strcpy((list + wc)->value, line);

        fgets(line, LINESIZE, arq);
        wc++;
    }

    fclose(arq);

    // Sortear palavra
    srand(time(0));
    r = rand() % wc;

    strcpy(selected, (list + r)->value);

    wordSize = strlen(selected);

    int i;
    for (i = 0; i < (wordSize - 1); i++)
    {
        openWord[i] = '_';
    }
    openWord[i] = '\0';

    while (!win)
    {
        printf("Digite uma letra: ");
        scanf(" %c", &entry);

        printf(">>> %c\n", entry);

        for (int i = 0; i < (wordSize - 1); i++) // retirar \0
            if (selected[i] == entry)
                openWord[i] = entry;
            else if (openWord[i] == '_')
                openWord[i] = '_';

        trying++;

        printf("%s\n\n", openWord);

        if (strstr(openWord, "_") == NULL)
        {
            printf("Voce ganhou com %d tentativas.\n\n", trying);
            win = 1;
        }
    }

    free(list);

    return 0;
}
