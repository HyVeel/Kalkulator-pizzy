#include <iostream>

using namespace std;

const double PI = 3.1415926536;
int iloscPizz;

class Pizza
{
public:
	double srednica;
	double cenaSzt;
	double pole;
	double cenaCm2;

	Pizza()
	{
		srednica = 0;
		cenaSzt = 0;
		pole = 0;
		cenaCm2 = 0;
	}

	Pizza uzupelnijDane()
	{
		Pizza temp;
		temp.srednica = wczytajSrednice();
		temp.cenaSzt = wczytajCeneSzt();
		temp.pole = obliczPole(temp.srednica);
		temp.cenaCm2 = obliczCeneCm2(temp.cenaSzt, temp.pole) * 100; //*100 - bo w gr

		return temp;
	}

private:
	double wczytajSrednice()
	{
		cout << "Podaj srednice pizzy [cm]: "; cin >> srednica;
		if(srednica <= 0)
		{
			cout << "\a[!] Srednica musi byc dodatnia"; cout << "\n";
			wczytajSrednice();
		}

		return srednica;
	}

	double wczytajCeneSzt()
	{
		cout << "Podaj cene pizzy [z\210]: "; cin >> cenaSzt;
		if(cenaSzt < 0)
		{
			cout << "\a[!] Cena nie moze byc ujemna"; cout << "\n";
			wczytajCeneSzt();
		}

		return cenaSzt;
	}

	double obliczPole(double d)
	{
		double r = d / 2;
		pole = PI * r * r;

		return pole;
	}

	double obliczCeneCm2(double cena, double p)
	{
		cenaCm2 = cena / p;

		return cenaCm2;
	}
};

int wczytajIlosc()
{
	cout << "Podaj ilosc pizz do porownania: "; cin >> iloscPizz;
	if(iloscPizz <= 0)
	{
		cout << "\a[!] Liczba pizz musi byc dodatnia"; cout << "\n";
		wczytajIlosc();
	}

	return iloscPizz;
}

void wyswietlDane(Pizza pizza)
{
	cout << "\nSrednica:\t" << pizza.srednica << " cm\n";
	cout << "Cena za szt:\t" << pizza.cenaSzt << " zl\n";
	cout << "Pole calkowite:\t" << pizza.pole << " cm^2\n";
	cout << "Cena za cm^2:\t" << pizza.cenaCm2 << " gr\n\n";
}

int znajdzMin(double cena[])
{
	double najmniejsza = cena[0];
	int numer = 0;

	for(int i = 1; i < iloscPizz; i++)
	{
		if(cena[i] < najmniejsza)
		{
			najmniejsza = cena[i];
			numer = i;
		}
	}

	return numer;
}

int main()
{
	wczytajIlosc();
	system("cls");

	Pizza *pizza = new Pizza[iloscPizz];
	double *ceny = new double[iloscPizz];

	for(int i = 0; i < iloscPizz; i++)
	{
		cout << "----------[ Pizza " << i + 1 << " ]----------\n\n";

		pizza[i] = pizza[i].uzupelnijDane();
		wyswietlDane(pizza[i]);
		ceny[i] = pizza[i].cenaCm2;
	}

	int indeks = znajdzMin(ceny);

	cout << "------[ Najlepszy wybor ]------\n\n";

	cout << "Pizza " << indeks + 1 << " (" << pizza[indeks].cenaCm2 << " gr za cm^2)";
	getchar(); getchar();

	delete [] pizza;

	return 0;
}