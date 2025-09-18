#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[50], esporte[20];
    int idade, altura;

}atleta;

void tira_quebra_linha(char *str){
    
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

 void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



void ler_altleta(atleta *a){
    printf("Nome: ");
    fgets(a->nome, sizeof(a->nome), stdin);
    tira_quebra_linha(a->nome);
    printf("Esporte: ");
    fgets(a->esporte, sizeof(a->esporte), stdin);
    tira_quebra_linha(a->esporte);
    printf("idade: ");
    scanf("%d", &a->idade);
    limpar_buffer();
    printf("altura (cm): ");
    scanf("%d", &a->altura);
    limpar_buffer();
}

void imprimir_no_arquivo(atleta a, FILE *arq){
    fprintf( arq, " Nome: %s\n Esporte: %s\n Idade: %d\n Altura: %d\n\n", a.nome, a.esporte, a.idade, a.altura );
}

int main(){

    atleta a[5];
    FILE *F;
    F= fopen("arquivo.txt", "w");

    if(F!=NULL){

        for(int i=0; i<5; i++){
            ler_altleta(&a[i]);
            imprimir_no_arquivo( a[i], F);
        }
        
         fclose(F);
        
    } else printf("erro ao abrir o arquivo");

 
}
