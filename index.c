#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct{
    char game1[20], game2[20], ganhador[20];
    int cont1, cont2, pont_max;
} dama;

FILE *historico;
void desenho() {
    printf("\n\n\n\t\t\t0000000000000000000000000000\n\t\t\t000000000__________000000000\n\t\t\t000000________________000000\n\t\t\t0000____________________0000\n\t\t\t000_____00________00_____000\n\t\t\t00_____0000______0000_____00\n\t\t\t00_____0000______0000_____00\n\t\t\t00______00________00______00\n\t\t\t00________________________00\n\t\t\t00______0__________0______00\n\t\t\t000______00______00______000\n\t\t\t0000_______000000_______0000\n\t\t\t000000________________000000\n\t\t\t000000000___________00000000\n\t\t\t0000000000000000000000000000\n");
}
void desenho2() 
{
    printf("\n\t\t\t´´´¶¶¶¶´´´´´´´´´´s¶¶¶¶¶´´´´´´´´´´´s¶¶¶\n\t\t\t´´´´¶¶¶¶¢´´´´´7¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´¶¶¶¶\n\t\t\t´´´7¶¶¶¶¢´´´¢¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´s¶¶¶¶s\n\t\t\t´´¶¶¶¶¶¶¶¶´ø¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1´¶¶¶¶¶¶¶¶\n\t\t\t´´¢øs$¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´¶¶¶¶¢¢$$\n\t\t\t´´´´´´´´7¢ø¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶s´ø\n\t\t\t´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n\t\t\t´´´´´´´´´´1¶¶¶¶ø´´7¶¶¶¶¶1´ø¶¶¶¶¶s\n\t\t\t´´´´´´´´´´´¶¶´´´´´´´¶¶¶´´´´´´s¶¶\n\t\t\t´´´´´´´´´´1¶¶´´´´´´$¶¶¶1´´´´´´¶¶1\n\t\t\t´´´´´´´´´´´¶¶¶´´s¶¶¶´´ø¶¶s´´¶¶¶¶\n\t\t\t´´´´´´´´´´´7¶¶¶¶¶¶¶¶´´´¶¶¶¶¶¶¶¶1\n\t\t\t´´´´´´´´´´´´´¶¶¶¶¶¶¶s$s¶¶¶¶¶¶\n\t\t\t´´´´´´´´´´´ø¶´¶s¶¶¶¶¶¶¶¶¶¶¶´¶´¶s\n\t\t\t´´´´7´´´´$¶¶¶´¶´´´´´´´´´´´$´¶¶¶¶¶\n\t\t\t´1¶¶¶¶¶¶¶¶¶¶ø´¶´¶¶$¶¶$¶¶$¶7¶1´¶¶¶¶¶¶¶¶¶¶¶\n\t\t\t´´¶¶¶¶¶¶¶¶´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶1´´´¶¶¶¶¶¶¶¶¶\n\t\t\t´´´ø¶¶¶¶¶´´´´´´1¶¶¶¶¶¶¶¶¶¶¢´´´´´´¶¶¶¶¶¶¶\n\t\t\t´´´´´s¶¶ø´´´´´´´´´$¶¶¶¶¶s´´´´´´´´1¶¶¶\n");
}
void desenho3() 
{
    printf("\t\t\t´´´´´´´´´´´´´´´´´´´´´´´$¶´´´´´¶´´´´´¶¢\n\t\t\t´´´´´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¢´´´¶´´´ø¶\n\t\t\t´´´´´´´´´´¶¶´´´´ø¶¶¶´´´´´´oø´´ø´´øo\n\t\t\t´´´´´´´´´´¶7´´´´´´´¶¶¶´´´´´´1´´´1´´´´1o\n\t\t\t´´´´´´´¶¶¶¶¶¶¶´´´´´´´¶¶¶7´´´´´´´´1o¶¶¶ø\n\t\t\t´´´´´´´¶¶¶¶¶¶¶´´´´´´´´´¶¶¶¶¶¶¶¶´´1\n\t\t\t´´´´´o¶¶¶¶¶¶¶¶¶ø´´´´´´´´´´´´´´´´´´o$¢\n\t\t\t´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´¢´´1ø´´´1¶¶o\n\t\t\t´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶o´´´´´´´1$´´´¶\n\t\t\t´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´¶´´´´o¶´\n\t\t\t´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´¶¶\n\t\t\t´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´\n\t\t\t´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´\n\t\t\t´´´´´¶¶¶¶¶¶¶¶¶¶¶¶´\n\t\t\t´´´´´´´¶¶¶¶¶¶¶¶\n");
}
void desenho4()
{
    printf("\t\t\t\t-----\\\\////--------\n\t\t\t\t------( @@)-------\n\t\t\t\t---ooO--(_)--Ooo--\n\t\t\t\t\n\n\n");
}

