#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


typedef struct Pacient{
	char ime[100];
	short zdrastveno;
	int pregledi;
}pacient;

typedef struct MaticenDoktor {
	char ime[100];
	pacient niza[200];
	int br_pac;
	float cena;
}doktor;


float suma_doktor(doktor md){
	int suma = 0;
	for (int i = 0; i < md.br_pac; i++){
		if (md.niza[i].zdrastveno == 0)
			suma += md.niza[i].pregledi;
	}
	return suma*md.cena;
}

int pregledi_doktor(doktor md){

	int suma = 0;
	for (int i = 0; i < md.br_pac; i++){
		suma += md.niza[i].pregledi;
	}
	return suma;
}

void najuspesen_doktor(doktor *md, int n)
{

	float max_suma = 0.00;
	int max_ind = 0;
	for (int i = 0; i < n; i++)
	{
		float suma = suma_doktor(md[i]);
		//printf("%.2f\n", priv);
        if (suma == max_suma){
			int broj = pregledi_doktor(md[i]);
			int broj_max = pregledi_doktor(md[max_ind]);
            //printf("%d %d\n", broj, broj_max);
			if (broj > broj_max){
				max_suma = suma;
				max_ind = i;
			}
		}
        if (suma > max_suma){
			max_suma = suma;
			max_ind = i;
		}
	}
	printf("%s %.2f %d\n", md[max_ind].ime, max_suma, pregledi_doktor(md[max_ind]));
}

int main()
{
    int i, j, n, broj;

	cin >> n;
	doktor md[n];
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);



	return 0;
}
