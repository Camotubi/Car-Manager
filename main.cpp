#include <iostream>
#include <fstream>
#include <vector>
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

};

int main () {
	vector<Carro> carros;
	string carro_nombre;
	int carro_ano;
	char menu_op;
	
	while(true)
	{
		cout<<"a) Crear Nuevo Auto \nb) Mostrar Autos en Memoria\nc) Guardar Vehiculos en Memoria"<<endl;
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
			
			case 'b':cout<<endl;
			break;
			
			case 'c':
				ofstream datos;
					datos.open("data.txt",ios::app);
					for(int unsigned n=0; n<carros.size(); n++)
					{
						datos<<carros.at(n).getnombre()<<endl;
						cout<<"Hola"<<carros.at(n).getnombre();
					}
					datos.close();
			break;
		}
		
	}
	
	
  return 0;
}