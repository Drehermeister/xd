#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct Teszt
{
	string azonosito;
	string valasz;
	int pont;
};
int Osszpont(Teszt* Tomb , int db);
int main()
{
	// Adatbevitel 
	ifstream be("valaszok.txt");
	if (be.fail()) { cout << "Hiba a fájl beolvasásakor !";system("pause");exit(1); }
	int i = 0, j;
	Teszt tmb[500];
	string megoldas;
	be >> megoldas;   // Elsõ lépésben olvassuk be a megoldást
	
	while (be >> tmb[i].azonosito>> tmb[i].valasz)
	{
		int pontsz = 0;
						// számítsuk ki az egyes versenyzõk pontszámait!
		for (int j = 0; j < 14; j++)
		{
			if (tmb[i].valasz[j] == megoldas[j])  // ha jól válaszolt a versenyzõ
			{
				pontsz++;
			}
		}
		tmb[i].pont = pontsz;
		i++;
	}
	be.close();

	// 2.	Írja ki a képernyõre, hogy hány versenyzõ vett részt a versenyen! 
	int versenyzokszama = i;
	cout << "A versenyen "<< versenyzokszama <<" versenyzo vett reszt"<<endl;

	//3.Írja ki a legtöbb pontot elért versenyzõ azonosítóját és pontszámát!
	int max = 0;
	for (i = 1; i < versenyzokszama; i++)
	{
		if (tmb[i].pont > tmb[max].pont)
		{
			max = i;
		}
	}
	cout<<"A legtobb pontot elert versenyzo azonositoja :"<< tmb[max].azonosito<<" pontszama: "<<tmb[max].pont<<endl;

	//4.Írja ki, hogy volt-e volt e maximális pontszámot elért versenyzõ!
	bool volt_e = false;
	for (int i = 0; i < versenyzokszama; i++)
	{
		if (tmb[i].pont == 14)				// ha találunk 14 pontost nem kell tovább menni - break
		{
			volt_e=true;					// ha találunk 14 pontost a volt_e változót állítsuk igazra
			break;
		}
	}
	if (volt_e==true) cout<<"Volt maximalis pont"<<endl;
	else cout<<"Nem volt maximalis pont"<<endl;

	//5.Számolja meg hány versenyzõ nem tudott legalább a kérdések felére válaszolni!
	int hetalatt = 0;
	for (i = 0; i < versenyzokszama; i++)
	{
		if (tmb[i].pont < 7) hetalatt++;
	}
	cout<<hetalatt<<" versenyzo nem tudott legalabb a kerdesek felere valaszolni"<<endl;

	//Az összes versenyzõ összes pontja
	cout << "A versenyzok altal elert osszes pont: " << Osszpont(tmb, versenyzokszama);
	return 0;
}

int Osszpont(Teszt* Tomb, int db)
{
	int ossz = 0;
	for (int i = 0; i < db; i++)
	{
		ossz = ossz + Tomb[i].pont;
	}return ossz;
}
