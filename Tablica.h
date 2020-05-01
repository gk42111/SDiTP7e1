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
		/*tutaj musimy dokonaæ realokacji pamiêci na rzecz naszej tablicy
		dynamicznej.
		Tak naprawdê w C++ wykorzytujemy do tego w praktyce w³aœnie gotowy
		szablon z STL - vector.
		Tutaj chcemy zbudowaæ nasz w³asny wektor, wiêc wykorzystamy
		nastêpuj¹c¹, prost¹ do zrozumienia konstrukcjê:
		1: utworzymy now¹ tablicê o rozmiarze o 1 wiêkszym ni¿ poprzedni*/
		TYP *newbuf = new TYP[Size + 1];
		/*2: kopiujemy zawartoœæ naszej tablicy (wskazywanej przez Tab) do
		nowo utworzonej (newbuf)*/
		copy_n(Tab, Size, newbuf);
		/*3: kasujemy Tab*/
		delete[] Tab;
		/*4: nasze pole Tab wskazuje to, co newbuf*/
		Tab = newbuf;
		/*na koniec naszej tablicy dodajemy element*/
		Tab[Size] = Element;
		/*zwiêkszamy rozmiar tablicy*/
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
	//to jest przeci¹¿enie operatora indeksacji. Teraz po obiekcie tej klasy
//	mo¿emy "poruszaæ siê" u¿ywaj¹c operatora[]
	TYP& operator[](unsigned N)
	{
		return Tab[N];
	}
};