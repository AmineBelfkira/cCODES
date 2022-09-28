#include <console.h>
#include <stdio.h>
#include <segment.h>
#include <cpu.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>

#include "start.h"
#include "time.h"
//#include "traitants.S"


#define QUARTZ 0x1234DD
#define CLOCKFREQ 50


extern void traitant_IT_32();

double  CLOCK=0;
int SEC=2;

void afficheHAUTDROITE(const char *s){
    unsigned long len=strlen(s);
    for (int i=79-len;i<80;i++){
        ecrit_car(0,i,' ',0,0);
    }
    place_curseur(0,79-len);
    console_putbytes(s,len);

}

void tic_PIT (void) {
  outb (0x20, 0x20);
  int min; int hr;
  char chaine[8];
  CLOCK += 1;
  SEC = CLOCK/CLOCKFREQ;
  min = (SEC /60)%60;
  hr = SEC /360;
  SEC = SEC%60;
  sprintf (chaine, "%d:%d:%d", hr, min, SEC);
  afficheHAUTDROITE (chaine);
  
}



void init_traitant_IT(int32_t num_IT, void (*traitant)(void)){  
    uint32_t *adresse=(uint32_t*)(0x1000+num_IT*8);
    uint32_t mot1= ((uint32_t)KERNEL_CS <<16) +((uint32_t)(traitant) << 16);
    uint32_t mot2=(((uint32_t)(traitant) >> 16)<<16) + (uint32_t)0x8E00;
    *adresse=mot1;
    *(adresse+1)=mot2;
}

void freq_clock () {
  outb (0x43, 0x34);
  uint16_t frequence = (uint16_t) (QUARTZ/CLOCKFREQ);
  uint8_t poids_faibles_frequence = frequence & 0xFF;
  uint8_t poids_forts_frequence = frequence >> 8;
  outb (poids_faibles_frequence, 0x40);
  outb (poids_forts_frequence, 0x40);
}

void masque_IRQ(uint32_t num_IRQ, bool masque) {
  uint8_t masque1 = inb(0x21); 
  uint8_t valeur;
  uint8_t bin=(0b1<< num_IRQ);
  if (masque) {
    valeur = bin | masque1;
  }
  else {
    valeur = ~ bin & masque1;
  }
  
  outb (valeur, 0x21);
}

/*
void kernel_start1(void)
{
// initialisations

// démasquage des interruptions externes
sti();
// boucle d’attente
while (1) hlt();
}

*/

void kernel_start(void)
{ 
  //efface_ecran;
  efface_ecran();
  
  //initialisation
  init_traitant_IT (31, traitant_IT_32);
  init_traitant_IT (32, traitant_IT_32);
  masque_IRQ(0,false);
  freq_clock();
  
  // démasquage des interruptions externes
  sti();
  
  
  //Boucle d'attente
  while (1) {
      hlt();
  }
}
