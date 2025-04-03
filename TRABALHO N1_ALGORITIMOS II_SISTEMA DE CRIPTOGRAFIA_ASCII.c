#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAMANHO 100

int main() {

    setlocale(LC_ALL, "Portuguese");

    // Declarando variáveis
    char msgDigitada[TAMANHO];
    char msgCriptografada[TAMANHO];
    char looping;

    do {
        // Iniciador do sistema criptografador
        printf("|------------------------------------------------------|\n");
        printf("|===========[SISTEMA CRIPTOGRAFADOR ASCII]=============|\n");
        printf("|------------------------------------------------------|\n");

        // lendo a mensagem digitada
        do {
            printf("\n=DIGITE SUA MENSAGEM, PARA CRIPTOGRAFAR ADICIONE ';' AO FINAL DA FRASE.\n");
            printf("\n=MENSAGEM PARA CRIPTOGRAFAR:");
            scanf(" %[^\n]", msgDigitada);
            while (getchar() != '\n');

            // Verifica se foi digitado a mensagem com ';' no final
            if (msgDigitada[strlen(msgDigitada) - 1] != ';') {
                printf("\n ***ERRO***  Sua mensagem deve terminar com ';'. Tente novamente!\n");
            }
           // verificação do programa que garante no final o ';'
        } while (msgDigitada[strlen(msgDigitada) - 1] != ';');

        // Mostra a mensagem criptografada
        printf("\t\n Mensagem CRIPTOGRAFADA: ");

        // Loop `do-while` para criptografar
        int i = 0;
        do {
            msgCriptografada[i] = (5 * msgDigitada[i] + 100) % 256;
            i++;
        } while (msgDigitada[i] != '\0');

        msgCriptografada[i] = '\0';
        printf("%s\n", msgCriptografada);

        // Pergunta ao usuario se ele quer continuar ou encerrar o programa
        do {
            printf("\nDeseja continuar? (S/N): ");
            scanf(" %c", &looping);
            while (getchar() != '\n');

            // Converte manualmente para minusculo
            if (looping >= 'A' && looping <= 'Z') {
                looping += 32;
            }

            if (looping != 'n' && looping != 's') {
                printf("Tente novamente, insira S para continuar ou N para encerrar o programa...\n");
            }
          // Aguarda entrada valida de s ou n para continuar ou encerrar
        } while (looping != 'n' && looping != 's');
      // encerra o programa
    } while (looping != 'n');

    return 0;


}




