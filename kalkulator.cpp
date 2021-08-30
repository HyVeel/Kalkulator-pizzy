#include <iostream>
#include <conio.h> //_getch()

using namespace std;

const double PI = 3.1415926536;
int iloscPizz;

class Pizza
{
public:
	char ksztalt;
	double srednica;
	double bokA, bokB;
	double cenaSzt;
	double pole;
	double cenaCm2;

	Pizza()
	{
		ksztalt = '0';
		srednica = 0;
		bokA = 0;
		bokB = 0;
		cenaSzt = 0;
		pole = 0;
		cenaCm2 = 0;
	}

	Pizza uzupelnijDane()
	{
		Pizza temp;
		temp.ksztalt = wczytajKsztalt();
		if(temp.ksztalt == '1') //kolo
		{
			temp.srednica = wczytajSrednice();
			temp.pole = obliczPole(temp.srednica);
		}
		else //prostokat
		{
			temp.bokA = wczytajBokA();
			temp.bokB = wczytajBokB();
			temp.pole = obliczPole(temp.bokA, temp.bokB);
		}

		temp.cenaSzt = wczytajCeneSzt();
		temp.cenaCm2 = obliczCeneCm2(temp.cenaSzt, temp.pole) * 100; //*100 - bo w gr

		return temp;
	}

private:
	int wczytajKsztalt()
	{
		cout << "Wybierz kszta\210t pizzy\n";
		cout << "[1] Okr\245g\210a\n";
		cout << "[2] Prostok\245tna\n\n";

		do
		{
			ksztalt = _getch();
		}while(ksztalt != '1' && ksztalt != '2');

		if(ksztalt == '1') cout << "> Okr\245g\210a\n\n";
		else cout << "> Prostok\245tna\n\n";

		return (int)ksztalt;
	}

	double wczytajSrednice()
	{
		cout << "Podaj \230rednic\251 pizzy [cm]: "; cin >> srednica;
		if(srednica <= 0)
		{
			cout << "\a[!] \227rednica musi by\206 dodatnia"; cout << "\n";
			wczytajSrednice();
		}

		return srednica;
	}

	double wczytajBokA()
	{
		cout << "Podaj d\210ugo\230\206 1 boku pizzy [cm]: "; cin >> bokA;
		if(bokA <= 0)
		{
			cout << "\a[!] D\210ugo\230\206 boku musi by\206 dodatnia"; cout << "\n";
			wczytajSrednice();
		}

		return bokA;
	}

	double wczytajBokB()
	{
		cout << "Podaj d\210ugo\230\206 2 boku pizzy [cm]: "; cin >> bokB;
		if(bokB <= 0)
		{
			cout << "\a[!] D\210ugo\230\206 boku musi by\206 dodatnia"; cout << "\n";
			wczytajSrednice();
		}

		return bokB;
	}

	double wczytajCeneSzt()
	{
		cout << "Podaj cen\251 pizzy [z\210]: "; cin >> cenaSzt;
		if(cenaSzt < 0)
		{
			cout << "\a[!] Cena nie mo\276e by\206 ujemna"; cout << "\n";
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

	double obliczPole(double a, double b)
	{
		pole = a * b;

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
	cout << "Podaj ilo\230\206 pizz do por\242wnania: "; cin >> iloscPizz;
	if(iloscPizz <= 0)
	{
		cout << "\a[!] Liczba pizz musi by\206 dodatnia"; cout << "\n";
		wczytajIlosc();
	}

	return iloscPizz;
}

void wyswietlDane(Pizza pizza)
{
	cout << "\nPole ca\210kowite:\t" << pizza.pole << " cm^2\n";
	cout << "Cena za cm^2:\t" << pizza.cenaCm2 << " gr\n\n\n";
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

	cout << "------[ Najlepszy wyb\242r ]------\n\n";

	cout << "Pizza " << indeks + 1 << " (" << pizza[indeks].cenaCm2 << " gr za cm^2)";
	getchar(); getchar();

	delete[] pizza;

	return 0;
}
