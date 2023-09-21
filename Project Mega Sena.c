#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define existe 1
#define nexiste 0


    void opcoes();
	void surpresinha();
	void selecionar_numeros();
	void sorteio ();
	void sorteio_opcoes();
    
	int aposta[15], i, j,*pont;
	int num[15];
	
	struct apostas {
		int surpresa[15],num[15];
	};
	
int main(){
	
	srand (time(NULL));
	
 printf ("\nBem vindo a mega-sena\n");
 opcoes();			   			   
}

void selecionar_numeros (){
	int numeros, qt , rep, controle = 1, aux; 
	char sn;
		
	 while(numeros < 6 || numeros > 15){
	 
		printf ("Quantos numeros deseja apostar?( de 6 a 15)\n ");
	     scanf ("%d",&numeros);	
	}		 

	 	printf ("digite os numeros ");
	 	
 pont =&numeros;
	for (i=0;i<*pont;i++){  //ponteiro
	    controle = 1;
	   	scanf ("\t%d", &rep);	   	
	   		
	   	if (rep>0 && rep <61){	   	
		   
	   			for (j=0;j<i;j++){
	   	   			if (rep == aposta[j]){
	   	   				printf ("Numero existente, digite outro \n");
	   	   				i--;
	   	   				controle = 0;
	   	   				break;
			   	     }
		           }
			
				if(controle){
					aposta[i]= rep;
		   		}
		   		
			
    	   } 
				else{
					printf ("digite valores ere 1 e 60\t");
					i--;
			
				}

	}	   	
	
		for (i=0;i<*pont;i++){   //Ordenando os números!!! e ponteiro
			for(j=i+1;j<numeros;j++) {
				if (aposta[j] < aposta[i]){
					aux=aposta[i];
					aposta[i]=aposta[j];
					aposta[j]=aux;
				}
			}
		}
		
	 printf ("Numeros escolhidos:\n");
	 
	 for (i=0;i<*pont;i++){
	   	
		   printf ("\t%d", aposta[i]);
	 }
		
	   	   printf ("\nconfirma os numeros?\n");
		   fflush(stdin);
	   	   scanf ("%c", &sn);
	   	 	 if (sn == 's' || sn == 'S'){
	   	  		sorteio_opcoes();
			 }
	   	  		else if (sn =='n' || sn =='N'){
	   	  			selecionar_numeros();
	   	     	}
	   	     
 }
	   	  
void surpresinha (){
	int qt,rep, num[15],trocou=1,aux=0,apostas,y;
	char sn;
	printf ("Quantas apostas deseja fazer?\n");
	scanf ("%d",&apostas);
	
	struct apostas surpresinha[apostas];
	for (y=0;y<apostas;y++){
	struct apostas surpresinha;
	do {	printf ("\nQuantos numeros deseja apostar?\nDefina de 6 a 15 numeros\n");
	scanf ("%d", &qt);

 }
  while (qt <6 || qt >15);
	
	for (i=0;i<qt;i++){
	
	   do {
		 num[i] = rand() % 61;
		 rep = existe;
		  	for (j=0;j<i;j++)
		  	  if (num[i]== num[j] || num[i]==0)
		  	      rep = nexiste	;	  	  	
	   } while (rep == nexiste);		

	}

		for (i=0;i<qt;i++){   //Ordenando os números!!!
			for(j=i+1;j<qt;j++) {
				if (num[j] < num[i]){
					aux=num[i];
					num[i]=num[j];
					num[j]=aux;
				}
			}
		}
	
	for(i=0;i<qt;i++){
		printf("%d ",num[i]);
	
	}
		
	}
	
	printf ("\nconfirma os numeros? (s/n))\n");
		   fflush(stdin);
	   	   scanf ("%c", &sn);
	   	 	 if (sn == 's' || sn == 'S'){
	   	  		sorteio_opcoes(num,qt);
	   	  		resultado_sorteio(num,qt);
			 }
	   	  		else if (sn =='n' || sn =='N'){
	   	  			/*surpresinha();*/
	   	     	}
}

void opcoes (int resposta){
	 printf ("Escolha uma das opcoes:\n1 - Escolher numeros.\n2 - Surpresinha.\n3 - Sorteio e opcoes\n");
 	 scanf ("%d",&resposta);
	    if (resposta == 2 ){
	        surpresinha();
        } 
			else if (resposta == 1 ){
			   selecionar_numeros();
		    }
				else if (resposta == 3 ){
			   		sorteio_opcoes();
	         	}		 
				 	else {
		   				printf ("Opcao invalida\n\n");
		   				opcoes(resposta);
					 }		
}
	
void sorteio_opcoes (void)	{
		
	//struct numeros
		
		char resposta;
		
		do{
			printf ("deseja ver o sorteio? (s/n))\n");
			fflush(stdin);
	        scanf("%c",&resposta);
	        resposta = toupper(resposta);	        
		}while(resposta != 'N' && resposta != 'S');	
		
		if(resposta == 'N'){
	        	main ();
	        }else if(resposta == 'S'){
	        	sorteio();
	      	        }
       		
}

void sorteio (){
	int i, j,k, rep, num[6],trocou=1,aux=0;
		
	for (i=0;i<6;i++){
	
	   do {
		 num[i] = rand() % 61;
		 rep = existe;
		  	for (j=0;j<i;j++)
		  	  if (num[i]== num[j] || num[i] == 0)
		  	      {
					rep = nexiste;}
		  	      
						  	  	
	   } while (rep == nexiste);		

	}

		for (i=0;i<6;i++){   //Ordenando os números!!!
			for(j=i+1;j<6;j++) {
				if (num[j] < num[i]){
					aux=num[i];
					num[i]=num[j];
					num[j]=aux;
				}
			}
		}
	
	for(i=0;i<6;i++){
		printf("%d ",num[i]);
	
	}
	printf ("\n");
 resultado_sorteio(num,6);	
 
}

int resultado_sorteio (int num[],int n, int *pont){
int i,l,j,m,k=0, acertos[6],q;

   for (m=0;m<n;m++){
        for (i=0;i<7;i++){
	 	       if (num[m]==aposta[i]){
	 	       	
	 	     	  acertos[k]= aposta[i];
	 	     	  k++;
	           	}
		     }
	   }

/*for (m=0;m<n;m++){  //surpresinha
        for (j=0;j<7;j++){
	 	       if (num[m]==num1[j]){
	 	       	
	 	     	  acertos[k]= num1[j];
	 	     	  k++;
	           	}
		     }
	   }

    for (j=0;j<k;j++){
       printf ("%d ",num1[j]);  //surpresinha*/
       

	 if (k>0){  	   
 printf ("Numeros acertados:\n");
 
   for (l=0;l<k;l++){
       printf ("%d ",acertos[l]);
   
}
}
  
   if (k==4){
   	printf ("parabens, voce fez uma quadra " );
   	
   	 }else if  (k==5){
   	  	  printf ("parabens, voce fez uma quina! " );
   	  	 } else if  (k==6){
   	  	  	printf ("parabens, voce fez uma sena! " );
			   }
                    else if  (k<1){
 	                      printf ("voce nao acertou nenhum \n");
                         }
                            else if (k<4){
			                  printf ("\nNao foi dessa vez\n ");
			                    }
}
