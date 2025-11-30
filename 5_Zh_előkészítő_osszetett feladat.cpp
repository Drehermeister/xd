/*Feladat :
Egy vegyesbolt adatait kell tárolni. Tároljuk az áruk neveit (string),  árát, 
és a raktáron lévõ darabszámot!
Hozzunk létre egy az elõbbiek tárolására szolgáló struktúra típusú változót!
Maximum 15 db különféle árúnk lehet (15 elemû a struktúra tömb)!     
1. Kérjük  be az árúk számát ellenõrzötten!
2. Kérjük be az áruk neveit! (pl. fekete ribizli szörp)
3. Kérjük be az áruk árát ellenõrzötten(nem lehet 5000 Ft nál nagyobb és 100 Ft- nál kisebb!)    
4. Kérjük be az árúk darabszámát véletlengenerátorral (az árúk száma 1 és 10 db között lehet)   
5. Írja ki az adatokat táblázatosan!   
6. Határozza meg, és írja ki, mennyi az egész árukészlet értéke!
7. Számolja ki az átlagos árat és írja ki a képernyõre !
8. Számolja meg hány áruból van több mint öt raktárkészleten!
9. Írja ki a legdrágább áru nevét és árát!
10. Emelje az árakat 20 %-kal majd írja ki az áruk nevét és új árát! 
*/
#include <iostream>
#include<iomanip>
#include<string>
#include<ctime>
using namespace std;

struct Aru
{
	string arunev;
	int ar;
	int db;
};
int main()
{
	Aru bolt[15];
	int i, legdragabb, ertek = 0, atlagar = 0, aruszam;
	srand((unsigned)time(NULL));
	// adatbekérés - különbözõ áruk darabszámának bekérése ellenõrzötten
	do 
	{
		cout << "Adja meg hanyfele aru van a boltban ! (1-15)" << endl;
		cin >> aruszam;
		cin.ignore();
		if (aruszam < 1 || aruszam>15) cout << "Hibas adat, az aruk szama 1-15 lehet!" << endl;
	} while (aruszam < 1 || aruszam>15);
	
	// adatbekérés - különbözõ áruk neve, darabszáma és ára
	for (i = 0; i <aruszam; i++)
	{
		cout << "Adja meg az " << i + 1 << " . aru nevet\n";
		getline(cin, bolt[i].arunev);	//  aru nevének bekérése
		do
		{
			cout << "Adja meg az aru arat ( 100-5000Ft)\n";	// ár ellenõrzött bekérése 100FT és 5000 között!
			cin >> bolt[i].ar;
			cin.ignore();
			if (bolt[i].ar < 100 || bolt[i].ar>5000) cout << "Hibas adat, az aruk ara 100-1850 FT lehet!" << endl;
		} while (bolt[i].ar < 100 || bolt[i].ar>5000);	
		bolt[i].db = rand() % 10 + 1;// darabszám bekérése véletlen generátorral 1-10
	}
	// 5. feladat eredmenyek kiiratasa "tablazatosan"
	system("cls");			// képernyõ törlés
	cout.setf(ios::left);	// balra igazított kiírás

	for (i = 0; i <aruszam; i++) // adatok táblázatosan
	{
	cout<<setw(20)<<bolt[i].arunev<<setw(6)<<bolt[i].ar<<"Ft"<<"\t"<<bolt[i].db<<" db" <<endl;
	}
	
	// 6. feladat adatok feldolgozása - egész árukészlet értéke

	for (i = 0; i < aruszam; i++)
	{
		ertek = ertek+ bolt[i].ar * bolt[i].db;
	}
	cout << "Az arukeszlet ossz ereteke: " << ertek << endl;

	// 7. feladat adatok feldolgozása - átlagár 
	for (i = 0; i < aruszam; i++)
	{
		atlagar = atlagar + bolt[i].ar;
	}
	cout << "Az aruk atlagara :" << atlagar / aruszam << endl; //(nincs szükség a törtrészre)
	
	// 8. feladat adatok feldolgozása - hány áruból van több mint öt raktárkészleten!
	
	int otneltobb = 0;
	for (i = 0; i < aruszam; i++)
	{
		if( bolt[i].db>5)
		{
			otneltobb++;
		}
	}
	cout << otneltobb << " arubol van otnel tobb a keszleten " << endl;
	
	//9. feladat adatok feldolgozása - Írja ki a legdrágább áru nevét és árát!
	legdragabb = 0;										// legyen a 0. áru a legdrágább
	for (i = 1; i < aruszam; i++)
	{
		if (bolt[i].ar > bolt[legdragabb].ar) legdragabb = i;   // jegyezzük meg a lagdragab														aru sorszamat
	}
	cout<<"A legdragabb aru adatai: \n"<<setw(20)<<bolt[legdragabb].arunev << bolt[legdragabb].ar << "\t" << bolt[legdragabb].db << endl;
	
	//10. feladat Emelje az árakat 20 %-kal majd írja ki az áruk nevét és új árát! 
	
	cout << "Az aruk adatai 20%-os emeles utan :" << endl;
	for (i = 0; i < aruszam; i++)
	{
		bolt[i].ar = bolt[i].ar*1.2;    // 20%-os emelés
		cout << setw(20) << bolt[i].arunev << setw(6) << bolt[i].ar << "Ft" << "\t" << bolt[i].db << " db" << endl;
	}
	return 0;
}
