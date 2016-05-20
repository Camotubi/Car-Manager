#ifndef __CAR_H_INCLUDED__
#define __CAR_H_INCLUDED__
using namespace std;
class Car
{
	private:
	string nombre;
	int ano;
	vector<float> fuel_economy;
public:
	Car(string nombre, int ano)
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
#endif
	