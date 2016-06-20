#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Car.h"
#include <string>
#define MENU "a) Crear Nuevo Auto \nb) Mostrar Autos en Memoria\nc) Guardar Vehiculos en Memoria\nd) Cargar Autos a memoria\nf) Limpiar Pantalla\ng) Cerrar Programa"

using namespace std;
int main () {
	vector<Car> carros;
	string carro_nombre;
    fstream myfiles;
	int carro_ano;
    int carro_id;
	char menu_op;
    char yes_no;
    
	void printMenu();
    string nom_archivo;
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
				carros.push_back(Car(carro_nombre,carro_ano,carro_id));
			break;
			
			case 'b':
				for(int unsigned i =0; i<carros.size();i++)
				{
					cout<<carros.at(i).get_nombre()<<endl;
				}
			break;
			
			case 'c':
				{
                cout<<"Ingrese el nombre del archivo"<<endl;
                cin>>nom_archivo;
					myfiles.open(nom_archivo.c_str(),fstream::out);
					for(int unsigned n=0; n<carros.size(); n++)
					{
						myfiles<<carros.at(n).get_nombre()<<endl;
					}
					myfiles.close();
				}
				
			break;
			
			case 'd':
			{
                if(carros.size()>0)
                {
                    cout<<"Hay autos en memoria." 
                    "\n¿Desea Guardar los Autos en otro lado antes de importar los nuevos?"
                    "\n(s/n)( Los autos en memoria seran reemplazados )\n";
                    cin>>yes_no;
                    if(yes_no == 's')
                    {
                        cout<<"Nombre del Archivo:";
                        cin>>nom_archivo;
                        myfiles.open(nom_archivo.c_str(), fstream::out);
                        for(int unsigned n=0; n<carros.size(); n++)
                        {
                            myfiles<<carros.at(n).get_id();
                            myfiles<<"{";
                            myfiles<<carros.at(n).get_nombre()<<";";
                            myfiles<<"Nombre:"<<carros.at(n).get_nombre()<<";";
                            myfiles<<"Año:"<<carros.at(n).get_ano()<<";";
                            myfiles<<"ID:"<<carros.at(n).get_id()<<";";
                            if(carros.at(n).get_fuel_economy_size()!=0)
                            {
                                myfiles<<"Fuel Economy:";
                                for(int unsigned i = 0; i < carros.at(n).get_fuel_economy_size() - 1; i++)
                                {
                                    myfiles<<carros.at(n).getany_fuel_economy(i)<<",";
                                }
                                myfiles<<carros.at(n).getcurrent_fuel_economy()<<";";
                            }
                            
                        }
                    myfiles.close();
                    }
                        
                }
            }
                cout<<"Ingrese el nombre del archivo"<<endl;
                cin>>nom_archivo;
				myfiles.open(nom_archivo.c_str(),fstream::in);
				while(getline(myfiles,carro_nombre))
				{
					carros.push_back(Car(carro_nombre,1,1));
				}
				myfiles.close();
			break;
			
			case 'f':
				system("clear");
			break;
            
            case 'g':
                return 0;
		}
		
	}
}


void printMenu()
{
    cout<<MENU<<endl;
}

bool saveCars()
{
    
    return true;
}