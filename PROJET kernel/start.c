#include <cpu.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>

uint32_t  LIGNE=23;
uint32_t  COLONNE=0;


uint16_t *ptr_mem(uint32_t lig, uint32_t col){
  return (uint16_t*)(0xB8000 + 2 *(lig *80 + col));
}
void ecrit_car(uint32_t lig, uint32_t col, char c, uint32_t couleurfond, uint32_t couleurtexte){

	//le deuxième octet contient le format du caractère
	uint8_t  format_du_caractere=(0<<7)+(couleurfond<<4)+couleurtexte; /* les couleurs du texte sont entre 0 et 15 donc elles n'occupent que 4 bits 	et les couleurs de fond sont entre 0 et 7 et n'en occupent que 3 bits et donc on peut sommer sans perdre des informations*/

	//le premier octet contient le code ASCII du caractère
	uint8_t ascii=(uint8_t)c;

	uint16_t* adresse=ptr_mem(lig,col);
	*adresse=(format_du_caractere<<8)+ascii;
}
void efface_ecran(void){
  for (uint32_t i=0;i<25;i++){
    for (uint32_t j=0;j<80;j++){
      ecrit_car(i,j,' ',0,0); 
    }
  }

}
void place_curseur(uint32_t lig, uint32_t col) {

	uint16_t commande=0x3D4;
	uint16_t donnees=0x3D5;
	uint16_t position=col+lig*80;
  	uint8_t  ptbasse=position;
	outb(0x0F,commande);
	outb(ptbasse,donnees);
	uint8_t  pthaute=position>>8;
	outb(0x0E,commande);
	outb(pthaute,donnees);
}
void defilement(void){
	int i,j;
	uint16_t *source,*destination;
	for(i=0; i<25;i++) { 
		if (i==24){
			for(j=0;j<80;j++){
				ecrit_car(24,j,' ',0,0);
			}
		}
		else {
			for(j=0; j<80;j++) { 
			source=ptr_mem(i+1,j); 
			destination=ptr_mem(i,j); 
			//*destination=*source;
			memmove(destination,source,2);
			//(uint16_t*)
			}
		}	
	}

	
}
void traite_car(char c){
	if(c>=32 && c<=126) {
		ecrit_car(LIGNE,COLONNE,c,0,15);
		COLONNE+=1;
	}
	
	else if(c==8){
		if (COLONNE!=0) {
			COLONNE-=1;
			place_curseur(LIGNE,COLONNE);
		}
	}
	
	else if(c==9) {
		
			if ((COLONNE/8+1)*8<80){
				COLONNE=(COLONNE/8+1)*8;
				place_curseur(LIGNE,COLONNE);
			} 
			else if ((COLONNE/8+1)*8==80){
				COLONNE=79;
				place_curseur(LIGNE,79);
			} 
		
		/*
		else{
			defilement();
			LIGNE=24;
			if ((COLONNE/8+1)*8<80) {
				COLONNE=(COLONNE/8+1)*8;
				place_curseur(LIGNE,COLONNE);
			}
			else if ((COLONNE/8+1)*8==80){
				COLONNE=79;
				place_curseur(LIGNE,COLONNE);
			}

		}
		*/
	}
	
	else if(c==10) {
		if (LIGNE!=24){
			LIGNE+=1;
			COLONNE=0;
			place_curseur(LIGNE,COLONNE);
		}
		else{
			defilement();
			LIGNE=24;
			COLONNE=0;
			place_curseur(LIGNE,COLONNE);
		}
	}
	else if(c==12) {
		efface_ecran();
		LIGNE=0;
		COLONNE=0;
		place_curseur(LIGNE,COLONNE);
	}
	else if(c==13){
		COLONNE=0;
		place_curseur(LIGNE,COLONNE);
	}
}

uint32_t fact(uint32_t n)
{
    uint32_t res;
    if (n <= 1) {
        res = 1;
    } else {
        res = fact(n - 1) * n;
    }
    return res;
}
void console_putbytes(const char *s, int len){
	place_curseur(LIGNE,COLONNE); 
	for(int i=0;i<len;i++){
		if(COLONNE==80) {
			if (LIGNE == 24){ 
				defilement();
				LIGNE=24;
				COLONNE=0;
				place_curseur(LIGNE,COLONNE);
				traite_car(s[i]);
				
			}
			else{
				COLONNE=0;
				LIGNE+=1;
				place_curseur(LIGNE,COLONNE);
				traite_car(s[i]);
				//COLONNE=1;
				//LIGNE+=1;
			}
		    
		}
		else {
			place_curseur(LIGNE,COLONNE);
			traite_car(s[i]);
		}

	}

}




void kernel_start(void)
{
    uint32_t x = fact(5);
    // quand on saura gerer l'ecran, on pourra afficher x
    (void)x;
    // on ne doit jamais sortir de kernel_start
    while (1) {
        
        efface_ecran();
        /*
		
        ecrit_car(0,1,'m',2,0);
        ecrit_car(0,2,'i',3,0);
        ecrit_car(0,3,'n',4,0);
        ecrit_car(0,4,'e',5,0);
        place_curseur(4,0);
        traite_car('a');
		*/

		//efface_ecran();
		//defilement();
		ecrit_car(0,0,'a',1,0);
		console_putbytes("WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nWA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nwa sma3 sma3\tana wwa3er\n",378);
		console_putbytes("aminux is aminux",16);
		console_putbytes("\rkiknux is aminux",17);
		console_putbytes("WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nWA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nwa sma3 sma3\tana wwa3er\f",378);
		console_putbytes("WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nWA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone WA phelma ya lwarda ou 3lik i ti7 nda wa phelma wa khra mal mok tab3ana hola mi amo amine el mejore del mundo cabrone\nwa sma3 sma3\tana wwa3er",378);
		


        // cette fonction arrete le processeur
        hlt();
    }
}
