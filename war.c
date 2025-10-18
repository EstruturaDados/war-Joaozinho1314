// // Nível Novato: Cadastro Inicial dos Territórios
// #include <stdio.h>
// #include <string.h>

// // Definição da struct Territorio
// struct Territorio {
//     char nome[30]; 
//     char cor[10];     
//     int tropas;       
// };

// int main() {
//     struct Territorio territorios[5]; // Vetor para armazenar 5 territórios
//     int i;

//     printf("=== Cadastro de Territórios ===\n\n");

//     // Cadastro dos territórios
//     for (i = 0; i < 5; i++) {
//         printf("Cadastro do território %d:\n", i + 1);

//         printf("Digite o nome do território: ");
//         scanf(" %29[^\n]", territorios[i].nome); 

//         printf("Digite a cor do exército: ");
//         scanf(" %9s", territorios[i].cor);

//         printf("Digite a quantidade de tropas: ");
//         scanf("%d", &territorios[i].tropas);

//         printf("\n"); 
//     }

//     // Exibição dos dados cadastrados
//     printf("\n=== Territórios Cadastrados ===\n");
//     for (i = 0; i < 5; i++) {
//         printf("\nTerritório %d\n", i + 1);
//         printf("Nome: %s\n", territorios[i].nome);
//         printf("Cor do exército: %s\n", territorios[i].cor);
//         printf("Quantidade de tropas: %d\n", territorios[i].tropas);
//     }

//     printf("\nCadastro concluído com sucesso!\n");

//     return 0;
// }

// Nível Aventureiro: Batalhas Estratégicas

// #include <stdio.h>5    } else if (strcmp(mapa[atacanteIndex - 1].cor, mapa[defensorIndex - 1].cor) == 0) {
//         printf("Você não pode atacar um território da mesma cor!\n");
//     } else {
//         atacar(&mapa[atacanteIndex - 1], &mapa[defensorIndex - 1]);
//     }

//     // Exibição final
//     printf("\n=== Situação após o ataque ===\n");
//     exibirTerritorios(mapa, qtd);

//     // Liberação de memória
//     liberarMemoria(mapa);

//     printf("\nMemória liberada. Encerrando o programa.\n");
//     return 0;
// }


// void cadastrarTerritorios(Territorio *mapa, int qtd) {
//     for (int i = 0; i < qtd; i++) {
//         printf("\nCadastro do território %d:\n", i + 1);
//         printf("Nome: ");
//         scanf(" %29[^\n]", mapa[i].nome);
//         printf("Cor do exército: ");
//         scanf(" %9s", mapa[i].cor);
//         printf("Quantidade de tropas: ");
//         scanf("%d", &mapa[i].tropas);
//     }
// }

// /*
//  * Função: exibirTerritorios
//  * Objetivo: exibir os dados de todos os territórios.
//  */
// void exibirTerritorios(Territorio *mapa, int qtd) {
//     for (int i = 0; i < qtd; i++) {
//         printf("\nTerritório %d\n", i + 1);
//         printf("Nome: %s\n", mapa[i].nome);
//         printf("Cor: %s\n", mapa[i].cor);
//         printf("Tropas: %d\n", mapa[i].tropas);
//     }
// }

// /*
//  * Função: atacar
//  * Objetivo: simular o ataque entre dois territórios.
//  * Regras:
//  *  - Cada lado rola um "dado" (1 a 6).
//  *  - Se o atacante vencer, o defensor muda de dono e perde tropas.
//  *  - Se o defensor vencer, o atacante perde uma tropa.
//  */
// void atacar(Territorio *atacante, Territorio *defensor) {
//     int dadoAtacante = (rand() % 6) + 1;
//     int dadoDefensor = (rand() % 6) + 1;

//     printf("\n>>> %s (cor %s) está atacando %s (cor %s)!\n",
//            atacante->nome, atacante->cor, defensor->nome, defensor->cor);
//     printf("Dado do atacante: %d\n", dadoAtacante);
//     printf("Dado do defensor: %d\n", dadoDefensor);

//     if (dadoAtacante > dadoDefensor) {
//         printf("O atacante venceu a batalha!\n");
//         strcpy(defensor->cor, atacante->cor);      // muda o dono
//         defensor->tropas = atacante->tropas / 2;   // transfere metade das tropas
//     } else {
//         printf("O defensor resistiu ao ataque!\n");
//         atacante->tropas -= 1;                     // atacante perde 1 tropa
//     }
// }

// /*
//  * Função: liberarMemoria
//  * Objetivo: liberar a memória alocada dinamicamente.
//  */
// void liberarMemoria(Territorio *mapa) {
//     free(mapa);
// }

