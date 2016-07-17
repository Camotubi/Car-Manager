#include "Files.h"



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

