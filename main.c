#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void conversao(int n, int A);
void conversaoNegativa(int n);
void conversaoDecimal(double N, int A);

int main(void) {

  int opc = 10;
  int n = 0;
  int opc2 = 0;
  double N;

  system("clear");
  printf("Olá! Bem vindo à calculadora didática! Aqui você pode converter números da base 10 para outras bases");
  
  while(opc != -1){

    printf("\n\n[2] - Base 2 | [8] - Base 8 | [16] - Base 16 | [0] - BCD | [3] - Base 2 Negativa (16 bits e complemento)\n");
    printf("[4] - Decimal para double/float (Notação Científica) | [-1] - Sair\n\n");
    scanf("%d", &opc);

    if(opc == -1){

      return 0;

    }else if(opc == 2){

      system("clear");
      printf("Qual número gostaria de converter para binário (base 2)?\n\n");
      scanf("%d", &n);
      
      if(n < 0){

        conversaoNegativa(n);
        
      }else{

        conversao(n, 2);
        
      }

    }else if(opc == 8){

      system("clear");
      printf("Qual número gostaria de converter para octal (base 8)?\n\n");
      scanf("%d", &n);
      
      if(n < 0){

        printf("\nPor favor coloque um número maior que zero\n\n");

      }else{

        conversao(n, 8);
        
      }

    }else if(opc == 16){

      system("clear");
      printf("Qual número gostaria de converter para hexadecimal (base 16)?\n\n");
      scanf("%d", &n);

      if(n < 0){

        printf("\nPor favor coloque um número maior que zero\n\n");

      }else{

        conversao(n, 16);
        
      }

    }else if(opc == 0){

      system("clear");
      printf("Qual número gostaria de converter para BCD?\n\n");
      scanf("%d", &n);

      if(n < 0){

        printf("\nPor favor coloque um número maior que zero\n\n");

      }else{

        conversao(n, 0);

      }
      
    }else if(opc == 3){

      system("clear");
      printf("Qual número em negativo gostaria de converter para binário?\n\n");
      scanf("%d", &n);
      conversaoNegativa(n);
      
    }else if(opc == 4){

      system("clear");
      printf("Qual número em negativo gostaria de converter para notação científica?\n\n");
      scanf("%lf", &N);
      printf("\nGostaria de converter ele em float ou double?\n");
      printf("\n[0] - Float | [1] - Double\n\n");
      scanf("%d", &opc2);
      if(opc2 != 1 || opc2 != 0){

        printf("\n\nPor favor coloque 0 ou 1");
        
      }else{

        conversaoDecimal(N, opc2);
        
      }
    }
  }
  
  return 0;
}


void conversao(int n, int A){

  int BCD = 0;
  
  if(A == 0){

    A = 2;
    BCD = 1;
    
  }

  int m = n/A;
  int q = n % A;
  int num[16];
  int cont = 0;

  while((m != 0) || (cont == 0)){
  
    printf("\n%d / %d = %d (Resto: %d)", n, A, m, q);
    num[cont] = q;
    cont++;
    n = m;
    m = n/A;
    q = n % A;
    
  }

  if(q != 0){

    printf("\n%d / %d = %d (Resto: %d)", n, A, m, q);
    num[cont] = q;
    cont++;
    
  }

  if ((BCD == 1) && (cont % 4 != 0)) {
      int zeros = 4 - (cont % 4);
      for(int i = 0; i < zeros; i++){

        num[cont] = 0;
        cont++;
        
      }
  }

  int temp;

  for(int i = 0, j = cont - 1; i < j; i++, j--){

    temp = num[i];
    num[i] = num[j];
    num[j] = temp;

  }

  if(A == 16){

    printf("\nPegamos os restos das divisões em ordem reversa e juntamos elas no resultado\n");
    printf("(Também convertemos os restos que são acima de 9 em letras do alfabeto até o 15(F)):\n\n");

    for(int i = 0; i < cont; i++){

      if(num[i] == 10){
        
        printf("A");
        
      }else if(num[i] == 11){

        printf("B");
        
      }else if(num[i] == 12){

        printf("C");

      }else if(num[i] == 13){

        printf("D");

      }else if(num[i] == 14){

        printf("E");

      }else if(num[i] == 15){

        printf("F");

      }else{

        printf("%d",num[i]);
        
      }

    }
    
  }else if((A == 2) && (BCD == 1)){

    printf("\nPegamos os restos das divisões em ordem reversa e juntamos elas no resultado\n");
    printf("(Também organizamos os números em binário para que fiquem em grupos de 4 bits cada):\n\n");
    
    for(int i = 0; i < cont; i++){

      printf("%d",num[i]);
      
      if(((i+1) % 4) == 0){

        printf(" ");

      }
      
    }
    
  }else{

    printf("\nPegamos os restos das divisões em ordem reversa e juntamos elas no resultado:\n\n");

    for(int i = 0; i < cont; i++){

      printf("%d",num[i]);
    
    }
  }
}