// Nível Mestre: Missões e Modularização Total

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ==== Protótipos das funções ====
void cadastrarTerritorios(Territorio *mapa, int qtd);
void exibirMapa(Territorio *mapa, int qtd);
void atacar(Territorio *atacante, Territorio *defensor);
void atribuirMissao(char *destino, char *missoes[], int totalMissoes);
int verificarMissao(char *missao, Territorio *mapa, int tamanho);
void liberarMemoria(Territorio *mapa, char *missaoJogador1, char *missaoJogador2);

// ==== Função principal ====
int main() {
    srand(time(NULL));

    int qtd, atacante, defensor;
    Territorio *mapa;
    char *missaoJogador1, *missaoJogador2;

    // Vetor de missões disponíveis
    char *missoes[] = {
        "Conquistar 2 territorios inimigos.",
        "Eliminar todas as tropas da cor vermelha.",
        "Possuir pelo menos 3 territorios com mais de 5 tropas.",
        "Conquistar 3 territorios seguidos.",
        "Ser dono de todos os territorios verdes."
    };
    int totalMissoes = 5;

    printf("=== Sistema de Missoes e Batalhas ===\n\n");

    // Quantidade de territórios
    printf("Digite o numero de territorios no mapa: ");
    scanf("%d", &qtd);

    // Alocação dinâmica dos territórios
    mapa = (Territorio*) calloc(qtd, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria para territorios!\n");
        return 1;
    }

    // Cadastro dos territórios
    cadastrarTerritorios(mapa, qtd);

    // Alocação e atribuição das missões
    missaoJogador1 = (char*) malloc(100 * sizeof(char));
    missaoJogador2 = (char*) malloc(100 * sizeof(char));

    atribuirMissao(missaoJogador1, missoes, totalMissoes);
    atribuirMissao(missaoJogador2, missoes, totalMissoes);

    printf("\nMissao do Jogador 1: %s\n", missaoJogador1);
    printf("Missao do Jogador 2: %s\n", missaoJogador2);

    // Loop de turnos
    int vencedor = 0;
    while (!vencedor) {
        printf("\n=== Mapa Atual ===\n");
        exibirMapa(mapa, qtd);

        printf("\nEscolha o territorio atacante (numero): ");
        scanf("%d", &atacante);
        printf("Escolha o territorio defensor (numero): ");
        scanf("%d", &defensor);

        if (atacante == defensor) {
            printf("Um territorio nao pode atacar a si mesmo!\n");
            continue;
        }

        if (strcmp(mapa[atacante - 1].cor, mapa[defensor - 1].cor) == 0) {
            printf("Voce nao pode atacar um territorio da mesma cor!\n");
            continue;
        }

        atacar(&mapa[atacante - 1], &mapa[defensor - 1]);

        // Verifica se algum jogador cumpriu sua missão
        if (verificarMissao(missaoJogador1, mapa, qtd)) {
            printf("\n🏆 Jogador 1 cumpriu sua missao e venceu o jogo!\n");
            vencedor = 1;
        } else if (verificarMissao(missaoJogador2, mapa, qtd)) {
            printf("\n🏆 Jogador 2 cumpriu sua missao e venceu o jogo!\n");
            vencedor = 1;
        }
    }

    liberarMemoria(mapa, missaoJogador1, missaoJogador2);
    return 0;
}

// ==== Implementações ====

void cadastrarTerritorios(Territorio *mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nCadastro do territorio %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %29[^\n]", mapa[i].nome);
        printf("Cor do exercito: ");
        scanf(" %9s", mapa[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(Territorio *mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n[%d] %s | Cor: %s | Tropas: %d",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("\n");
}

void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;

    printf("\n>>> %s (cor %s) ataca %s (cor %s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado Atacante: %d | Dado Defensor: %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("O atacante venceu o combate!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("O defensor resistiu!\n");
        atacante->tropas -= 1;
    }
}

void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

/*
 * Função simples para verificar o cumprimento da missão.
 * Nesta versão inicial, criaremos apenas condições ilustrativas.
 */
int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
    int territoriosDoJogador = 0;

    // Exemplo de regra simples:
    if (strstr(missao, "2 territorios")) {
        // verifica se há dois territórios da mesma cor
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "azul") == 0) territoriosDoJogador++;
        }
        if (territoriosDoJogador >= 2) return 1;
    }

    if (strstr(missao, "vermelha")) {
        // verifica se ainda existe algum vermelho
        int vermelhoExiste = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "vermelho") == 0)
                vermelhoExiste = 1;
        }
      
