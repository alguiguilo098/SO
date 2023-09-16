/*Código responsável por criar uma shell para que o usuário consiga executar comandos. 
Para um comando que não é executado em segundo plano, foi utilizado o wait() para esperar
o retorno dele. Para um comando que é executado em segundo plano, o usuário pode executar
outros comandos sem nenhum problema.*/
//Autores: Ingrid Reupke Sbeguen Moran RA:2349388
//Data de criação:23.03.2023
//Data de atualização:07.09.2023

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(){

    // declarações para execvp
    char *cmd = malloc(50*sizeof(char)); // comando
    char **lista_arg = malloc(50*sizeof(char*)); // lista de comandos

    // declarações extras
    pid_t pid; // pid do processo atual
    int status;
    int a; // variável de controle 

    while(1){

        scanf("%s", cmd); // lê o comando de entrada e grava na string cmd
        int len = strlen(cmd); // retorna o tamanho da string do comando
        cmd[strcspn(cmd, "\n")] = 0; // ao ler um \n na string cmd, coloca um 0 no seu lugar

        lista_arg[0] = strtok(cmd, "\n"); // copia o comando para a lista de comandos

        pid = fork();
 
        if(pid == 0){ // caso o pid seja 0, ou seja, de um filho, o comando é executado 

            if(cmd[len-1] != '&'){ // se não for executado em segundo plano...
                a = 1;
            }

            execvp(cmd, lista_arg); // execução do comando

            if(a == 1){
                wait(&status); // espera o retorno do comando
            }

        }

    }
    exit(0);
}