void jogador1(char matriz[8][8],char jogador, int oposto)
{
    system("color 20");
    int i,j,l,c,li,co,opcao=0;

    do//laço do jogo
    {
        system("cls");
        if(jogador==1)//definiçao da peça
        printf("\n\n----------------    A VEZ E A DO JOGADOR PECA BRANCA  ----------\n\n\n\n");
        if(jogador==2)
        printf("\n\n----------------    A VEZ E A DO JOGADOR PECA PRETA  ------------\n\n\n\n");
        printf("\t \t\t 0 1 2 3 4 5 6 7 \n");
        for(i=0;i<8;i++)
        {
            printf("\n\t\t\t%d   ", i);
            for(j=0;j<8;j++)
            printf("%c ", matriz[i][j]);
        }

        printf("\n\n\t***************  CORDENADA DA PECA  **********************");
        printf("\n\rLINHA: ");
        scanf("%d", &l);
        printf("\n\tCOLUNA: ");
        scanf("%d", &co);
        if((li+co)%2==0)
        {
            if((jogador==1&&l<li)||(jogador==2&&l>li))
            {
                printf("linha\n");
                if(c-1==co || c+1==co)
                {
                    if(co==c-1){
                    matriz[li][co] = jogador;
                    matriz[l][c] = 0;
                    opcao++;
                    }
                    if(co==c+1)
                    {
                        matriz[li][co] = jogador;
                        matriz[l][c] = 0;
                        opcao++;
                    }
                }

            if(matriz[l+1][c+1]==oposto)
            {
                if(c+2==co)
                {
                    matriz[li][co] = jogador;
                    matriz[l][c] = 0;
                    opcao++;
                    matriz[l+1][c+1]=0;
                }
            }     

            if(matriz[l+1][c-1]==oposto)
            {
                if(c-2==co)
                {
                    matriz[li][co] = jogador;
                    matriz[l][c] = 0;
                    matriz[l+1][c-1] = 0;
                    opcao++;
                }
            }

            if(matriz[l-1][c+1]==oposto)
            {
                if(c+2==0)
                {
                    matriz[li][co] = jogador;
                    matriz[l][c] = 0;
                    matriz[l+1][c-1] = 0;
                    opcao++;
                }
            }

            if(matriz[l-1][c-1]==oposto) 
            {
                if(c-2==0)
                {
                    matriz[li][co] = jogador;
                    matriz[l][c] = 0;
                    matriz[l-1][c-1] = 0;
                    opcao++;
                }
            }

            }
            else printf("\n\n\t\t__________MOVIMENTO INVALIDO!!_________\n\t\t_________JOGUE NOVAMENTE________\n");
        } 
        system("pause");
    }   while(opcao!=1);
}

void ganhador(char matriz[8][8])
{
    int i,j;
    for(i=0;i<8;i++)
       for(j=0;j<8;j++)
       {
           if(matriz[i][j]==2)
           dama.cont1++;
           if(matriz[i][j]==1)
           dama.cont2++;
       }
        if(dama.cont1>dama.cont2)
        {
            printf("\n\tVENCEDOR........-> %s TOTAL DE PECAS: %d\n\n", dama.game2,dama.cont2);
            strcpy(dama.ganhador, dama.game2);
            dama.pont_max=dama.cont1;
        }
        else
        {
            if(dama.cont1<dama.cont2)
            {
                printf("\n\tVENCEDOR........-> %s TOTAL DE PECAS: %d\n\n",dama.game2,dama.cont2);
                strcpy(dama.ganhador, dama.game2);
                dama.pont_max=dama.cont2; 
            }
            else{
                printf("\n\tEmpate!\n\t%s: %d\n\t%s: %d\n\n\n",dama.game1,dama.cont1,dama.game2,dama.cont2);
                strcpy(dama.ganhador,"jogo empatado");
                dama.pont_max=dama.cont2;
            }
        }

}       

void registro(void){
    fwrite(&dama, sizeof(dama), 1, historico);

}

void escreve(void){
    rewind(historico);
    while(fread(&dama, sizeof(dama), 1, historico)==1)
    printf("\nJogador peca preta: %s\nJogador peca branca: %s\nVencedor: %s        Total de pecas: %d\n\n",dama.game1, dama.game2, dama.ganhador, dama.pont_max);

}

