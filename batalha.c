# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <windows.h>
# define LIM 10

int c, l;
char letras[10]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void tracinhos(){
    printf("\n");
    printf("     ");    /// deixar com 5 espa�os
    for(c=0; c<41; c++){ /* 'c' < (4 x qtd de letras)+1*/
        printf("-");
    }
    printf("\n");
}

void cabecalho(){
    printf("       ");    /// deixar 7 espa�os
    {for(c=0; c<10; c++){
        printf("%c   ", letras[c]);
    }
    tracinhos();}
}

int analise(char cam[LIM][LIM], int l, int c, int n) /// receber o trocou e o lin
{   int val = 0;
    if((c-n) >= 0 && (c-n) <= 8){    /// � esquerda
        if(cam[l-1][c-n] == ' '){
            if(n == 2)
                val = 1;
            else if(n == 3){
                if(cam[l-1][c-2] == ' ')
                    val = 1;
            }
            else if(n == 4){
                if(cam[l-1][c-3] == ' ' && cam[l-1][c-2] == ' ')
                    val = 1;
            }
        }
    }
    if((c+n)-2 >= 1 && (c+n)-2 <= 9){   /// � direita
        if(cam[l-1][(c+n)-2] == ' '){
            if(n == 2)
                val = 1;
            else if(n == 3){
                if(cam[l-1][(c+n)-3] == ' ')
                    val = 1;
            }
            else if(n == 4){
                if(cam[l-1][(c+n)-3] == ' ' && cam[l-1][(c+n)-4] == ' ')
                    val = 1;
            }
        }
    }
    if((l+n)-2 >= 1 && (l+n)-2 <= 9){   /// abaixo
        if(cam[(l+n)-2][c-1] == ' '){
            if(n == 2)
                val = 1;
            else if(n == 3){
                if(cam[(l+n)-3][c-1] == ' ')
                    val = 1;
            }
            else if(n == 4){
                if(cam[(l+n)-3][c-1] == ' ' && cam[(l+n)-4][c-1] == ' ')
                    val = 1;
            }
        }
    }
    if((l-n) >= 0 && (l-n) <= 8){   /// acima
        if(cam[l-n][c-1] == ' '){
            if(n == 2)
                val = 1;
            else if(n == 3){
                if(cam[l-2][c-1] == ' ')
                    val = 1;
            }
            else if(n == 4){
                if(cam[l-3][c-1] == ' ' && cam[l-2][c-1] == ' ')
                    val = 1;
            }
        }
    }
    return val;
}

int analise2(char cam1[LIM][LIM], int lin1, int col1, int lin2, int col2, int n) /// receber os dados da ultima ponta do barco
{   int j;
    int val = 0;

    if(lin2 == lin1){
        if(col2 == (col1+n)-1 || col2 == (col1-n)+1){
            if(col2 > col1){
                for(j=col1+1; j<=col2; j++){
                    if(cam1[lin1][j] != ' '){
                        val = 0;
                        break;
                    }else{
                        val = 1;}
                }
            }else{
                for(j=col1-1; j>=col2; j--){
                    if(cam1[lin1][j] != ' '){
                        val = 0;
                        break;
                    }else{
                        val = 1;}
                }
            }
        }else{
            return val;
        }
    }else if(col2 == col1){
        if(lin2 == (lin1+n)-1 || lin2 == (lin1-n)+1){
            if(lin2 > lin1){
                for(j=lin1+1; j<=lin2; j++){
                    if(cam1[j][col1] != ' '){
                        val = 0;
                        break;
                    }else{
                        val = 1;}
                }
            }else{
                for(j=lin1-1; j>=lin2; j--){
                    if(cam1[j][col1] != ' '){
                        val = 0;
                        break;
                    }else{
                        val = 1;}
                }
            }
        }else{
            return val;
        }
    }
    return val;
}