void conversaoNegativa(int n){
  
  if (n < 0){

    n = n * (-1);
    
  }

  int m = n/2;
  int q = n % 2;
  int num[16], neg[16];
  int cont = 0;

  while((m != 0) || (cont == 0)){

    printf("\n%d / 2 = %d (Resto: %d)", n, m, q);
    num[cont] = q;
    
    if(q == 0){
      neg[cont] = 1;
    }else if(q == 1){
      neg[cont] = 0;
    }
    
    cont++;
    n = m;
    m = n/2;
    q = n % 2;

  }

  if(q != 0){

    printf("\n%d / 2 = %d (Resto: %d)", n, m, q);
    num[cont] = q;

    if(q == 0){
      neg[cont] = 1;
    }else if(q == 1){
      neg[cont] = 0;
    }
    
    cont++;

  }

  int temp, tempNeg;

  for(int i = 0, j = cont - 1; i < j; i++, j--){

    temp = num[i];
    num[i] = num[j];
    num[j] = temp;

    tempNeg = neg[i];
    neg[i] = neg[j];
    neg[j] = temp;
    
  }

  printf("\nPegamos os restos das divisões em ordem reversa e juntamos elas no resultado:\n\n");

  for(int i = 0; i < cont; i++){

    printf("%d",num[i]);

  }

  printf("\n\nAgora nós invertemos o número para que todos os 1s virem 0 e todos os 0s virem 1:\n\n");

  for(int i = 0; i < cont; i++){

    printf("%d",neg[i]);

  }

  printf("\n\nE finalmente, nós adicionamos 1 ao número (Complemento a 2):\n\n");

  int j = cont - 1;

  if(neg[j] == 0){

    neg[j] = 1;

  }else{

    while((neg[j] != 0) && (j != 0)){

      if(neg[j - 1] == 0){

        neg[j] = 0;
        neg[j-1] = 1;
        
      }else if(neg[j - 1] == 1){

        neg[j] = 0;
        
      }

      j--;

    }
    
  }

  for(int i = 0; i < cont; i++){

    printf("%d",neg[i]);

  }
  
}


