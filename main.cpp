#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
class	Carro
{
private:
	string nombre;
	int ano;
	vector<float> fuel_economy;
public:
	Carro(string nombre, int ano)
	{
		this->nombre = nombre;
		this->ano = ano;
	}
	string getnombre()
	{
		return nombre;
	}
	int getano()
	{
		return ano;
	}
	float getcurrent_fuel_economy()
	{
		return fuel_economy.back();
	}
	float calculate_fuel_economy(float fuel_final, float fuel_inicial,float distance)
	{
		return (fuel_final-fuel_inicial)/distance;
	}

};

int main () {
	vector<Carro> carros;
	string carro_nombre;
	int carro_ano;
	char menu_op;
	void menu();
	while(true)
	{
		menu();
		cin>>menu_op;
		switch(menu_op)
		{
			case 'a':
				cout<<"Ingrese nombre del Vehiculo"<<endl;
				cin>>carro_nombre;
				cout<<"Ingrese año del Vehiculo"<<endl;
				cin>>carro_ano;
				carros.push_back(Carro(carro_nombre,carro_ano));
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
					carros.push_back(Carro(carro_nombre,1));
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


void menu(){
			cout<<"a) Crear Nuevo Auto \nb) Mostrar Autos en Memoria\nc) Guardar Vehiculos en Memoria\nd) Cargar Autos a memoria\nf) Limpiar Pantalla"<<endl;
}