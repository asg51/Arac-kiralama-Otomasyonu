#include "pch.h"
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <sstream>

using namespace std;

int musterisayisi, aracsayisi, parcalamasayisi;
string *parcalamadizisi;
bool bgiris;
class class1 {
public:
	void ekle(string veri, string adres, bool guncelle);
	void liste(string veri);
	void ara();
}clas1;
class class2 {
public:
	void sil();
	void guncelle();
}clas2;
class kullanici_sifre {
protected:
	string kullanici, sifre;
};
class anaclass :class1, class2, kullanici_sifre {
public:
	void secim();
	void liste_guncelle();
	void arac_kiralama();
	void giris();
	void arac_teslim_alma();
	void yeni_arac_ekleme();
	void arac_kayiti_silme();
	void araclarin_durumu();
	void gelir_durumu();
	void set_kullanici(string *adres);
	void set_sifre(string *adres);
	string get_kullanici();
	string get_sifre();
	anaclass() {
		kullanici = "asg";
		sifre = "51";
	}
	~anaclass() {
		cout<<"Yikici Calistirildi, Cikis Yapildi";
	}
}ana;
static struct musteribilgileri
{
	string ad;
	string soyad;
	string marka;
	string model;
	int adet;
	string fiyat;
	string zaman;
}*musteri;
static struct aracbilgileri
{
	string marka;
	string model;
	string yil;
	int adet;
}*arac;
struct diziii
{
	string dizi;
}*dizi;
void yazdir(string deger, bool durum) {
	for (int i = 0; i < deger.length(); i++)
	{
		cout << deger[i];
		Sleep(50);

	}if (durum)
	{
		cout << endl;
	}
}
void yazdir(int durum) {
	system("cls");
	ana.liste_guncelle();
	if (dizi[0].dizi == "arac")
	{
		for (int i = 1; i < durum; i++)
		{
			yazdir(to_string(i) + " " + arac[stoi(dizi[i].dizi)].marka + " " + arac[stoi(dizi[i].dizi)].model + " " + arac[stoi(dizi[i].dizi)].yil + " " + to_string(arac[stoi(dizi[i].dizi)].adet), true);
		}
	}
	else if (dizi[0].dizi == "musteri")
	{
		for (int i = 1; i < durum; i++)
		{
			yazdir(to_string(i) + " " + musteri[stoi(dizi[i].dizi)].ad + " " + musteri[stoi(dizi[i].dizi)].soyad + " " + musteri[stoi(dizi[i].dizi)].marka + " " + musteri[stoi(dizi[i].dizi)].model + " " + musteri[stoi(dizi[i].dizi)].fiyat + " " + musteri[stoi(dizi[i].dizi)].zaman, true);
		}
	}
}
string sdonusturme(char *deger) {
	string degerr;
	for (int i = 0; i < strlen(deger); i++)
	{
		degerr += deger[i];
	}
	return degerr;
}
int parcalama(string deger) {
	int sayac = 0;
	for (int i = 0; i < deger.length(); i++)
	{
		if (deger[i] == '$')
		{
			sayac++;
		}
	}
	parcalamasayisi = sayac;
	dizi = new diziii[sayac];
	int sayac2 = 0;
	string sonuc;
	for (int i = 0; i < deger.length(); i++)
	{
		if (!(deger[i] == '$'))
		{
			sonuc += deger[i];
		}
		else
		{
			dizi[sayac2].dizi = sonuc;
			sonuc = "";
			sayac2++;
		}
	}
	return sayac;
}
void class1::ekle(string veri, string adres, bool guncelle) {
	if (guncelle == false)
	{
		fstream dosya_kayitet(adres, ios::out);
		dosya_kayitet << veri;
		dosya_kayitet.close();
	}
	if (guncelle == true)
	{
		fstream dosya_kayitet(adres, ios::app);
		dosya_kayitet << veri;
		dosya_kayitet.close();
	}
}
void anaclass::liste_guncelle() {

	fstream fdosyaoku, adosyaoku;
	system("cls");
	adosyaoku.open("aracbilgileri.txt", ios::in);
	int sayac = 0, sayac2 = 0, forsayac = 0, whilesayac = 0, kontrol;
	string oku, sdeger = "";
	while (!adosyaoku.eof()) {
		getline(adosyaoku, oku);
		sayac++;
	}
	adosyaoku.close();
	sayac -= 1;
	arac = new aracbilgileri[sayac];
	aracsayisi = sayac;
	fdosyaoku.open("aracbilgileri.txt", ios::in);
	kontrol = 0;
	while (!fdosyaoku.eof())
	{
		getline(fdosyaoku, oku);
		if (!(kontrol == sayac)) {
			for (int i = 0; i < oku.length(); i++)
			{
				if (!(oku[i] == '$'))
					sdeger += oku[i];
				else
				{
					forsayac++;
					switch (forsayac)
					{
					case 1: {
						arac[whilesayac].marka = sdeger;
						sdeger = "";
						break; }
					case 2: {
						arac[whilesayac].model = sdeger;
						sdeger = "";
						break; }
					case 3: {
						arac[whilesayac].yil = sdeger;
						sdeger = "";
						break; }
					case 4: {
						char *cdeger = new char[sdeger.length()];
						for (int i = 0; i < sdeger.length(); i++)
						{
							cdeger[i] = sdeger[i];
						}
						arac[whilesayac].adet = atoi(cdeger);
						sdeger = "";
						break; }
					default: {
						break;
					}
					}
				}
			}
			whilesayac++;
			forsayac = 0;
		}
		kontrol++;
	}
	fdosyaoku.close();
	whilesayac = 0;
	forsayac = 0;
	fstream fdosyaoku2, adosyaoku2;
	adosyaoku2.open("musteribilgileri.txt", ios::in);
	while (!adosyaoku2.eof()) {
		getline(adosyaoku2, oku);
		sayac2++;
	}
	adosyaoku2.close();
	sayac2 -= 1;
	musteri = new musteribilgileri[sayac2];
	musterisayisi = sayac2;
	fdosyaoku2.open("musteribilgileri.txt", ios::in);
	kontrol = 0;
	while (!fdosyaoku2.eof())
	{
		getline(fdosyaoku2, oku);
		if (!(kontrol == sayac2))
		{
			for (int i = 0; i < oku.length(); i++)
			{
				if (!(oku[i] == '$'))
					sdeger += oku[i];
				else
				{
					forsayac++;
					switch (forsayac)
					{
					case 1: {
						musteri[whilesayac].ad = sdeger;
						sdeger = "";
						break;
					}
					case 2: {
						musteri[whilesayac].soyad = sdeger;
						sdeger = "";
						break;
					}
					case 3: {
						musteri[whilesayac].marka = sdeger;
						sdeger = "";
						break;
					}
					case 4: {
						musteri[whilesayac].model = sdeger;
						sdeger = "";
						break;
					}
					case 5: {
						char *cdeger = new char[sdeger.length()];
						for (int i = 0; i < sdeger.length(); i++)
						{
							cdeger[i] = sdeger[i];
						}
						musteri[whilesayac].adet = atoi(cdeger);
						sdeger = "";
						break;
					}
					case 6: {
						musteri[whilesayac].fiyat = sdeger;
						sdeger = "";
						break;
					}
					case 7: {
						musteri[whilesayac].zaman = sdeger;
						sdeger = "";
						break;
					}
					default: {
						break;
					}
					}
				}
			}
			whilesayac++;
			forsayac = 0;
		}
		kontrol++;
	}
}
void class1::ara() {
	string gelen_veri, arama;
	string toplama = "";
	system("cls");
	yazdir("Hangi bilgilere gore arama yapacaksiniz?", true);
	yazdir("1. Arac bilgileri", true);
	yazdir("2. Musteri bilgileri", true);
	char sonuc;
	cin >> sonuc;
	if (sonuc == '2')
	{
		toplama = "musteri$";
		system("cls");
		yazdir("1. Ad", true);
		yazdir("2. Soyad", true);
		yazdir("3. Marka", true);
		yazdir("4. Model", true);
		cin >> sonuc;
		system("cls");
		ana.liste_guncelle();
		yazdir("Ne ariyacaksiniz?", true);
		cin >> arama;
		if (sonuc == '1')
		{
			for (int i = 0; i < musterisayisi; i++)
			{
				if (musteri[i].ad == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
		if (sonuc == '2')
		{
			for (int i = 0; i < musterisayisi; i++)
			{
				if (musteri[i].soyad == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
		if (sonuc == '3')
		{
			for (int i = 0; i < musterisayisi; i++)
			{
				if (musteri[i].marka == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
		if (sonuc == '4')
		{
			for (int i = 0; i < musterisayisi; i++)
			{
				if (musteri[i].model == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
	}
	else if (sonuc == '1')
	{
		toplama = "arac$";
		system("cls");
		yazdir("1. Marka", true);
		yazdir("2. Model", true);
		cin >> sonuc;
		system("cls");
		yazdir("Ne ariyacaksiniz?", true);
		cin >> arama;
		ana.liste_guncelle();
		if (sonuc == '1')
		{
			for (int i = 0; i < aracsayisi; i++)
			{
				if (arac[i].marka == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
		if (sonuc == '2')
		{
			for (int i = 0; i < aracsayisi; i++)
			{
				if (arac[i].model == arama)
				{
					toplama += to_string(i) + "$";
				}
			}
		}
	}
	int sayi = parcalama(toplama);
	yazdir(sayi);
	yazdir("Bulundu...", true);
	yazdir("1.Ana Menu", true);
	yazdir("2. Cikis", true);
	cin >> sonuc;
	system("cls");
	if (sonuc == '1')
	{
		ana.secim();
	}
	if (sonuc == '2')
	{
		bgiris = false;
		exit(0);
	}
}
void class2::sil() {
	system("cls");
	yazdir("Hangisini silmek istersiniz?", true);
	yazdir("1. Arac bilgilerinden", true);
	yazdir("2. Musteri bilgilerinden", true);
	char degisken[50];
	cin >> degisken;
	system("cls");
	string sdegisken = "";
	for (int i = 0; i < strlen(degisken); i++)
	{
		sdegisken += degisken[i];
	}
	clas1.liste(sdegisken);
	int silll;
	cin >> silll;
	if (sdegisken == "1")
	{
		arac[silll - 1].marka = "###";
	}
	if (sdegisken == "2")
	{
		musteri[silll - 1].marka = "###";
	}
	guncelle();
	ana.liste_guncelle();
}
void class2::guncelle() {

	bool gncle = false;
	for (int i = 0; i < aracsayisi; i++)
	{
		if (!(arac[i].marka == "###"))
		{
			clas1.ekle(arac[i].marka + "$" + arac[i].model + "$" + arac[i].yil + "$" + to_string(arac[i].adet) + "$" + "\n", "aracbilgileri.txt", gncle);
		}
		if ((arac[i].marka == "###")&&i==0)
		{
			clas1.ekle("", "aracbilgileri.txt", gncle);
		}
		gncle = true;
	}
	gncle = false;
	for (int i = 0; i < musterisayisi; i++)
	{
		if (!(musteri[i].marka == "###"))
		{
			clas1.ekle(musteri[i].ad + "$" + musteri[i].soyad + "$" + musteri[i].marka + "$" + musteri[i].model + "$" + to_string(musteri[i].adet) + "$" + musteri[i].fiyat + "$" + musteri[i].zaman + "$" + "\n", "musteribilgileri.txt", gncle);
		}
		if ((musteri[i].marka == "###")&&i==0)
		{
			clas1.ekle("", "musteribilgileri.txt", gncle);
		}
		gncle = true;
	}
}
void class1::liste(string veri) {
	ana.liste_guncelle();
	if (veri == "1")
	{
		for (int i = 0; i < aracsayisi; i++)
		{
			yazdir(to_string(i + 1) + " " + arac[i].marka + " " + arac[i].model + " " + arac[i].yil + " " + to_string(arac[i].adet), true);
		}
	}
	if (veri == "2")
	{
		for (int i = 0; i < musterisayisi; i++)
		{
			yazdir(to_string(i + 1) + " " + musteri[i].ad + " " + musteri[i].soyad + " " + musteri[i].marka + " " + musteri[i].model + " " + musteri[i].fiyat + " " + musteri[i].zaman, true);
		}
	}
}
void anaclass::arac_kiralama() {
	yazdir("Hangi Araci Kiralamak Istiyorsunuz", true);
	ana.liste("1");
	int deger;
	cin >> deger;
	system("cls");
	if (arac[deger - 1].adet == 0)
	{
		yazdir("Elimizde " + arac[deger - 1].marka + " " + arac[deger - 1].model + " arac kalmamistir başka araç tercih ediniz!!!", true);
		system("cls");
		arac_kiralama();
	}
	else
	{
		string isim, soyad, fiyat, zaman;
		yazdir("Isminiz", true);
		cin >> isim;
		yazdir("Soyad", true);
		cin >> soyad;
		yazdir(arac[deger - 1].marka + " " + arac[deger - 1].model + " aractan kac tane kiraliyacaksiniz", true);
		int kiralik_arac_sayisi;
		cin >> kiralik_arac_sayisi;
		yazdir("Fiyat", true);
		cin >> fiyat;
		yazdir("Zaman", true);
		cin >> zaman;
		string veri = isim + "$" + soyad + "$" + arac[deger - 1].marka + "$" + arac[deger - 1].model + "$" + to_string(kiralik_arac_sayisi) + "$" + fiyat + "$" + zaman + "$\n";
		yazdir(veri, true);
		ana.ekle(veri, "musteribilgileri.txt", true);
		liste_guncelle();
		arac[deger - 1].adet -= kiralik_arac_sayisi;
		guncelle();
		liste_guncelle();
		yazdir("Arac kiralanmistir...", true);
		system("cls");
		secim();
	}
}
void anaclass::arac_teslim_alma() {
	yazdir("Hangi Araci Teslim Alacaksiniz?", true);
	liste_guncelle();
	liste("2");
	int secim;
	cin >> secim;
	if (musteri[secim - 1].adet > 1)
	{
		system("cls");
		yazdir(musteri[secim - 1].marka + " " + musteri[secim - 1].model + " aracdan " + to_string(musteri[secim - 1].adet) + "adet var kac tanesini teslim almak istiyorsunuz?", true);
		int arac_sayisi;
		cin >> arac_sayisi;
		if (musteri[secim - 1].adet == aracsayisi)
		{
			for (int i = 0; i < aracsayisi; i++)
			{
				if (arac[i].marka == musteri[secim - 1].marka&&arac[i].model == musteri[secim - 1].model)
				{
					arac[i].adet += arac_sayisi;
					break;
				}
			}
			musteri[secim - 1].marka = "###";
		}
		else
		{
			for (int i = 0; i < aracsayisi; i++)
			{
				if (arac[i].marka == musteri[secim - 1].marka&&arac[i].model == musteri[secim - 1].model)
				{
					arac[i].adet += arac_sayisi;
					musteri[secim - 1].adet -= arac_sayisi;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < aracsayisi; i++)
		{
			if (arac[i].marka == musteri[secim - 1].marka&&arac[i].model == musteri[secim - 1].model)
			{
				arac[i].adet += musteri[secim - 1].adet;
				break;
			}
		}
		musteri[secim - 1].marka = "###";
	}
	guncelle();
	liste_guncelle();
	yazdir("Basarili bi sekilde teslim alinmistir", true);
	ana.secim();
}
void anaclass::yeni_arac_ekleme() {
	char marka[50], model[50], yil[15];
	int adet;
	yazdir("Eklemek istediginiz aracin bilgilerini giriniz", true);
	yazdir("Markasi:", false);
	cin >> marka;
	yazdir("\nModeli:", false);
	cin >> model;
	yazdir("\nYil:", false);
	cin >> yil;
	yazdir("\nAdet:", false);
	cin >> adet;
	system("cls");
	liste_guncelle();
	guncelle();
	bool bsonuc = true;
	string amarka, amodel, ayil;
	for (int i = 0; i < strlen(model); i++)
	{
		amodel += model[i];
	}
	for (int i = 0; i < strlen(marka); i++)
	{
		amarka += marka[i];
	}
	for (int i = 0; i < strlen(yil); i++)
	{
		ayil += yil[i];
	}
	for (int i = 0; i < aracsayisi; i++)
	{
		if (arac[i].marka == amarka && arac[i].model == amodel && arac[i].yil == ayil)
		{
			arac[i].adet += adet;
			bsonuc = false;
			break;
		}
	}
	if (bsonuc)
	{
		ekle(amarka + "$" + amodel + "$" + ayil + "$" + to_string(adet) + "$\n", "aracbilgileri.txt", true);
	}
	yazdir("Basarili bir sekilde eklenmistir", true);
	system("cls");
	secim();
}
void anaclass::arac_kayiti_silme() {
	system("cls");
	yazdir("Hangi Aracin Kayiti Silmek Istiyorsunuz?", true);
	liste_guncelle();
	liste("1");
	int secim;
	cin >> secim;
	system("cls");
	if (arac[secim - 1].adet == 1)
	{
		arac[secim - 1].marka == "###";
	}
	else if (arac[secim - 1].adet == 0)
	{
		yazdir("Hata arac suan kirada teslim aldiktan sonra kayitini silebirsiniz!!!", true);
		ana.secim();
	}
	else if (arac[secim - 1].adet > 1)
	{
		system("cls");
		yazdir(arac[secim - 1].marka + " " + arac[secim - 1].model + " " + to_string(arac[secim - 1].adet) + "adet bulunmaktadir kac tanesini sileceksiniz?", true);
		int Ksileme;
		cin >> Ksileme;
		if (arac[secim - 1].adet == Ksileme) {
			arac[secim - 1].marka = "###";
		}
		else
		{
			arac[secim - 1].adet -= Ksileme;
		}
	}
	guncelle();
	liste_guncelle();
	system("cls");
	ana.secim();
}
void anaclass::araclarin_durumu() {
	system("cls");
	liste("2");
	yazdir("1.Ana menu", true);
	yazdir("2.Cikis", true);
	int secim;
	cin >> secim;
	if (secim == 1)
	{
		ana.secim();
	}
	else if (secim == 2)
	{
		bgiris = false;
		exit(0);
	}
	else
	{
		araclarin_durumu();
	}
	system("cls");
}
void anaclass::gelir_durumu() {
	liste_guncelle();
	liste("2");
	int toplam_gelir = 0;
	for (int i = 0; i < musterisayisi; i++)
	{
		char *cdeger = new char[musteri[i].fiyat.length()];
		for (int j = 0; j < musteri[i].fiyat.length(); j++)
		{
			cdeger[j] = musteri[i].fiyat[j];
		}
		toplam_gelir += atoi(cdeger);
	}
	yazdir("Toplam Gelir:" + to_string(toplam_gelir), true);
	system("cls");
	ana.secim();
}
string anaclass::get_kullanici() {
	return kullanici;
}
string anaclass::get_sifre() {
	return sifre;
}
void anaclass::set_kullanici(string *adres) {
	kullanici = *adres;
}
void anaclass::set_sifre(string *adres) {
	sifre = *adres;
}
void kullanici_sifre_degistirme() {
	char kullaniciadi[50], sifre[50];
	string kullanici, parola;
	yazdir("Degistirmek istediginiz bilgileri giriniz", true);
	yazdir("Kullanici adi:", false);
	cin >> kullaniciadi;
	yazdir("\nSifre:", false);
	cin >> sifre;
	for (int i = 0; i < strlen(kullaniciadi); i++)
	{
		kullanici += kullaniciadi[i];
	}
	for (int i = 0; i < strlen(sifre); i++)
	{
		parola += sifre[i];
	}
	ana.set_kullanici(&kullanici);
	ana.set_sifre(&parola);
	yazdir("\nBasarili bir sekilde guncellenmistir", true);
	system("cls");
	ana.secim();
}
void anaclass::secim() {
	if (bgiris)
	{
		system("cls");
		yazdir("Ne yapmak istiyorsunuz?", true);
		yazdir("1.Arac kiralama", true);
		yazdir("2.Arac teslim alma", true);
		yazdir("3.Yeni arac ekleme", true);
		yazdir("4.Arac kayiti silme", true);
		yazdir("5.Kiralik araclarin durumunu ogrenme", true);
		yazdir("6.Sirketin gelir durumu", true);
		yazdir("7.Ara", true);
		yazdir("8.Kullanici adi parola degistirme", true);
		yazdir("9.Cikis", true);
		int secim;
		cin >> secim;
		switch (secim)
		{
		case 1:
		{
			arac_kiralama();
			break;
		}
		case 2:
		{
			arac_teslim_alma();
			break;
		}
		case 3: {
			yeni_arac_ekleme();
			break;
		}
		case 4: {
			arac_kayiti_silme();
			break;
		}
		case 5: {
			araclarin_durumu();
			break;
		}
		case 6: {
			gelir_durumu();
			break;
		}
		case 7: {
			ara();
			break;
		}
		case 8: {
			kullanici_sifre_degistirme();
			break;
		}
		case 9: {
			bgiris = false;
			exit(0);
		}
		default:
			break;
		}

	}
	else
	{
		giris();
	}
}
void anaclass::giris() {
	char kullaniciadi[50], sifre[50];
	string kullanici = "", parola = "";
	yazdir("Kullanici Adi:", true);
	cin >> kullaniciadi;
	yazdir("Sifre", true);
	cin >> sifre;
	for (int i = 0; i < strlen(kullaniciadi); i++)
	{
		kullanici += kullaniciadi[i];
	}
	for (int i = 0; i < strlen(sifre); i++)
	{
		parola += sifre[i];
	}
	if (get_kullanici() == kullanici && get_sifre() == parola)
	{
		bgiris = true;
		secim();
	}
	else
	{
		bgiris = false;
		yazdir("Hatali giris yeniden deneyiniz!!!", true);
		giris();
	}
}
int main()
{
	ana.secim();
	return 0;
}
