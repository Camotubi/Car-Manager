//Include Guard
#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__
using namespace std;
//Dependencies
#include <vector>
class Car
{
	
private:
	string nombre;
	int ano;
	vector<float> fuel_economy;
public:
	Car(string nombre, int ano)
	{
        set_name(nombre);
        set_year(ano);
        set_fuel_economy(fuel_economy);
	}
	string get_nombre()
	{
		return nombre;
	}
	int get_ano()
	{
		return ano;
	}
	float getcurrent_fuel_economy()
	{
		return fuel_economy.back();
	}
    float getany_fuel_economy(int n)
    {
        return fuel_economy.at(n);
    }
    int get_fuel_economy_size()
    {
        return fuel_economy.size();
    }
	float calculate_fuel_economy(float fuel_used, float kiloF,float kiloI)
	{
        float fuel_econ = (fuel_used/(kiloF-kiloI));
        fuel_economy.push_back(fuel_econ);
		return fuel_econ;
	}
    void add_fuel_economy(float fuel_economy)
    {
        this->fuel_economy.push_back(fuel_economy);
    }
    void set_name(string name)
    {
        this->nombre = name;
    }
    void set_year(int year)
    {
        this->ano = year;
    }
    void set_fuel_economy(vector<float> fuel_economy)
    {
        this->fuel_economy=fuel_economy;
    }

};
#endif // __CAR_H_INCLUDED
	