void preencher(char cam[LIM][LIM], int L1, int C1, int L2, int C2, int n)
{   int i;

    if(L2 == L1){
        if(C2 > C1){
            for(i=C1; i<=C2; i++){
                if(n == 2)
                    cam[L1][i] = '2';
                if(n == 3)
                    cam[L1][i] = '3';
                if(n == 4)
                    cam[L1][i] = '4';

                if((C1-1) >= 0 && (C1-1) <= 8)
                    cam[L2][C1-1] = '-';
                if((C2+1) >= 1 && (C2+1) <= 9)
                    cam[L2][C2+1] = '-';
                if((L1-1) >= 0 && (L1-1) <= 8)
                    cam[L1-1][i] = '-';
                if((L1+1) >= 1 && (L1+1) <= 9)
                    cam[L1+1][i] = '-';
            }
        }else{
            for(i=C1; i>=C2; i--){
                if(n == 2)
                    cam[L1][i] = '2';
                if(n == 3)
                    cam[L1][i] = '3';
                if(n == 4)
                    cam[L1][i] = '4';

                if((C2-1) >= 0 && (C2-1) <= 8)
                    cam[L2][C2-1] = '-';
                if((C1+1) >= 1 && (C1+1) <= 9)
                    cam[L2][C1+1] = '-';
                if((L1-1) >= 0 && (L1-1) <= 8)
                    cam[L1-1][i] = '-';
                if((L1+1) >= 1 && (L1+1) <= 9)
                    cam[L1+1][i] = '-';
            }
        }
    }if(C2 == C1){
        if(L2 > L1){
            for(i=L1; i<=L2; i++){
                if(n == 2)
                    cam[i][C1] = '2';
                if(n == 3)
                    cam[i][C1] = '3';
                if(n == 4)
                    cam[i][C1] = '4';

                if((L1-1) >= 0 && (L1-1) <= 8)
                    cam[L1-1][C1] = '-';
                if((L2+1) >= 1 && (L2+1) <= 9)
                    cam[L2+1][C1] = '-';
                if((C1-1) >= 0 && (C1-1) <= 8)
                    cam[i][C1-1] = '-';
                if((C1+1) >=1 && (C1+1) <= 9)
                    cam[i][C1+1] = '-';
            }
        }else{
            for(i=L1; i>=L2; i--){
                if(n == 2)
                    cam[i][C1] = '2';
                if(n == 3)
                    cam[i][C1] = '3';
                if(n == 4)
                    cam[i][C1] = '4';

                if((L2-1) >= 0 && (L2-1) <= 8)
                    cam[L2-1][C1] = '-';
                if((L1+1) >= 1 && (L1+1) <= 9)
                    cam[L1+1][C1] = '-';
                if((C1-1) >= 0 && (C1-1) <= 8)
                    cam[i][C1-1] = '-';
                if((C1+1) >= 1 && (C1+1) <= 9)
                    cam[i][C1+1] = '-';
            }
        }
    }
}


void area1(char campo[10][10]){
    system("cls");
    cabecalho();
    for(l=0; l<10; l++){  /* ser�o 10*/
        if(l<=8)
            printf(" %d   |", l+1);
        else
            printf(" %d  |", l+1);
        for(c=0; c<10; c++){
            printf(" %c |", campo[l][c]);
        }
        tracinhos();
    }
}

void area2(char campo[10][10]){
    printf("\n\n");
    cabecalho();
    for(l=0; l<10; l++){  /* ser�o 10*/
        if(l<=8)
            printf(" %d   |", l+1);
        else
            printf(" %d  |", l+1);
        for(c=0; c<10; c++){
            printf(" %c |", campo[l][c]);
        }
        tracinhos();
    }
}

int troca(char vert_cal){
    int vertic;
    if (vert_cal == 'A' || vert_cal == 'a')
        vertic = 1;
    else if (vert_cal == 'B' || vert_cal == 'b')
        vertic = 2;
    else if (vert_cal == 'C' || vert_cal == 'c')
        vertic = 3;
    else if (vert_cal == 'D' || vert_cal == 'd')
        vertic = 4;
    else if (vert_cal == 'E' || vert_cal == 'e')
        vertic = 5;
    else if (vert_cal == 'F' || vert_cal == 'f')
        vertic = 6;
    else if (vert_cal == 'G' || vert_cal == 'g')
        vertic = 7;
    else if (vert_cal == 'H' || vert_cal == 'h')
        vertic = 8;
    else if (vert_cal == 'I' || vert_cal == 'i')
        vertic = 9;
    else if (vert_cal == 'J' || vert_cal == 'j')
        vertic = 10;
    else
        vertic = 11;
    return vertic;
}


