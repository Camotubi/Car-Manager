#include "Car.h"
    Car::Car(string nombre, int ano)
	{
        set_name(nombre);
        set_year(ano);
        set_fuel_economy(fuel_economy);
	}
    string Car::get_nombre()
	{
		return nombre;
	}
	int Car::get_ano()
	{
		return ano;
	}
	float Car::getcurrent_fuel_economy()
	{
		return Car::fuel_economy.back();
	}
    float Car::getany_fuel_economy(int n)
    {
        return fuel_economy.at(n);
    }
    int Car::get_fuel_economy_size()
    {
        return fuel_economy.size();
    }
	float Car::calculate_fuel_economy(float fuel_used, float kiloF,float kiloI)
	{
        float fuel_econ = (fuel_used/(kiloF-kiloI));
        fuel_economy.push_back(fuel_econ);
		return fuel_econ;
	}
    void Car::add_fuel_economy(float fuel_economy)
    {
        this->fuel_economy.push_back(fuel_economy);
    }
    void Car::set_name(std::string name)
    {
        this->nombre = name;
    }
    void Car::set_year(int year)
    {
        this->ano = year;
    }
    void Car::set_fuel_economy(std::vector<float> fuel_economy)
    {
        this->fuel_economy=fuel_economy;
    }

