#include <stdio.h>

int main(){

FILE *file = fopen("C:\\Users\\warli\\Desktop\\AtividadeProgramacaoFaculdade\\programacao-EstruturaDeDados\\atividade3\\Pasta1.csv", "w");
    fprintf(file, "CAOASDMSADASIODASDNASODASD");
if (file == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1;
}
    fclose (file);
    return 0;
}

