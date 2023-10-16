#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct Idopont {
  int ora, perc, masodperc;
} Idopont;

Idopont ido(char *c) {
  Idopont most;
  char idotartam;
  if(sscanf(c, "%d:%d:%d", &most.ora, &most.perc, &most.masodperc) == 3) {
    return most;
  }
  else if(sscanf(c, "%dh %dm %ds", &most.ora, &most.perc, &most.masodperc) == 3)
    return most;
  sscanf(c, "%d:%d %cM", &most.ora, &most.perc, &idotartam);
  most.masodperc = 0;
  if (idotartam == 'A') {
    if (most.ora == 12) {
      most.ora = 0;
    }
  }
  else {
    if (most.ora != 12) {
      most.ora += 12;
    }
  }
  return most;
}

int main(void) {
  char sztring[50];
  Idopont nagy;
  fgets(sztring, sizeof(sztring), stdin);
  sztring[strcspn(sztring, "\n")] = 0;
  nagy = ido(sztring);
  printf("%02d:%02d:%02d", nagy.ora, nagy.perc, nagy.masodperc);
  return 0;
}