int main(){
    setlocale(LC_ALL, "Portuguese");

    {HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);} /// trecho que faz o programa abrir com a tela maximizada

    char exemplo_1[10][10]={{'1', '-', ' ', ' ', ' ', '-', '1', '-', ' ', ' '}, {'-', ' ', '-', ' ', ' ', ' ', '-', ' ', ' ', '-'}, {' ', '-', '2', '-', ' ', '-', '-', ' ', '-', '4'},
                            {' ', '-', '2', '-', '-', '2', '2', '-', '-', '4'}, {'-', ' ', '-', ' ', '-', '-', '-', ' ', '-', '4'}, {'1', '-', ' ', '-', '3', '-', ' ', ' ', '-', '4'},
                            {'-', '-', ' ', '-', '3', '-', ' ', ' ', ' ', '-'}, {'-', '1', '-', '-', '3', '-', ' ', ' ', ' ', ' '}, {'-', '-', ' ', ' ', '-', ' ', ' ', '-', '-', '-'},
                            {'2', '2', '-', ' ', ' ', ' ', '-', '3', '3', '3'},};

    char exemplo_2[10][10]={{'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'c', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'X', ' ', ' ', ' ', 'X', ' ', 'c', ' ', ' ', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', 'c', ' ', ' ', ' '}, {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' '},
                            {' ', 'X', 'c', 'X', ' ', ' ', ' ', 'X', 'c', 'c'}, {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', 'X', 'c', 'c', 'c', 'X'},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},};

    char campo1[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},};

    char campo2[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},};

    char campo3[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},};

    char campo4[10][10]={{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},};

    char col, nome1[25], nome2[25];
    int valido, i, j, trocou, lin, fim, ct_jog, lil_boat, ct_jog1=1, ct_jog2=1, acertos1=0, acertos2= 0;
    int a=0, b=0;

    /// MENU
    printf("\n                         Bem-Vindo ao menu instru��es do Batalha Naval\n\n");
    printf("--- Leia com aten��o o passo a passo a seguir para montar os barcos de forma correta. ---\n\n");
    printf("1) Para montar seu campo de batalha voc� ter� BARCOS DE 4 TIPOS DIFERENTES. Totalizando 10 barcos.\n");
    printf("1.1) Voc� ter� QUATRO barcos do TIPO 1, TR�S barcos do TIPO 2, DOIS barcos do TIPO 3 e UM barco do TIPO 4.\n");
    printf("1.2) Os barcos do tipo 1 ser�o representados pelo n�mero '1', os do tipo 2 pelo n�mero '2' e assim por diante.\n");
    printf("1.3) Os primeiros barcos que voc� vai posicionar ser�o do tipo 1, em seguida ser�o os do tipo 2 e assim por diante.\n\n");
    printf("2) Cada n�mero (de 1 a 4) ocupa APENAS um espa�o dentro do campo. *� como se cada n�mero fosse um peda�o do barco.*\n");
    printf("2.1) Os barcos tipo 1 podem ser colocados em qualquer local dispon�vel no campo.");
    printf(" Por�m, a partir dos barcos tipo 2, s� ser� poss�vel inserir um barco se tiver espa�o suficiente para ele dentro do campo.\n");
    printf("2.2) A partir da montagem dos barcos tipo 2, � importante que as partes do barco (n�meros) estejam posicionados pr�ximos uns dos outros, de forma que, juntos, formem um barco s�.\n\n");
    printf("3) Quando for perguntado onde quer inserir os barcos, informe PRIMEIRO A COLUNA (letra) e DEPOIS A LINHA. Caso contr�rio a jogada n�o ser� v�lida.\n");
    printf("3.1) Ao informar as coordenadas, a partir dos barcos TIPO 2, informe SOMENTE as coordenadas das EXTREMIDADES dos barcos. Por exemplo:\n   1�) inserir um barco na horizontal;\n   2�) inserir um barco na vertical;\n");
    printf("3.1.1�) Horizontal: primeiro, informe a coluna e linha da primeira extremidade, depois escolha (NA MESMA LINHA) a coluna da outra extremidade, seja � direita ou � esquerda (respeitando o espa�o no campo e o tamanho do barco).\n");
    printf("3.1.2�) Vertical: primeiro, informe a coluna e linha da primeira extremidade, depois escolha (NA MESMA COLUNA) a linha da outra extremidade, seja para cima ou para baixo (respeitando o espa�o no campo e o tamanho do barco).\n");
    printf("3.2) As partes entre as extremidades ser�o preenchidas automaticamente.\n\n");
    printf("4) Durante a montagem, cada barco ter� uma barreira � sua volta, representada por v�rios '-'. Ela serve para que haja um espa�o m�nimo entre os barcos. Mas n�o se preocupe, na hora do jogo ela n�o aparece.\n");
    printf("4.1) Dica: *Fique ligado em rela��o a essa barreira! Na hora do jogo, ao encontrar um barco, ela pode te ajudar a ter no��o se no campo advers�rio tem outros barcos por perto ou n�o ;) *\n");
    printf("\n No final da montagem, o seu campo vai terminar de forma semelhante a esta:");
    area2(exemplo_1);

    printf("\n -Voc� pode perceber que os n�meros '2', '3' e '4' aparecem numa quantidade maior do que o explicado no passo 1.1 .");
    printf("\n -Por�m, lembre-se de que cada n�mero � como se fosse um PEDA�O DO BARCO, como foi dito no passo 2. Por isso respeite bem todo o passo 3.\n");

    printf("\n5) EXEMPLO DE UMA SITUA��O DE JOGO:");
    area2(exemplo_2);

    printf("\n - LEGENDA:");
    printf("\n\t .O 'X' indica que voc� n�o acertou nada;");
    printf("\n\t .A letra 'c' significa que voc� acertou uma parte de um barco;");
    printf("\n\n *Perceba que mesmo que voc� encontre um barco inteiro (que nem na linha 9) ele n�o aparece completo. ");
    printf("Ent�o analise bem todo o campo para n�o desperdi�ar sua pr�xima chance ;) *");

    printf("\n\n - E ent�o, tudo pronto?\n\n");
    system("pause");


    /// IN�CIO
    system("cls");
    printf("-------- Vai come�ar a Batalha!!! --------\n\n");
    printf(" Insira um nome para o Jogador 1: ");
    gets(nome1);
    printf("\n Insira um nome para o Jogador 2: ");
    gets(nome2);
    printf("\n ");
    system("pause");

    /// MONTAGEM JOGADOR 1
    do{
        fim = 1;
        ct_jog = 1;
        lil_boat = 1;
        do{
            valido = 0;
            area1(campo1);
            if(lil_boat >= 1 && lil_boat <= 4)
                printf("\n Montagem barco TIPO 1");
            else if(lil_boat >= 5 && lil_boat <= 10){
                printf("\n Montagem barco TIPO 2");}
            else if(lil_boat >= 11 && lil_boat <= 14)
                printf("\n Montagem barco TIPO 3");
            else if(lil_boat >= 15 && lil_boat <= 16)
                printf("\n Montagem barco TIPO 4");
            printf("\n Monte seu jogo, '%s'. Informe a coluna e a linha para colocar seu navio: ", nome1);
            scanf("%c %d", &col, &lin);
            printf("\n");
            trocou = troca(col);
            if(lin < 1 || trocou < 1 || lin > 10 || trocou > 10){
                lin = 0;
                trocou = 0;
            }else if(campo1[lin-1][trocou-1] != ' '){
                lin = 0;
                trocou = 0;
            }else{
                if(lil_boat >= 1 && lil_boat <= 4){
                    campo1[lin-1][trocou-1] = '1'; /// colocar mensagem indicando em qual barco est�
                    if((trocou-2) >= 0 && (trocou-2) <= 8)
                        campo1[lin-1][trocou-2] = '-';
                    if(trocou >= 1 && trocou <= 9)
                        campo1[lin-1][trocou] = '-';
                    if((lin-2) >= 0 && (lin-2) <= 8)
                        campo1[lin-2][trocou-1] = '-';
                    if(lin >= 1 && lin <= 9)
                        campo1[lin][trocou-1] = '-';
                    lil_boat++;
                    ct_jog ++;
                    fim ++;
                }
                else if(lil_boat >= 5 && lil_boat <= 10){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo1, lin, trocou, 2);
                        if(valido == 1){
                            campo1[lin-1][trocou-1] = '2';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                    else{
                        valido = analise2(campo1, a, b, (lin-1), (trocou-1), 2);
                        if(valido == 1){
                            preencher(campo1, a, b, (lin-1), (trocou-1), 2);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
                else if(lil_boat >= 11 && lil_boat <= 14){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo1, lin, trocou, 3);
                        if(valido == 1){
                            campo1[lin-1][trocou-1] = '3';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }else{
                        valido = analise2(campo1, a, b, (lin-1), (trocou-1), 3);
                        if(valido == 1){
                            preencher(campo1, a, b, (lin-1), (trocou-1), 3);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
                else if(lil_boat >= 15 && lil_boat <= 16){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo1, lin, trocou, 4);
                        if(valido == 1){
                            campo1[lin-1][trocou-1] = '4';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }else{
                        valido = analise2(campo1, a, b, (lin-1), (trocou-1), 4);
                        if(valido == 1){
                            preencher(campo1, a, b, (lin-1), (trocou-1), 4);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
            }
        }while(ct_jog <= 16); /// ct_jog = lil_boat (16 por enquanto)
        for(i=0; i<10; i++){
            for(j=0; j<10; j++){
                if(campo1[i][j] == '-')
                    campo1[i][j] = ' ';
            }
        }
        area1(campo1);
        printf("\n Assim ficou seu campo, '%s'.\n ", nome1);
        system("pause");
    }while(fim <= 16); /// finaliza quando termina de colocar os barcos (16)

   /// MONTAGEM JOGADOR 2
    do{
        fim = 1;
        ct_jog = 1;
        lil_boat = 1;
        do{
            valido = 0;
            area1(campo2);
            if(lil_boat >= 1 && lil_boat <= 4)
                printf("\n Montagem barco TIPO 1");
            else if(lil_boat >= 5 && lil_boat <= 10){
                printf("\n Montagem barco TIPO 2");}
            else if(lil_boat >= 11 && lil_boat <= 14)
                printf("\n Montagem barco TIPO 3");
            else if(lil_boat >= 15 && lil_boat <= 16)
                printf("\n Montagem barco TIPO 4");
            printf("\n Monte seu jogo, '%s'. Informe a coluna e a linha para colocar seu navio: ", nome2);
            scanf("%c %d", &col, &lin);
            printf("\n");
            trocou = troca(col);
            if(lin < 1 || trocou < 1 || lin > 10 || trocou > 10){
                lin = 0;
                trocou = 0;
            }else if(campo2[lin-1][trocou-1] != ' '){
                lin = 0;
                trocou = 0;
            }else{
                if(lil_boat >= 1 && lil_boat <= 4){
                    campo2[lin-1][trocou-1] = '1'; /// colocar mensagem indicando em qual barco est�
                    if((trocou-2) >= 0 && (trocou-2) <= 8)
                        campo2[lin-1][trocou-2] = '-';
                    if(trocou >= 1 && trocou <= 9)
                        campo2[lin-1][trocou] = '-';
                    if((lin-2) >= 0 && (lin-2) <= 8)
                        campo2[lin-2][trocou-1] = '-';
                    if(lin >= 1 && lin <= 9)
                        campo2[lin][trocou-1] = '-';
                    lil_boat++;
                    ct_jog ++;
                    fim ++;
                }
                else if(lil_boat >= 5 && lil_boat <= 10){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo2, lin, trocou, 2);
                        if(valido == 1){
                            campo2[lin-1][trocou-1] = '2';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                    else{
                        valido = analise2(campo2, a, b, (lin-1), (trocou-1), 2);
                        if(valido == 1){
                            preencher(campo2, a, b, (lin-1), (trocou-1), 2);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
                else if(lil_boat >= 11 && lil_boat <= 14){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo2, lin, trocou, 3);
                        if(valido == 1){
                            campo2[lin-1][trocou-1] = '3';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }else{
                        valido = analise2(campo2, a, b, (lin-1), (trocou-1), 3);
                        if(valido == 1){
                            preencher(campo2, a, b, (lin-1), (trocou-1), 3);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
                else if(lil_boat >= 15 && lil_boat <= 16){
                    if(lil_boat % 2 == 1){
                        valido = analise(campo2, lin, trocou, 4);
                        if(valido == 1){
                            campo2[lin-1][trocou-1] = '4';
                            a = lin-1;
                            b = trocou-1;
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }else{
                        valido = analise2(campo2, a, b, (lin-1), (trocou-1), 4);
                        if(valido == 1){
                            preencher(campo2, a, b, (lin-1), (trocou-1), 4);
                            lil_boat ++;
                            ct_jog ++;
                            fim ++;
                        }
                    }
                }
            }
        }while(ct_jog <= 16); /// ct_jog = lil_boat (16 por enquanto)
        for(i=0; i<10; i++){
            for(j=0; j<10; j++){
                if(campo2[i][j] == '-')
                    campo2[i][j] = ' ';
            }
        }
        area1(campo2);
        printf("\n Assim ficou seu campo, '%s'.\n ", nome2);
        system("pause");
    }while(fim <= 16); /// finaliza quando termina de colocar os barcos (16)

    /// ATAQUE JOGADOR 1
    ataque_jog1:
    do{
        do{
            area1(campo3);
            printf("\n- Faltam %d acertos.", 20-acertos1);
            printf("\n Sua vez, '%s'. Escolha um local para atacar: ", nome1);
            scanf("%c %d", &col, &lin);
            printf("\n");
            trocou = troca(col);
            if(lin < 1 || trocou < 1 || lin > 10 || trocou > 10){
                lin = 0;
                trocou  = 0;
            }
            else{
                if(campo3[lin-1][trocou-1] != ' '){
                    lin = 0;
                    trocou = 0;
                    printf("\n INV�LIDO. Coordenada repetida. Jogue Novamente.\n ");
                    system("pause");
                }
                else{
                    if(campo2[lin-1][trocou-1] != ' '){
                        campo3[lin-1][trocou-1] = 'c';   /// fazer aparecer o barco todo s� depois de acertar tudo
                        area1(campo3);
                        printf("\n ACERTOU! ");
                        acertos1 ++;
                        ct_jog1 ++;
                        system("pause");
                        if(acertos1 == 20){  /// MANTER SEMPRE 20
                            area1(campo3);
                            break;
                        }
                    }
                    else{
                        campo3[lin-1][trocou-1] = 'X';
                        ct_jog1 ++;
                        area1(campo3);
                        printf("\n ERROU! Agora � a vez de '%s'. ", nome2);
                        system("pause");
                        goto ataque_jog2;}
                    }
                }
        }while(ct_jog1 <= 100); /// tem que ser o tamanho do tabuleiro
        if (acertos1 == 20 && ct_jog1 <= 101){ /// MANTER ACERTOS SEMPRE 20
            for(i=0; i<10; i++){
                for(j=0; j<10; j++){
                    if(campo3[i][j] == 'c'){
                        campo3[i][j] = campo2[i][j];}
                    if(campo3[i][j] == 'X'){
                        campo3[i][j] = ' ';}
                }
            }
            system("cls");
            area2(campo3);
            printf("\n Parab�ns, '%s', voc� ganhou!!! Encontrou todos os barcos!!\n ", nome1);
            system("pause");
            goto quase2;}
    }while(ct_jog1 <= 100); /// (tam. do tabuleiro)

    /// ATAQUE JOGADOR 2
    ataque_jog2:
    do{
        do{
            area1(campo4);
            printf("\n- Faltam %d acertos.", 20-acertos2);
            printf("\n Sua vez, '%s'. Escolha um local para atacar: ", nome2);
            scanf("%c %d", &col, &lin);
            printf("\n");
            trocou = troca(col);
            if(lin < 1 || trocou < 1 || lin > 10 || trocou > 10){
                lin = 0;
                trocou  = 0;
            }
            else{
                if(campo4[lin-1][trocou-1] != ' '){
                    lin = 0;
                    trocou = 0;
                    printf("\n INV�LIDO. Coordenada repetida. Jogue Novamente.\n ");
                    system("pause");
                }
                else{
                    if(campo1[lin-1][trocou-1] != ' '){
                        campo4[lin-1][trocou-1] = 'c';    /// fazer aparecer o barco todo s
                        area1(campo4);
                        printf("\n ACERTOU! ");
                        system("pause");
                        acertos2 ++;
                        ct_jog2 ++;
                        if(acertos2 == 20){ /// MANTER ACERTOS SEMPRE 20
                            area1(campo4);
                            break;
                        }
                    }
                    else{
                        campo4[lin-1][trocou-1] = 'X';
                        ct_jog2 ++;
                        area1(campo4);
                        printf("\n ERROU! Agora � a vez de '%s'. ", nome1);
                        system("pause");
                        goto ataque_jog1;}
                    }
                }
        }while(ct_jog2 <= 100); /// tem que ser o tamanho do tabuleiro
        if (acertos2 == 20 && ct_jog2 <= 101 ){ /// MANTER ACERTOS SEMPRE 20
            for(i=0; i<10; i++){
                for(j=0; j<10; j++){
                    if(campo4[i][j] == 'c'){
                        campo4[i][j] = campo1[i][j];}
                    if(campo4[i][j] == 'X'){
                        campo4[i][j] = ' ';}
                }
            }
            system("cls");
            area2(campo4);
            printf("\n Parab�ns, '%s', voc� ganhou!!! Encontrou todos os barcos!!\n ", nome2);
            system("pause");
            break;
            goto quase1;
        }
    }while(ct_jog2 <= 100); /// enquanto o limite de jogadas (tam. do tabuleiro) durar ou o jogador acertar todos

    quase1:
        if(acertos2 == 20 && ct_jog1 <= 101 && acertos1 < 20){ /// MANTER ACERTOS2 SEMPRE 20
            for(i=0; i<10; i++){
                for(j=0; j<10; j++){
                    if(campo3[i][j] == ' '){
                        if(campo2[i][j] != ' '){
                            campo3[i][j] = '~';}}
                    if(campo3[i][j] == 'c'){
                        campo3[i][j] = campo2[i][j];}
                }
            }
            area2(campo3);
            printf("\n Os '~' eram as partes que faltavam para voc�, '%s'.\n ", nome1);  /// ao inv�s de deixar os n�meros, trocar pelo 'c'
            system("pause");
            goto acabou;}

    quase2:
        if(acertos1 == 20 && ct_jog2 <= 101 && acertos2 < 20){ /// MANTER ACERTOS1 SEMPRE 20
            for(i=0; i<10; i++){
                for(j=0; j<10; j++){
                    if(campo4[i][j] == ' '){
                        if(campo1[i][j] != ' '){
                            campo4[i][j] = '~';}}
                    if(campo4[i][j] == 'c')
                        campo4[i][j] = campo1[i][j];
                }
            }
            area2(campo4);
            printf("\n Os '~' eram as partes que faltavam para voc�, '%s'.\n ", nome2); /// ao inv�s de deixar os n�meros, trocar pelo 'c'
            system("pause");
            goto acabou;}

    acabou:
        printf("\n     FIM DE JOGO...\n");

    return 0;
}
