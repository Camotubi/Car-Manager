#include "DisplayInfo.h"

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