int main(int agrc, char *agrv[])
{
    char matriz[8][8];
    int i,j, jogador=2,oposto=1,opcao=0,opcao2;
    dama.cont1=dama.cont2=0;
    historico=fopen("Historico_dama.bin", "ab+");


  matriz[0][0]= 1;     matriz[0][1]= 178;   matriz[0][2]= 1;   matriz[0][3] = 178; matriz[0][4] = 1;  matriz[0][5]= 178; matriz[0][6]= 1;   matriz[0][7]= 178; 
  matriz[1][0]= 178;   matriz[1][1]= 1;     matriz[1][2]= 178; matriz[1][3] = 1;   matriz[1][4] = 178;matriz[1][5]= 1;   matriz[1][6]= 178; matriz[1][7]= 1; 
  matriz[2][0]= 1;     matriz[2][1]= 178;   matriz[2][2]= 1;   matriz[2][3] = 178; matriz[2][4] = 1;  matriz[2][5]= 178; matriz[2][6]= 1;   matriz[2][7]= 178; 
  matriz[3][0]= 178;   matriz[3][1]= 0;     matriz[3][2]= 178; matriz[3][3] = 0;   matriz[3][4] = 178;matriz[3][5]= 0;   matriz[3][6]= 178; matriz[3][7]= 0;  
  matriz[4][0]= 0;     matriz[4][1]= 178;   matriz[4][2]= 0;   matriz[4][3] = 178; matriz[4][4] = 0;  matriz[4][5]= 178; matriz[4][6]= 0;   matriz[4][7]= 178;
  matriz[5][0]= 178;   matriz[5][1]= 2;     matriz[5][2]= 178; matriz[5][3] = 2;   matriz[5][4] = 178;matriz[5][5]= 2;   matriz[5][6]= 178; matriz[5][7]= 2;
  matriz[6][0]= 2;     matriz[6][1]= 178;   matriz[6][2]= 2;   matriz[6][3] = 178; matriz[6][4] = 2;  matriz[6][5]= 178; matriz[6][6]= 2;   matriz[6][7]= 178;
  matriz[7][0]= 178;   matriz[7][1]= 2;     matriz[7][2]= 178; matriz[7][3] = 2;   matriz[7][4] = 178;matriz[7][5]= 2;   matriz[7][6]= 178; matriz[7][7]= 2; 

  do{
      system("color 47");

    printf("\n\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________                    ____________________\n");
    printf("\t__________________                    ____________________\n");
    printf("\t__________________   JOGO  DA  DAMA   ____________________\n");
    printf("\t__________________                    ____________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n");
    printf("\t__________________________________________________________\n\t\t\t\t\tCriado Por :Emerson\n\n");
    printf("\tEscolha uma das op%c%ces abaixo:\n\n",135,228);
    printf("\t%c 1 Jogar.\n\t%c 2 Ajuda.\n\t%c 3 Hist%crico.\n\t%c 4 Sair.\n\n",16,16,16,162,16);
    printf("\tOp%c%co: ",135,198);// OS NUMEROS  E PARA COLOCAR  ACENTOS........
    scanf("%d",&opcao2);//ESCOLHA DA OPCAO DO MENU.......
    system("cls");
    switch(opcao2){
        case 1:
                    system("color 10");
                     desenho();
                     printf("\n\n\t\t\tENTER PARA CONTINUAR.....");
                     printf("\n\n\n");
                     system("pause");
                     system("cls");
                     system("color 50");
                     printf("\n\n\t\tINFORME O NOME DO JOGADOR PECA PRETA:\n\n\t\t\t\t");//NOME DOS JOGADORES..
                     scanf("%s",dama.game1);
                     printf("\n\n\t\tINFORME O NOME DO JOGADOR PECA BRANCA:\n\n\t\t\t\t ");//NOME DOS JOGADORES..
                     scanf("%s",dama.game2);
    
        int tempo = clock();
        while(clock()-tempo<5000)
        {
            jogador=1;oposto=2;
            jogador1(matriz,jogador,oposto);
            jogador=2;oposto=1;
            jogador1(matriz,jogador,oposto);
        }
        system("cls");
        system("color 20");
        desenho4();
        printf("\n\t\t..........PASSARAM 3 MINUTOS FIM DO JOGO...........\n\n\n");
        ganhador(matriz);
        registro();
        system("pause");
        system("cls");
        break;
        case 2: 
        system("color 90");
        printf("\n_____________________________O QUE E O JOGO?_______________________________");
        printf("\n\t     O jogo de Damas e constituido por um Tabuleiro quadratico,\n\tdividido em 64 quadrados,com 24 Pecas,sendo 12 de cor branca\n\te 12 de cor preta. Exitem  8 linhas que estao na posicao  vertical,\n\te com 8 culunas na posicao horizantal.\n");
        printf("\n_____________________________  O OBJETIVO  _______________________________");
        printf("\n\n\t      Comer o maior Numero de Pecas Possiveis.Quem \n\tDurante os 3 Minutos tiver  mais Pecas e o Vencedor!\n\n");
                     
        printf("\n______________________________REGRAS O JOGO_________________________________");
        printf("\n\n\t1-Nao e permitido comer para tras.\n\t2-Pode comer uma peca,nao duas de uma vez.\n\t3-So anda uma casa por vez.\n\t4- O Jogo dura  3 Minutos.\n\t5-Nao e permitido Jogar com uma Peca do adversario.\n");
        printf("____________________________________________________________________________\n\n");
        system("pause");
        system("cls");
        break;
        case 3: 
        system("color 80");
        desenho2();
        system("pause");
        system("cls");
        escreve();
        system("pause");
        system("cls");
        break;
        case 4:
            system("color 70");
            desenho3();
            printf("\n\n\n\n\t\t\t  FIM DO JOGO\n\n\n\n\n");
            break;
        }
  }while(opcao2!=4);
      fclose(historico);
      system("PAUSE");
      return 0;
}