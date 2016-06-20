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
	int ano,id;
	vector<float> fuel_economy;
public:
	Car(string nombre, int ano, int id)
	{
		this->nombre = nombre;
		this->ano = ano;
        this->id = id;
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
    int get_id()
    {
        return id;
    }
	float calculate_fuel_economy(float fuel_final, float fuel_inicial,float distance)
	{
		return (fuel_final-fuel_inicial)/distance;
	}


};
#endif // __CAR_H_INCLUDED
	