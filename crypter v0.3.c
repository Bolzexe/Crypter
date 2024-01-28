#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CRYPT 1
#define DECRYPT 2
#define OFFCRYPT 3
#define OFFDECRYPT 4


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
	
	int chiusura=3, valido=1;
	
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
    int offset;
    
    					if (today<6)
						{
							offset=1;
						} else if (today>=6 && today<11)
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
							
						} else if (today==30 || today==31)
						{
							offset=7;
						}


	while (chiusura!=1)
	{
printf ("********************************************\n");
printf ("\t\tCRYPTER v0.3\n");
printf ("********************************************\n\n");

    
if (chiusura==2 && valido==1)
{
    if (today>0 && today<9) {
        pw=today;
    } else if (today>9 && today<19) {
        pw=today-10;
    } else if (today>19 && today<29) {
        pw=today-20;
    } else if(today==30) {
        pw=0;
    } else if(today==31) {
        pw=1;
    }	
}
else
{
	printf ("Inserire password attuale: ");
	scanf("%d", &pw); 
}
    if (pw==sl) {		//sol: numero_di_verifica*2, numero_di_verifica-giorno_corrente
        int cod=rand()%10+1;
        int x, y, cont=0;
        if (chiusura==2 && valido==1)
        {
        	x=(cod*2);
		}
		else
		{
		printf ("\nVerificare codice %d: ", cod);        
        scanf ("%d", &x);
		}
        if (x==(cod*2))
        {
        	printf ("\nverificare codice (passo 2): ");
        	if (chiusura==2 && valido==1)
        	{
        		y=(cod*2)-today;
			}
			else
			{
			scanf ("%d", &y);	
			}
        		printf ("\n");
				if (y==(cod*2)-today)
				{
				printf ("Accesso Consentito\n\n");
				int scelta, key, q, q2, w, conta=0, lungh;
				
				system ("cls");
				valido=1;					
				printf ("----------------------------------------------\n");
				printf ("|\tMENU' PRINCIPALE\t\t     |\n");
				printf ("|\t\t\t\t\t     |\n");

				printf ("| CRIPTAZIONE\t1\t(offset predefinito) |\n");
				printf ("| --\t\t\t\t\t     |\n");
				printf ("| DECRIPTAZIONE\t2\t(offset predefinito) |\n");
				printf ("| --\t\t\t\t\t     |\n");
				printf ("| CRIPTAZIONE\t3\t(custom offset)\t     |\n");
				printf ("| --\t\t\t\t\t     |\n");
				printf ("| DECRIPTAZIONE\t4\t(custom offset)\t     |\n");
				printf ("----------------------------------------------\n");
				//printf ("CRIPTAZIONE\t1\t(offset predefinito)\n--\nDECRIPTAZIONE\t2\t(offset predefinito)\n--\nCRIPTAZIONE\t3\t(offset libero)\n--\nDECRIPTAZIONE\t4\t(offset libero)\n\n");
				/*printf ("Premere 1 per criptare\nPremere 2 per decriptare\n\n");*/
				

    scanf ("%d", &scelta);
				switch (scelta)
				{
					case CRYPT:
						printf ("\n\nSi vuole criptare un testo di 10 cifre (1) o di una lunghezza custom (2)?");
						int sceltalunghezza;
						do
						{
							scanf ("%d", &sceltalunghezza);
						} while (sceltalunghezza<1 || sceltalunghezza>2);
						
						
					if (sceltalunghezza==1)
					{
						printf ("\nInserire il testo da criptare (10 caratteri); ogni lettera separata da uno spazio\n\n");
						char car[10];

						for (q=0; q<10; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice criptato: ");
						
						for (q=0; q<10; q++)	//modificato
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
						printf ("\n\nOffset usato per la criptazione: +/- %d", offset);
					}
					else
					{
						printf ("\nInserire lunghezza testo precisa: ");
						int lungh;
						scanf ("%d", &lungh);
						
					printf ("\nInserire il testo da criptare; ogni lettera separata da uno spazio\n\n");
						char car[lungh];

						for (q=0; q<lungh; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice criptato: ");
						
						for (q=0; q<lungh; q++)	//modificato
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
						printf ("\n\nOffset usato per la criptazione: +/- %d", offset);
						
					}
						
						break;
						
					case DECRYPT:
						
						printf ("\n\nSi vuole decriptare un testo di 10 cifre (1) o di una lunghezza custom (2)? ");
						do
						{
							scanf ("%d", &sceltalunghezza);
						} while (sceltalunghezza<1 || sceltalunghezza>2);
						
					if (sceltalunghezza==1)
					{
							char car[10];
						printf ("\nInserire il testo da decriptare (10 caratteri); ogni lettera separata da uno spazio\n\n");
						
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
					}
					else
					{
						printf ("\nInserire lunghezza testo precisa: ");
						scanf ("%d", &lungh);
						
						char car[lungh];
						printf ("\nInserire il testo da decriptare; ogni lettera separata da uno spazio\n\n");
						
						for (q=0; q<lungh; q++)
						{
							scanf (" %c", &car[q]);
						}

						
						printf ("\ncodice decriptato: ");
						for (q=0; q<lungh; q++)
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
					}
						
						break;
						
					case OFFCRYPT:
						
						printf ("Inserire il custom offset: ");
						scanf ("%d", &offset);
						printf ("\n\nSi vuole criptare un testo di 10 cifre (1) o di una lunghezza custom (2)?");
						sceltalunghezza;
						do
						{
							scanf ("%d", &sceltalunghezza);
						} while (sceltalunghezza<1 || sceltalunghezza>2);
						
						
					if (sceltalunghezza==1)
					{
						printf ("\nInserire il testo da criptare (10 caratteri); ogni lettera separata da uno spazio\n\n");
						char car[10];

						for (q=0; q<10; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice criptato: ");
						
						for (q=0; q<10; q++)	//modificato
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
						printf ("|%d|", offset);
						printf ("\n\nOffset usato per la criptazione: +/- %d", offset);
					}
					else
					{
						printf ("Inserire lunghezza testo precisa: ");
						int lungh;
						scanf ("%d", &lungh);
						
					printf ("Inserire il testo da criptare; ogni lettera separata da uno spazio\n\n");
						char car[lungh];

						for (q=0; q<lungh; q++)
						{
							scanf (" %c", &car[q]);
						}
						
						printf ("\ncodice criptato: ");
						
						for (q=0; q<lungh; q++)	//modificato
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
						}printf ("|%d|", offset);
						printf ("\n\nOffset usato per la criptazione: +/- %d", offset);
						
					}
						
						break;
						
					case OFFDECRYPT:
						
						printf ("Inserire il custom offset: ");
						scanf ("%d", &offset);
					
					printf ("\n\nSi vuole decriptare un testo di 10 cifre (1) o di una lunghezza custom (2)?");
						do
						{
							scanf ("%d", &sceltalunghezza);
						} while (sceltalunghezza<1 || sceltalunghezza>2);
						
					if (sceltalunghezza==1)
					{
							char car[10];
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
						}printf ("|%d|", offset);
						printf ("\n\noffset usato per la criptazione: +/- %d", offset);
					}
					else
					{
						printf ("Inserire lunghezza testo precisa: ");
						scanf ("%d", &lungh);
						
						char car[lungh];
						printf ("Inserire il testo da decriptare; ogni lettera separata da uno spazio\n\n");
						
						for (q=0; q<lungh; q++)
						{
							scanf (" %c", &car[q]);
						}

						
						printf ("\ncodice decriptato: ");
						for (q=0; q<lungh; q++)
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
						} printf ("|%d|", offset);
						printf ("\n\noffset usato per la criptazione: +/- %d", offset);
					}
						
						break; 
				}
				}
				else
				{
					printf ("Accesso Negato\n");
					valido=0;
				}
		}
		else
		{
			printf ("Accesso Negato");
			valido=0;
		}

    } else 
	{
        printf("Accesso Negato\n");
        valido=0;
    }
    
    printf ("\nPremere 1 per uscire dal programma, premere 2 per ri-eseguire il programma");
    do
    {
    	scanf ("%d", &chiusura);	
	} while (chiusura<1||chiusura>2);
	system ("cls");
 }
    return 0;
}