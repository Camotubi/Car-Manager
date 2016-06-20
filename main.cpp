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
    int saveCars(vector<Car>,string);
    void loadCars(vector <Car>*, string);
    bool filexist(string);
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
					cout<<carros.at(i).get_nombre()<<carros.at(i).get_ano()<<carros.at(i).get_id()<<endl;
				}
			break;
			
			case 'c':
				{
                    cout<<"Ingrese el nombre del archivo"<<endl;
                    cin>>nom_archivo;
                    if(!filexist(nom_archivo))
                    {
                        saveCars(carros,nom_archivo);
                    }
                    else
                    {
                        cout<<"El Archivo "<<nom_archivo<<" ya existe, ¿Desea sobrescribirlo?(s/n)";
                        cin>>yes_no;
                        if(yes_no == 's')
                        {
                            saveCars(carros,nom_archivo);
                        }
                    }
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
                        int loop = 1;
                        do
                        {
                            if(loop==1)
                            {
                            loop++;
                            cout<<"Nombre del Archivo:";
                            cin>>nom_archivo;
                            }
                            else
                            {
                                cout<<"El archivo "<<nom_archivo<<" ya existe, ¿Desea sobrescribirlo?(s/n/c)"<<endl;
                                cin>>yes_no;
                                switch(yes_no)
                                {
                                    case 's':
                                        saveCars(carros,nom_archivo);
                                        break;
                                    case 'n':
                                        cout<<"Nombre del Archivo:";
                                        cin>>nom_archivo;
                                        break;
                                    case 'c':
                                        loop = 0;
                                        break;
                                }
                            }

                        }while(filexist(nom_archivo) && loop!=0);
                    }
                        
                }
            }
            carros.clear();
            cout<<"Ingrese el nombre del archivo"<<endl;
            cin>>nom_archivo;
            loadCars(&carros,nom_archivo);
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

int saveCars(vector<Car> cars, string filename)
{
    fstream myfiles;
    myfiles.open(filename.c_str(), fstream::out);
    for(int unsigned n=0; n<cars.size(); n++)
    {
        myfiles<<"ID:"<<cars.at(n).get_id()<<endl;
        myfiles<<"Nombre:"<<cars.at(n).get_nombre()<<endl;
        myfiles<<"Año:"<<cars.at(n).get_ano()<<endl;
        if(cars.at(n).get_fuel_economy_size()!=0)
        {
            myfiles<<"Fuel Economy:";
            for(int unsigned i = 0; i < cars.at(n).get_fuel_economy_size() - 1; i++)
            {
                myfiles<<cars.at(n).getany_fuel_economy(i)<<",";
            }
            myfiles<<cars.at(n).getcurrent_fuel_economy()<<";";
        }
        myfiles<<"--#SPACE#--\n";
    }
    myfiles.close();
    return 0;
}

void loadCars(vector<Car> *cars, string filename)
{
    int current_car_id = 0;
    int current_car_year = 0;
    string current_line;
    fstream myfiles;
    string current_car_name;
    myfiles.open(filename.c_str(),fstream::in);
    while(getline(myfiles,current_line))
    {
        cout<<current_line<<endl;
        if(current_line.substr(0,3) == "ID:")
        {
            current_car_id=atoi(current_line.substr(3).c_str());
            cout<<current_car_id<<endl;
        }
        if(current_line.substr(0,7) == "Nombre:")
        {
            current_car_name=current_line.substr(7);
            cout<<current_car_name<<endl;
        }
        if(current_line.substr(0,4) == "Ano:")
        {
            current_car_year= atoi(current_line.substr(4).c_str());
            cout<<current_car_year<<endl;
        }
        if(current_line=="--#SPACE#--")
        {
            cout<<"hola"<<endl;
            cars->push_back(Car(current_car_name,current_car_year,current_car_id));
            current_car_id = 0;
            current_car_year = 0;
        }

    }
    myfiles.close();
}

bool filexist(string filename)
{
    ifstream file(filename.c_str());
    
    return (bool)file;
}    