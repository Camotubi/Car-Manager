#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Car.h"
#define MENU "a) Crear Nuevo Auto \nb) Mostrar Autos en Memoria\nc) Guardar Vehiculos en Memoria\nd) Cargar Autos a memoria\nf) Limpiar Pantalla"

using namespace std;
int main () {
	vector<Car> carros;
	string carro_nombre;
	int carro_ano;
	char menu_op;
	void printMenu();
	while(true)
	{
		printMenu();
		cin>>menu_op;
		switch(menu_op)
		{
			case 'a':
				cout<<"Ingrese nombre del Vehiculo"<<endl;
				cin>>carro_nombre;
				cout<<"Ingrese año del Vehiculo"<<endl;
				cin>>carro_ano;
				carros.push_back(Car(carro_nombre,carro_ano));
			break;
			
			case 'b':
				for(int i =0; i<carros.size();i++)
				{
					cout<<carros.at(i).getnombre()<<endl;
				}
			break;
			
			case 'c':
				{
					ofstream datos;
					datos.open("data.txt");
					for(int unsigned n=0; n<carros.size(); n++)
					{
						datos<<carros.at(n).getnombre()<<endl;
					}
					datos.close();
				}
				
			break;
			
			case 'd':
			{
				ifstream datos;
				datos.open("data.txt");
				while(getline(datos,carro_nombre))
				{
					carros.push_back(Car(carro_nombre,1));
				}
				datos.close();
			}
			
			break;
			
			case 'f':
				system("clear");
			break;
		}
		
	}
	
	
  return 0;
}


void printMenu(){
			cout<<MENU<<endl;
}