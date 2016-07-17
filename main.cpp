#include <iostream>


#include <vector>

#include "Car.h"
#include "Files.h"
#include "DisplayInfo.h"
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

	void printMenu(string);

    
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