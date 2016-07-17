//Include Guard
#ifndef CAR_H
#define CAR_H

//Dependencies
#include <vector>
#include <iostream>
using namespace std;
class Car
{
	
private:
	string nombre;
	int ano;
	vector<float> fuel_economy;
public:
	Car(std::string nombre, int ano);
	string get_nombre();
	int get_ano();
	float getcurrent_fuel_economy();
    float getany_fuel_economy(int n);
    int get_fuel_economy_size();
	float calculate_fuel_economy(float fuel_used, float kiloF,float kiloI);
    void add_fuel_economy(float fuel_economy);
    void set_name(string name);
    void set_year(int year);
    void set_fuel_economy(vector<float> fuel_economy);

};
#endif // __CAR_H_INCLUDED
	