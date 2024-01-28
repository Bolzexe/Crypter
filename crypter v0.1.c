#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CRYPT 1
#define DECRYPT 2

int giorno() {
    // Dichiarazione di variabili
    time_t ora_corrente;
    struct tm *data_ora;

    // Ottenere l'orario corrente
    time(&ora_corrente);

    // Convertire l'orario corrente nella struttura tm
    data_ora = localtime(&ora_corrente);

    // Estrarre solo il giorno
    int giorno = data_ora->tm_mday;

    return giorno;
}

int main() {
	
char alfa[58] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '$', '%', '(', '?'};
	
    int pw, today, sl;
    srand(time(NULL));
    
    today=giorno();
    
    if (today>0 && today<9) {
        sl=today;
    } else if (today>9 && today<19) {
        sl=today-10;
    } else if (today>19 && today<29) {
        sl=today-20;
    } else if(today==30) {
        sl=0;
    } else if(today==31) {
        sl=1;
    } else {
        printf("Giorno non valido");
        return 1;
    }

printf ("********************************************\n");
printf ("\t\tCRYPTER v0.1\n");
printf ("********************************************\n\n");
printf ("Inserire password attuale: ");
    scanf("%d", &pw);

    if (pw==sl) {		//sol: numero_di_verifica*2, numero_di_verifica-giorno_corrente
        int cod=rand()%10+1;
        printf ("\nVerificare codice %d: ", cod);
        int x, y, cont=0;
        scanf ("%d", &x);
        if (x==(cod*2))
        {
        	printf ("\nverificare codice (passo 2): ");
        		scanf ("%d", &y);
        		printf ("\n");
				if (y==(cod*2)-today)
				{
				printf ("Accesso Consentito\n\n");
				int scelta, key, q, q2, w, conta=0, offset;
				char car[10];
				key=(today-(today/2));
				printf ("*-------MENU' PRINCIPALE-------*\n\n");
				printf ("Premere 1 per criptare\nPremere 2 per decriptare\n\n");
				scanf ("%d", &scelta);
				switch (scelta)
				{
					case CRYPT:
						if (today<4)
						{
							offset=1;
						} else if (today>=5 && today<11)
						{
							offset=2;
							
						} else if (today>=11 && today<16)
						{
							offset=3;
							
						} else if (today>=16 && today<21)
						{
							offset=4;
							
						} else if (today>=21 && today<26)
						{
							offset=5;
							
						} else if (today>26 && today<30)
						{
							offset=6;
							
						} else if (today>=30)
						{
							offset=7;
						}
						printf ("Inserire il testo da criptare (10 caratteri); ogni lettera separata da uno spazio\n\n");
						
						for (q=0; q<10; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice criptato: ");
						for (q=0; q<10; q++)
						{
							for (w=0; w<58;w++)
							{
							if (car[q]==alfa[w])
							{
								if (conta%2==0)
								{
									printf ("%c", alfa[w+offset]);
								}
								else
								{
									printf ("%c", alfa[w-offset]);
								}
								conta++;
							}	
							}
						}
						printf ("\n\noffset usato per la criptazione: +/- %d", offset);
						break;
						
					case DECRYPT:
						if (today<4)
						{
							offset=1;
						} else if (today>=5 && today<11)
						{
							offset=2;
							
						} else if (today>=11 && today<16)
						{
							offset=3;
							
						} else if (today>=16 && today<21)
						{
							offset=4;
							
						} else if (today>=21 && today<26)
						{
							offset=5;
							
						} else if (today>26 && today<30)
						{
							offset=6;
							
						} else if (today>=30)
						{
							offset=7;
						}
						
						printf ("Inserire il testo da decriptare (10 caratteri); ogni lettera separata da uno spazio\n\n");
						
						for (q=0; q<10; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice decriptato: ");
						for (q=0; q<10; q++)
						{
							for (w=0; w<58;w++)
							{
							if (car[q]==alfa[w])
							{
								if (conta%2==0)
								{
									printf ("%c", alfa[w-offset]);
								}
								else
								{
									printf ("%c", alfa[w+offset]);
								}
								conta++;
							}	
							}
							
						}
						printf ("\n\noffset usato per la criptazione: +/- %d", offset);
						
						break;
				}
				}
				else
				{
					printf ("Accesso Negato\n");
				}
		}
		else
		{
			printf ("Accesso Negato");
		}

    } else {
        printf("Accesso Negato\n");
    }
    
    
/*{
	int n1, x, y, z;
	int pw=giorno();
	scanf ("%d", &n1);
	x=n1*(pw);
	y=x/12;
	printf ("%d\n", y);
}*/

    return 0;
}
