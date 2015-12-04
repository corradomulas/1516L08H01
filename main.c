/*Funzionante: sì. Svolto: sì. Approfondimenti: N/D.
#################PROGRAMMA LAB08 - 12BHDLZ - Esercizio 4/H###################
#                                                                           #
#Copyright © 2015 Corrado Mulas.                                            #
#                                                                           #
#Rilasciato dietro licenza GNU GENERAL PUBLIC LICENSE VERSION 3             #
#                                                                           #
#    This program is free software: you can redistribute it and/or modify   #
#    it under the terms of the GNU General Public License as published by   #
#    the Free Software Foundation, either version 3 of the License, or      #
#    (at your option) any later version.                                    #
#                                                                           #
#    This program is distributed in the hope that it will be useful,        #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of         #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          #
#    GNU General Public License for more details.                           #
#                                                                           #
#    You should have received a copy of the GNU General Public License      #
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.  #
#                                                                           #
#############################################################################
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	char std1[60];
	char * str;
	int i = 0;
	int len = 0;
	int c = 0;
	int leng[60]; 
    
	/* * Nel vettore leng[], la posizione rappresenta il numero di caratteri misurati da strlen(), 
	 * * mentre il valore della cella corrisponde al numero di parole che hanno quella data lunghezza.
	 * *
	 * */
	printf("Inserire 5 parole separate da spazi, per un massimo di 60 caratteri: ");
		
		gets(std1); //La gets() è roba da matti, sarebbe stata meglio la fgets().

//Inizializzazione del vettore leng[], per azzerare tutto l'array.
	for(i = 0; i < 60; i++)
	{
		leng[i] = 0;
	}

	str = strtok(std1, " ");	//Con strtok() la stringa viene spezzata in parole, utilizzando gli spazi come delimitatori.
	while (str != NULL && c < 5)
	{
		//printf ("%s\n",str);  //TEST!
		len += strlen(str);	//Incremento la variabile len, perché mi indica la lunghezza totale della stringa, esclusi gli spazi.

		leng[strlen(str)-1]++; 
		
		/* Seguendo il principio indicato nel commento relativo a leng[], ora 
		 * il programma incrementa la cella in posizione pari alla lunghezza della parola.
		 * In questo modo, se si hanno due parole di lunghezza 10, nella cella n°10 si avrà
		 * un valore 2.
		 * */

		str = strtok (NULL, " ");
		c++; 
		/*c serve a limitare a 5 il numero di parole ricevute da strtok(). In generale,
		viene usato anche per indicare quante parole sono contenute nella stringa. Se la stringa
		ha meno di 5 parole, la prima condizione del while farà sì che c non raggiunga il suo valore
		massimo, 5.
		*/
	}	
	
	//stampo il numero di parole contenuto nella stringa.
		printf("\nLa stringa contiene %d parole.\n", c);
	
	//stampo la lunghezza media delle parole, utilizzando un cast di tipo float con due cifre decimali.
		printf("\nLunghezza media delle parole: %.2f\n", (float)len/5);
	
	
	//Ora col for leggo leng[] per produrre una statistica sul numero di parole con un dato numero di caratteri.
	for(i = 0; i < 60; i++)
	{
		if(leng[i] != 0) //se leng[i] = 0, significa che non ci sono parole di lunghezza i. Perciò non ha senso stampare qualcosa.
		{
			if(leng[i] == 1)
			{	//Non è significativo, ma la grammatica per me è importante.
				printf("c'è %d parola con %d caratteri\n", leng[i], i+1);
			}
			else
			{
				printf("ci sono %d parole con %d caratteri\n", leng[i], i+1);
			}
		}
	}
	return 0;
}
