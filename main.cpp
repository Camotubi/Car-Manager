#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Car.h"
#include <string>
#define MENUPRINCIPAL "a) Crear Nuevo Auto \nb) Mostrar Autos en Memoria\nc) Guardar Vehiculos en Memoria\nd) Cargar Autos a memoria\nf) Limpiar Pantalla\ng) Seleccionar Vehiculo\nz) Cerrar Programa"
#define MENUVEHICULO "b) Mostrar informacion del Vehiculo \nd) Mostrar Fuel Economy Actual \ne) Calcular Fuel Economy \nf) Mostrar Historial de Fuel Economy del Vehiculo \nx) Limpiar Pantalla \nz) Regresar al Menu Principal"
using namespace std;
char menu_op;
char yes_no;

int main () {
	vector<Car> carros; 
	string carro_nombre;
    fstream myfiles;
	int carro_ano;
    int carro_id;
    int saveCars(vector<Car>,string);
    void loadCars(vector <Car>*, string);
    bool filexist(string);
	void printMenu(string);
    void showCarsInMemory(vector<Car>);
    void showCarInfo(Car);
    void menuVehicles(Car);
    string nom_archivo;
	while(true)
	{
		printMenu(MENUPRINCIPAL);
		cin>>menu_op;
		switch(menu_op)
		{
			case 'a':
                {   cout<<"Ingrese nombre del Vehiculo"<<endl;
                    cin>>carro_nombre;
                    cout<<"Ingrese año del Vehiculo"<<endl;
                    cin>>carro_ano;
                    carros.push_back(Car(carro_nombre,carro_ano));
                }
			break;
			
			case 'b':
                    showCarsInMemory(carros);
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
                                        break;//
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
				system("cls");
			break;
            
            case 'g':
            {
                int unsigned selectedCar;
                showCarsInMemory(carros);
                cout<<"Ingrese el numero del carro que desea seleccionar:";
                cin>>selectedCar;
                menuVehicles(carros.at(selectedCar));
            }
            break;
            case 'h':
            {

                
            }
            break;
            case 'z':
                return 0;
            break;
		}
		
	}
}


void printMenu(string menu)
{
    cout<<menu<<endl;
}

void showCarsInMemory(vector<Car> cars)
{
    if(cars.size()>0)
    {
        for(int unsigned i =0; i<cars.size();i++)
        {
            cout<<i<<". "<<cars.at(i).get_nombre()<<cars.at(i).get_ano()<<endl;
        }
    } else
    {
        cout<<"No hay vehiculos en memoria"<<endl;
    }
                
}
void showCarInfo(Car car)
{
    cout<<"Nombre: "<<car.get_nombre()<<endl;
    cout<<"Año: "<<car.get_ano()<<endl;
    cout<<"Fuel Economy: ";
    if(car.get_fuel_economy_size()>0)
    {
        cout<<car.getcurrent_fuel_economy()<<endl;
    } else
    {
        cout<< "Not Set"<<endl;
    }
}
int saveCars(vector<Car> cars, string filename)
{
    fstream myfiles;
    myfiles.open(filename.c_str(), fstream::out);
    for(int unsigned n=0; n<cars.size(); n++)
    {
        myfiles<<"Nombre:"<<cars.at(n).get_nombre()<<endl;
        myfiles<<"Ano:"<<cars.at(n).get_ano()<<endl;
        if(cars.at(n).get_fuel_economy_size()!=0)
        {
            myfiles<<"Fuel Economy:";
            for(int unsigned i = 0; i < cars.at(n).get_fuel_economy_size(); i++)
            {
                myfiles<<cars.at(n).getany_fuel_economy(i)<<",";
            }
            myfiles<<";";
        }
        myfiles<<"--#SPACE#--\n";
    }
    myfiles.close();
    return 0;
}

void loadCars(vector<Car> *cars, string filename)
{
    int current_car_year = 0;
    fstream myfiles;
    string current_car_name;
    string current_line;
    string fuel_econo_buffer;
    vector<float> current_car_fuel_economy;
    myfiles.open(filename.c_str(),fstream::in);
    while(getline(myfiles,current_line))
    {
       
        cout<<current_line<<endl;
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
        if(current_line.substr(0,13)=="Fuel Economy:")
        {
            for(int i = 13,b=13,e=0;i<current_line.size();i++)
            {
                if(current_line.at(i)==' ')
                {
                    i++;
                    b=i;
                }
                e++;
                if(current_line.at(i)==',' || current_line.at(i) == ';')
                {
                    e--;
                    cout<<current_line.substr(b,e)<<endl;
                    cout<<atof(current_line.substr(b,e).c_str())<<endl;
                    current_car_fuel_economy.push_back(atof(current_line.substr(b,e).c_str()));
                    e=0;
                    b=i+1;
                }
            }

        }
        if(current_line=="--#SPACE#--")
        {
            cars->push_back(Car(current_car_name,current_car_year));
            current_car_year = 0;//test
            cars->at(0).set_fuel_economy(current_car_fuel_economy);
        }

    }
    myfiles.close();
}

bool filexist(string filename)
{
    ifstream file(filename.c_str());
    
    return (bool)file;
}    
void menuVehicles(Car car)
{
    void showCarInfo(Car);
    void printMenu(string);
    showCarInfo(car);
    while(true)
    {
        printMenu(MENUVEHICULO);
        cin>>menu_op;
        switch(menu_op)
        {
            case 'a':
            break;
            case 'b':
                showCarInfo(car);
            break;
            case 'c':
            break;
            case 'd':
                cout<<car.getcurrent_fuel_economy()<<" litros/km"<<endl;
            break;
            case 'e':
            {
                int kiloI, kiloF,liters;
                cout<<"Ingrese kilometraje inicial"<<endl;
                cin>>kiloI;
                cout<<"Ingrese Kilometraje actual"<<endl;
                cin>>kiloF;
                cout<<"Ingrese Litros gastados"<<endl;
                cin>>liters;
                cout<<car.calculate_fuel_economy(liters,kiloF,kiloI)<<" litros/km"<<endl;
            }
            break;
            case 'f':
                for(int unsigned i=0; i<car.get_fuel_economy_size();i++)
                {
                    cout<<car.getany_fuel_economy(i)<< "liters/km"<<endl;
                }
            break;
            case 'x':
                system("cls");
                break;
            case 'z':
                return;
            break;
        }
    }
}