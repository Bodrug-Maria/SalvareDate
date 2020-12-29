#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 

void Cazul2()//fuel
{
    float a, a1, b, b1, c, d, d1, y;
    float dif, econom, dis;
    int lower = 740, upper = 930, count = 1; 
    int r, i, VectorData[7];
    char destinatii[30][40];
    int Distanta[10], PassageriCoboara[10], PassageriUrca[10];
    char Vector[7][100] = 
    {
        "Passageri",					            //(Input max 575)   	|\|=--1--=|/|
        "Greutatea Medie",			    	        //(82kg)		        |\|=--2--=|/|
        "Viteza maximă",			    	        //(random 740 - 930)	|\|=--3--=|/|
        "Capacitatea rezervorului",		            //(Max 240T)		    |\|=--4--=|/|
        "Greutatea avionului",			            //(random 35 - 45)	    |\|=--5--=|/|
        "Consumul de combustibil per. persoana",	//(3-4 L per 100Km)	    |\|=--6--=|/|
        "Consumul de combustibil per. Ton"		    //(40L per 1T)		    |\|=--7--=|/|
    };
    printf("Cheltuieli pentru combustibil.\n");
    for(i=0;i<=7;i++)   //Introducerea si verificarea datelor pentru problema
    {
        if(i == 1)
        {
            VectorData[i] = 82;
            printf("\n%s a pasagerilor este %dkg.", Vector[i], VectorData[i]);
        }
        if(i == 2)
        {
            for (r = 0; r < count; r++) 
            { 
                VectorData[i] = (rand() % (upper - lower + 1)) + lower;
            }
            printf("\n%s a avionului este %dKm/h.", Vector[i], VectorData[i]);
        }
        if(i == 4)
        {
            lower = 35, upper = 40, count = 1;
            VectorData[i] = (rand() % (upper - lower + 1)) + lower;
            printf("\n%s este de %dt.", Vector[i], VectorData[i]);
        }
        if( i == 5)
        {
            lower = 3, upper = 4, count = 1;
            VectorData[i] = (rand() % (upper - lower + 1)) + lower;
            printf("\n%s este de %d L per. 100Km.", Vector[i], VectorData[i]);
        }
        if(i == 6)
        {
            VectorData[i] = 40;
            printf("\n%s este de %d L.", Vector[i], VectorData[i]);
        }
        if(i == 0)
        {
            printf("\nIntrodu câţi pasageri sunt la bord. ");
            scanf("%d", &VectorData[i]);
            if(VectorData[i] > 575)
            {
                printf("\nValoarea maximala de pasageri este depasită. \n Prin urmare se vor face 2 zboruri, deocamdată vom lua în calcul 575 persoane.");
                VectorData[i] = 575;
            }
            if(VectorData[i] <= 0)
            {
                printf("\n Nu-i nimic dacă nu sunt pasageri,\n Avionul oricum trebuie să ajungă la următoarea destinaţie pentru pasagerii de acolo.");
            }
            else
            {
                printf("\nPe bord sunt %d %s", VectorData[i], Vector[i]);
            }
        }
        if(i == 3)
        {
            printf("\nIntrodu cantitatea de combustibil in tone. (240 Max) ");
            scanf("%d", &VectorData[i]);
            
            if(VectorData[i] > 240)
            {
                printf("Cantitatea de combustibil introdusă este mai mare decât capacitatea rezervorului de 240T.\n Prin urmare Valoarea se stabileşte la 20T.");
                VectorData[i] = 240;
            }
            if(VectorData[i] < 1)
            {
                printf("Cantitatea de combustibil introdusă este mai mică decât minimul necesar pentru decolare.\n Prin urmare Valoarea se stabileşte la 10T.");
                VectorData[i] = 10;
            }
            else
            {
                printf("\nÎn rezervor sunt %d tone.", VectorData[i]);
            }
        }
    }
    printf("\nIntrodu câte aeropoarte sunt de vizitat(maxim 4/minim 2): ");
    scanf("%d", &count);
    if(count > 4)
    {
        printf("\nVrei să introduci %d stații, vom lua în calcul doar 4.", count);
        count = 4; 
    }
    else if(count < 2)
    {
        printf("\nValoarea introdusă este prea mică, vom spune că 2 statii.");
    }
    for(i=0;i<count;i++) //introducem statiile
    {
        if(i == 0)
        {
            printf("\nIntrodu Aeroportul din care decolezi: ");
            scanf("%s", destinatii[i]);
        }
        else
        {
            printf("\nIntrodu următoarea stație: ");
            scanf("%s", destinatii[i]);
        }
    }
    printf("\nAcum trebuie să introducem distanța dintre destinații: ");
    for(i=0;i<count-1;i++)
    {
        printf("\nIntrodu distanța dintre %s și %s (în Km): ", destinatii[i], destinatii[i+1]);
        scanf("%d", &Distanta[i]);
    }
    for(i=0;i<count-1;i++)
    {
        printf("Introdu câți pasageri coboară la stația %s : ", destinatii[i+1]);
        scanf("%d", &PassageriCoboara[i]);
        printf("Introdu câți pasageri urcă la stația %s : ", destinatii[i+1]);
        scanf("%d", &PassageriUrca[i]);
    }
    
    for(i=0;i<count-1;i++)
    {
        a1 = VectorData[0]*4;
        a = a1 / 1000;
        b1 = 0.04;
        b = VectorData[4]*b1;
        c = Distanta[i]/100;
        d = a+b;
        d1 = d*c;
        
        if(VectorData[3] > d1)
        {
            dif=VectorData[3]-d1;
            econom = dif; 
            dis = d1;
            printf("\nCantitatea de combustibil economisită este egală cu %fT.\nCantitatea necesară pentru a ajunge la %s este %ft.\n", econom, destinatii[i+1], dis);
        }
        if(VectorData[3]<d1)
        {
            dif=d1-VectorData[3];
            dis=d1;
            if(d1 <= 240)
            {
                printf("\nCantitatea de combustibil necesară pentru a ajunge la %s este %ft. Adăugânduse %fT.\n", destinatii[i+1], dis, dif);   
            }
            else if(d1 > 240)
            {
                printf("\nDistanta până la %s este prea mare pentru avion.\n", destinatii[i+1]);
                break;
            }
        }
        if(VectorData[3] == d1)
        {
            printf("\nPentru zborul până la %s cantitatea de combustibil introdusă coincide cu cantitatea necesară.\n", destinatii[i+1]);    
        }
        
        if(VectorData[0] > 575)
        {
            VectorData[0] = 575;
            printf("\nPrea multi pasageri de la statia %s la %s. \n se vor transporta doar 575.\n", destinatii[i], destinatii[i+1]);
        }
        else if(VectorData[0] <= 0)
        {
            VectorData[0] = 0;
            printf("\nNu sunt pasageri. Zborul va continua fara.\n");
        }
        VectorData[0] = VectorData[0] - PassageriCoboara[i] + PassageriUrca[i];
    }
    printf("\n Introdu 1 pentru a repeta: ");
    scanf("%d", &i);
    if(i == 1)
    {
        Cazul2();
    }
}
int main()
{
    char name;
    int c;
    srand(time(0)); 
    printf("Introdu Numele: ");
    scanf("%s", &name);
    printf("În serviciile aeriene SIGURANȚA e pe primul loc!\nIntrodu 1 pentru a continua:");
    scanf("%d", &c);
    if(c == 1)
    {
        Cazul2();
    }
}
