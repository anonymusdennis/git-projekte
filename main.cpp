#include <iostream>
#include "fstream"
#include "cnfg_reader.h"
#include "logging.hpp"
using namespace std;
class AutoTeil {
private : int id;
public:
    float cost = -999;
    string type;
    float weight;
    AutoTeil getAutoTeil()
    {
        return *this;
    }
};
class Karosserie : public AutoTeil
{

public :
    int Motor_ID;
    string color;
    Karosserie(string type = "Käfer",float weight = 251.2f,float cost = 321.98f, string color="red")
    {
        this->color = color;
        this->type = type;
        this->cost = cost;
        this->weight = weight;
    }
};
class Inrerioer : public AutoTeil
{

public :
    int Motor_ID;
    string fabric_type;
    string color;
    Inrerioer(string type = "Bus",float weight = 150.9f,float cost = 400.98f, string fabric_type = "paper", string color="ehkelhhhaftes beige")
    {
        this -> fabric_type = fabric_type;
        this -> color = color;
        this->type = type;
        this->cost = cost;
        this->weight = weight;
    }
};
class Electronic : public AutoTeil
{

public :
    int Motor_ID;

    Electronic(string type = "Bus",float weight = 150.9f,float cost = 600.98f)
    {
        this->type = type;
        this->cost = cost;
        this->weight = weight;
    }
};
class Motor : public AutoTeil
{

public :
    int Motor_ID;

    Motor(string type = "Karl",float weight = 100.0f,float cost = 1321.98f)
    {
        this->type = type;
        this->cost = cost;
        this->weight = weight;
    }
};
class Auto
{

public:
    AutoTeil parts[10];
    float cost;
    float weight;
    string Name;
    Motor moron;
    Electronic shit;
    Inrerioer bling_bling;
    Karosserie bonk;
    Auto(string Name, Motor moron, Electronic shit, Inrerioer bling_bling, Karosserie bonk) :
            moron(moron),shit(shit), bling_bling(bling_bling), bonk(bonk),Name(Name)
    { // <--- Element Initialisierer
        parts[0] = moron.getAutoTeil();
        parts[1] = shit.getAutoTeil();
        parts[2] = bling_bling.getAutoTeil();
        parts[3] = bonk.getAutoTeil();
    }
    float calc_Cost()
    {
        float costing = 0;
        for(const AutoTeil& part : this-> parts)
        {
            if(part.cost > 0)
                costing += part.cost;
        }
        this -> cost = costing;
        return this -> cost;
    }

    float calc_Weight()
    {
        float weighing = 0;
        for(const AutoTeil& part : this-> parts)
        {
            if(part.weight > 0 && part.weight < 9999999)
                weighing += part.weight;
            printf(part.weight);

        }
        this -> weight = weighing;
        return this -> weight;
    };

};
int main() {

    output.open("../main.log",ios::out|ios::trunc);
    printf(rsc("../car_specs","Motor.Kosten","Euro"));
    Auto test = Auto(rsc("../car_specs","Name",""),
                     Motor(
                             rsc("../car_specs","Motor.Modell",""),
                             rfc("../car_specs","Motor.Gewicht","kg"),
                             rfc("../car_specs","Motor.Preis","Euro")),
                        Electronic(
                                rsc("../car_specs","Electronics.Modell",""),
                                rfc("../car_specs","Electronics.Gewicht","kg"),
                                rfc("../car_specs","Electronics.Kosten","Euro")
                                ),
                    Inrerioer(
                            rsc("../car_specs","Interior.Modell",""),
                            rfc("../car_specs","Interior.Gewicht","kg"),
                            rfc("../car_specs","Interior.Preis","Euro"),
                            rsc("../car_specs","Interior.Stoff",""),
                            rsc("../car_specs","Interior.Farbe","")
                    ),
                        Karosserie(
                            rsc("../car_specs","Karosserie.Modell",""),
                            rfc("../car_specs","Karosserie.Gewicht","kg"),
                        rfc("../car_specs","Karosserie.Preis","Euro"),
                            rsc("../car_specs","Karosserie.Farbe","")
                            ));

    printf("Cost:", test.calc_Cost());
    printf("Weight:",test.calc_Weight());
    printf("Color Outside:",test.bonk.color);
    printf("Color Inside:",test.bling_bling.color);
    ofstream output;
    ifstream input;
    bool first = true;
    int i;
    //wenn dokument existiert addiere +1 und prüfe ob existiert.... wtf mache ich falsch
    for (i = -1; !!input || first;)
    {
        i++;
        printf("../" + test.Name + "_" + to_string(i));
        first = false;
        //offene inputs schliessen
        input.close();
        //nextes dokument öffnen wieso auch immer dann es nicht kapiert dass es offen ist...
        if(i == 0)
            input.open("../" + test.Name,ios::in);
        else
        input.open("../" + test.Name + "_" + to_string(i),ios::in);

    }
    printf(i);
    input.close();
    if(i == 0)
        output.open("../" + test.Name,ios::out | ios::app);
    else
        output.open("../" + test.Name + "_" + to_string(i),ios::out | ios::app);
    output << "Name : " << test.Name << "\n";
    output << "Motor : \n";
    output << "            Modell : " << test.moron.Motor_ID << "\n";
    output << "            Gewicht : " << test.moron.weight << " kg\n";
    output << "            Preis : " << test.moron.cost << " Euro\n";
    output << "Electronics : \n";
    output << "            Modell : " << test.shit.type << "\n";
    output << "            Gewicht : " << test.shit.weight << " kg\n";
    output << "            Kosten : " << test.shit.cost << " Euro\n";
    output << "Interior : \n";
    output << "            Modell : " << test.bling_bling.type << "\n";
    output << "            Gewicht : " << test.bling_bling.weight << " kg\n";
    output << "            Preis : " << test.bling_bling.cost << " Euro\n";
    output << "            Stoff : " << test.bling_bling.fabric_type << "\n";
    output << "            Farbe : " << test.bling_bling.color << "\n";
    output << "Karosserie : \n";
    output << "            Modell : " << test.bonk.type << "\n";
    output << "            Gewicht : " << test.bonk.weight << " kg\n";
    output << "            Preis : " << test.bonk.cost << " Euro\n";
    output << "            Farbe : " << test.bonk.color << "\n";

    output << "Insgesamt : \n";
    output << "            Kosten : " << test.calc_Cost() << "\n";
    output << "            Gewicht : "<< test.calc_Weight() << "\n";
    output.close();
    printf("Test",1101,'l');
    print("lol");
    print_raw("lol",120.000);



    output.close();
    return 0;
}