void conversaoDecimal(double N, int A){

  int neg = 0;
  int n = N;
  N = N - n;

  printf("\nPrimeiro, convertemos a parte inteira do número para binário:\n\n");
  
  if(n < 0){

    n = n * (-1);
    neg = 1;
    
  }
  
  int m = n/2;
  int q = n % 2;
  int num[64];
  int cont = 0;

  while((m != 0) || (cont == 1)){

    printf("\n%d / 2 = %d (Resto: %d)", n, m, q);
    num[cont] = q;
    cont++;
    n = m;
    m = n/2;
    q = n % 2;

  }

  if(q != 0){

    printf("\n%d / 2 = %d (Resto: %d)", n, m, q);
    num[cont] = q;
    cont++;

  }

  int temp;
  
  cont++;

  for(int i = 0, j = cont - 1; i < j; i++, j--){

    temp = num[i];
    num[i] = num[j];
    num[j] = temp;

  }

  printf("\nPegamos os restos das divisões em ordem reversa e juntamos elas no resultado:\n\n");

  for(int i = 0; i < cont; i++){

    if(i == 0){

      printf("%d", neg);
      
    }
    
    printf("%d",num[i]);

  }

  float dec = N;
  float decmult;
  int contDEC = 0;
  int DECBN[23];
  int tagN = 0;
  
  if(N != 0){

    tagN = 1;
    
    printf("\nAgora pegamos a parte decimal do número para converter\n\n");

    while((dec != 0) && (contDEC < 23)){

      decmult = dec * 2;
      printf("%f * 2 = %f\n", dec, decmult);

      if(dec > 1){

        DECBN[contDEC] = 1;
        decmult = dec - 1;
        printf("%f - 1 = %f\n", dec, decmult);
        dec = dec - 1;
        
      }else if(dec < 1){

        DECBN[contDEC] = 0;
        dec = dec * 2;
        
      }

      contDEC++;
      
    }

    printf("Quando o número ultrapassa de 1, nós colocamos 1 no número binário, e senão, colocamos 0:\n\n");

    for(int i = 0; i < contDEC; i++){

      printf("%d", DECBN[i]);

    }

    printf("\n\nColocando os dois juntos...\n\n");

    for(int i = 0; i < cont; i++){

      printf("%d",num[i]);

    }

    printf(".");
    
    for(int i = 0; i < contDEC; i++){

      printf("%d", DECBN[i]);

    }

    printf(" <--- Decimal");
    
  }

  printf("\n\nAgora transformamos o número numa notação científica\n\n");

  for(int i = 0; i < cont; i++){

    printf("%d", num[i]);
    if(i == 0){

      printf(".");
      
    }

  }

  printf(" x 2^%d\n", (cont-1));

  printf("\nEste é nosso expoente sem viés (sem alteração para caber num float ou double)\n\n");

  int expo = 0;
  int expoBN[23];

  if(A == 0){

    printf("Pegando esse expoente nós então iremos adicioná-lo ao expoente do float baseado na seguinte fórmula:\n");
    printf("Expoente normal + (2^[n-1] - 1)\n");
    printf("Onde n é o nº de bits que o double ou float tem na parte inteira do seu armazenamento\n");

    expo = cont-1 + ((pow(2, 7)) - 1);
    printf("(Nesse caso, o resultado é %d)\n", expo);
    
  }else if(A == 1){

    printf("Pegando esse expoente nós então iremos adicioná-lo ao expoente do double baseado na seguinte fórmula:\n");
    printf("Expoente normal + (2^[n-1] - 1)\n");
    printf("Onde n é o nº de bits que o double ou float tem na parte inteira do seu armazenamento\n");

    expo = cont-1 + ((pow(2, 10)) - 1);
    printf("(Nesse caso, o resultado é %d)\n", expo);
    
  }

  printf("\nAgora devemos converter o novo expoente parar binário:\n");

  int expoNeg = 0;

  if(expo < 0){

    expo = expo * (-1);
    expoNeg = 1;

  }

  int expoM = expo/2;
  int expoQ = expo % 2;
  int expoNum[64];
  int contExpo = 0;

  while((expoM != 0) || (contExpo == 1)){

    printf("\n%d / 2 = %d (Resto: %d)", expo, expoM, expoQ);
    expoNum[contExpo] = expoQ;
    contExpo++;
    expo = expoM;
    expoM = expo/2;
    expoQ = expo % 2;

  }

  if(expoQ != 0){

    printf("\n%d / 2 = %d (Resto: %d)", expo, expoM, expoQ);
    expoNum[contExpo] = expoQ;
    contExpo++;

  }

  int expoTemp;

  if(expoNeg == 0){

    expoNum[contExpo] = 0;

  }else{

    expoNum[contExpo] = 1;

  }

  contExpo++;

  for(int i = 0, j = contExpo - 1; i < j; i++, j--){

    expoTemp = expoNum[i];
    expoNum[i] = expoNum[j];
    expoNum[j] = expoTemp;

  }

  printf("\n");

  for(int i = 0; i < contExpo; i++){

    printf("%d",expoNum[i]);

  }

  printf("\n\nJuntando agora tudo que nós temos...:\n\n");
  printf("Sinal: ");
  
  if(neg == 0){

    printf("0(+)");
    
  }else if(neg == 1){

    printf("1(-)");
    
  }

  printf(" Expoente: ");

  for(int i = 0; i < contExpo; i++){

    printf("%d", expoNum[i]);

  }

  printf(" Mantissa: ");

  for(int i = 0; i < cont; i++){

    printf("%d",num[i]);

  }
  
}
