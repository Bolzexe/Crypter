#crypter

CRYPTER - v0.3

What's New?

- È possibile ri-eseguire il programma una volta arrivati al termine della criptazione/decriptazione, senza chiudere l'eseguibile.

- Ora, dopo essersi autenticati e aver ri-eseguito il programma, non verrà richiesta di nuovo l'autenticazione, ma si avrà direttamente il menù principale.

- Migliorata la grafica del menù e la "pulizia" dello schermo: una volta effettuato l'accesso, o dopo aver ri-eseguito il programma, si vedrà solo il menù principale, senza la parte di Login.

Linee di codice: 511


--VERSIONI PRECEDENTI--

CRYPTER - v0.2

What's new?

- Dalla precedente versione, sono state introdotte altre 2 opzioni nel menu principale,
la criptazione e la decriptazione con un custom offset.

Ora è quindi possibile scegliere un offset a piacimento, per poter tenere lunghe conversazioni per giorni o mesi senza cambiare l'offset di criptazione.

In caso di questa scelta, al codice criptato/decriptato mostrato come risultato, verrà affiancata la seguente dicitura: |x|, dove x rappresenta l'offset. Questa dicitura non va copiata per la criptazione/decriptazione, serve solo a ricordare l'offset utilizzato.



- Un'altra novità è la possibilità di poter inserire testi di lunghezza a piacimento in input/output.
NOTA: il testo dato in input DEVE essere dell'esatta lunghezza inserita nel campo precedente.

Linee di codice: 451






CRYPTER - v0.1


What's new?

il progetto CRYPTER consiste in un programma sviluppato in C, in grado di criptare/decriptare un testo di 10 caratteri dato in input.

ACCESSO AL PROGRAMMA
Per accedere al programma, è richiesta un'autenticazione a più passaggi

. Primo passaggio: inserire la data odierna, MA solamente la seconda cifra.
. Secondo passaggio: verrà generato un numero da 1 a 10, è necessario moltiplicare il numero *2, e inserire il risultato.
. Terzo passaggio: è ora necessario sottrarre la data odierna dal numero precedentemente ottenuto.

Dopo aver seguito i passaggi correttamente, si avrò l'accesso al programma.

CRIPTAZIONE/DECRIPTAZIONE

Scegliendo di criptare(1) un testo, è necessario essere sicuri che esso sia di 10 caratteri.
L'input dev'essere dato a cifre separate, ad esempio "provainput" diventerà p r o v a i n p u t;
Nel caso della decriptazione (2) non è necessario eseguire questa separazione, ma è comunque consigliato.

MOTORE DI CRIPTAZIONE
In base al suo valore, il numero corrente verrà sostituito con uno di posizione alterata in positivo/negativo di un determinato numero: l'offset.


OFFSET 
Può essere in positivo o in negativo, a seconda della posizione della lettera stessa, se pari o dispari.

Questo aumenta (credo) la sicurezza della criptazione.

L'offset attuale è settato a:

giorno compreso tra 1 e 5 -> offset: 1
giorno compreso tra 6 e 10 -> offset: 2
giorno compreso tra 11 e 15 -> offset: 3
giorno compreso tra 16 e 20 -> offset: 4
giorno compreso tra 21 e 25 -> offset: 5
giorno compreso tra 26 e 30 -> offset: 6
giorno pari a 31 -> offset: 7

Linee di codice: 219




-Christian Bolzan
