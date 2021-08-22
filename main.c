//Comprar ingressos, quantos quiser, selecionando  a poltrona
// Permitir descontos como meia entrada e itasil
// 40 fileiras de 1 a 40
// 10 poltronas por fileira, de A a J
// 20 reais o ingresso, 10 reais a meia e 14 reais pra itasil
#include<stdio.h>

#define INGRESSOPADRAO 20 //Valor fixo do ingresso cheio
#define DESCMEIA 10 //Valor fixo da meia entrada estudantil
#define DESCITASIL 14 //Valor fixo cliente itasil
#define FILEIRAS 40 
#define POLTRONAS 10
#define TOTALPOLTRONAS 400

char menu(void){
    char filme;
    printf("\n");
    printf("Seja bem vindo ao sistema de cinema Mariano Pinheiro =).\n\n");
    printf("------||------\n\n");
    printf("Por favor, selecione o filme\n");
    printf("1- \t Star Trek\n");
    printf("2- \t Star Wars\n");
    printf("3- \t Avengers\n");
    printf("0- \t Sair do sistema :(\n");
    scanf("%c", &filme);
    return filme;
}

int quantidade_ingressos(void){
    printf("\n");
    int quantidade; 
    scanf("%d", &quantidade);
    return quantidade;
}

int conta_vagas(char sala[FILEIRAS][POLTRONAS]){
    int contador = 0, i, j;
    for(i=0; i<FILEIRAS; i++){
        for(j=0; j<POLTRONAS; j++){
            if(sala[i][j]=='X'){
                contador++;
            }
        }
    }
    return contador;
}

int verifica_quantidade(char sala[FILEIRAS][POLTRONAS], int opcao, int max){
    int qnt;
    if(opcao==1){
        while(1){
            qnt = quantidade_ingressos();
            if((qnt>max- conta_vagas(sala))||(qnt<=0)){
                printf("\nEntre com uma quantidade valida, por favor");
                continue;
            }
            break;
        }
    }
    if(opcao==2){
        while(1){
            qnt = quantidade_ingressos();
            if((qnt>max)||(qnt<0)){
                printf("\nEntre com uma quantidade valida, por favor");
                continue; 
            }
            break;
        }
    }
    return qnt;
}

int receber_carteira(carteirinhas_usadas){
    int carteirinha, original;
    while(1){
        printf("\nEntre com a carteirinha\n");
        scanf("%5d", &carteirinha);
        original = carteirinha;
        int i, numero, digito, soma=0;
        char r;
        digito = carteirinha %10;
        carteirinha /= 10;
        for(i=0; i<4; i++){
            numero = carteirinha %10;
            carteirinha /= 10;
            if(i%2 == 0){
                if(numero>=5){
                numero *= 2;
                soma += numero % 10;
                soma += numero/10;
                continue; 
                }
                numero *= 2;
                soma += numero;
                continue;
            }
            soma += numero;
        }
        soma = soma % 10;
        soma = 10 - soma;
        if(soma == digito){
            return original;
        }
        scanf("%c", &r);
        printf("\nPor favor, entre com uma carteirinha válida(enter para continuar), ou desista do desconto dessa (digitando 0).");
        scanf("%c", &r);
        if(r=='0'){
            return 0;
        }
        continue;
    } 
}

int main(void){
    int i, j, carteira_estudante;
    int carteirinhas_utilizadas[TOTALPOLTRONAS];
    char sala1[FILEIRAS][POLTRONAS];
    char sala2[FILEIRAS][POLTRONAS];
    char sala3[FILEIRAS][POLTRONAS];
    for(i=0; i<FILEIRAS; i++){
        for(j=0; j<POLTRONAS; j++){
            sala1[i][j]= '0';
            sala2[i][j]= '0';
            sala3[i][j]= '0';
        }
    }
    for(i=0; i<TOTALPOLTRONAS; i++){
        carteirinhas_utilizadas[i] = 0;
    }
    while(1){
        char filme = menu();
        int qnt_ingressos=0, qnt_meia=0,meias_validas=0, qnt_itasil=0, carteirinha;
        switch(filme){
            case '0':
                printf("Muito obrigado, volte sempre!");
                return 0;
                break;
            case '1':
                printf("Por favor, entre com a quantidade de ingressos\n");
                qnt_ingressos = verifica_quantidade(sala1, 1, TOTALPOLTRONAS);
                printf("\nPor favor, entre com a quantidade dos ingressos que são meia entrada");
                qnt_meia = verifica_quantidade(sala1, 2, qnt_ingressos);
                for(i=0; i<qnt_meia; i++){
                    carteira_estudante = receber_carteira(carteirinhas_utilizadas);
                    if(carteira_estudante != 0){
                        meias_validas++;
                    }
                }
                break;
            case '2':
                printf("Por favor, entre com a quantidade de ingressos\n");
                qnt_ingressos = verifica_quantidade(sala2, 1, TOTALPOLTRONAS);
                printf("\nPor favor, entre com a quantidade dos ingressos que são meia entrada");
                qnt_meia = verifica_quantidade(sala2, 2, qnt_ingressos);
                for(i=0; i<qnt_meia; i++){
                    carteira_estudante = receber_carteira(carteirinhas_utilizadas);
                    if(carteira_estudante != 0){
                        meias_validas++;
                    }
                }
                break;
            case '3':
                printf("Por favor, entre com a quantidade de ingressos\n");
                qnt_ingressos = verifica_quantidade(sala3, 1, TOTALPOLTRONAS);
                printf("\nPor favor, entre com a quantidade dos ingressos que são meia entrada");
                qnt_meia = verifica_quantidade(sala3, 2, qnt_ingressos);
                for(i=0; i<qnt_meia; i++){
                    carteira_estudante = receber_carteira(carteirinhas_utilizadas);
                    if(carteira_estudante != 0){
                        meias_validas++;
                    }
                }
                
                break;
            default:
                printf("Valor inválido. Vamos tentar novamente...\n");
                continue;
        }
        // 12345 / 10 
        // 1234 5
        break;
    }
}


/*
2    2   1   9  4
x1  x2  x1  x2
 2   4   1   18
 2   4   1   9
16 % 10 = 6 ---> (10 - 6) = 4
*/