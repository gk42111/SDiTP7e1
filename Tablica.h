#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template<typename TYP> class Tablica
{
private:
	TYP* Tab;
	unsigned Size;
public:
	Tablica()
	{
		this->Size = 0;
	}
	void PushBack(TYP Element)
	{
		/*tutaj musimy dokona� realokacji pami�ci na rzecz naszej tablicy
		dynamicznej.
		Tak naprawd� w C++ wykorzytujemy do tego w praktyce w�a�nie gotowy
		szablon z STL - vector.
		Tutaj chcemy zbudowa� nasz w�asny wektor, wi�c wykorzystamy
		nast�puj�c�, prost� do zrozumienia konstrukcj�:
		1: utworzymy now� tablic� o rozmiarze o 1 wi�kszym ni� poprzedni*/
		TYP *newbuf = new TYP[Size + 1];
		/*2: kopiujemy zawarto�� naszej tablicy (wskazywanej przez Tab) do
		nowo utworzonej (newbuf)*/
		copy_n(Tab, Size, newbuf);
		/*3: kasujemy Tab*/
		delete[] Tab;
		/*4: nasze pole Tab wskazuje to, co newbuf*/
		Tab = newbuf;
		/*na koniec naszej tablicy dodajemy element*/
		Tab[Size] = Element;
		/*zwi�kszamy rozmiar tablicy*/
		Size++;
	}
	TYP Get(unsigned N)
	{
		return Tab[N];
	}
	TYP Front()
	{
		return Tab[0];
	}
	TYP Back()
	{
		return Tab[Size-1];
	}
	void Reverse() {
		TYP *newbuf1 = new TYP[Size];
		copy_n(Tab, Size, newbuf1);
		int counter = Size - 1;
		for(int i = 0; i < Size; i++) {
			Tab[i] = newbuf1[counter];
			counter--;
		
		}
		
	}
	void Print()
	{
		for (int i = 0; i < Size; i++) cout << Tab[i]<<endl;
	}
	int Count() {
		return Size;
	}
	void PopBack() {
		Tab[Size - 1] = 0;
	}

	~Tablica()
	{
		delete[] Tab;
	}
	//to jest przeci��enie operatora indeksacji. Teraz po obiekcie tej klasy
//	mo�emy "porusza� si�" u�ywaj�c operatora[]
	TYP& operator[](unsigned N)
	{
		return Tab[N];
	}
};