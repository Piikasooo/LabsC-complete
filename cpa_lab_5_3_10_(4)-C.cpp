#include <iostream>
#include <sstream>

using namespace std;

class FarmAnimal
{
    public:
        FarmAnimal(double water_consumption);
        double getWaterConsumption();
    private:
        double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption)
{
    this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption()
{
    return water_consumption;
}

class ConsumptionAccumulator
{
    public:
        ConsumptionAccumulator();
        double getTotalConsumption();
        void addConsumption(FarmAnimal animal);
    private:
        double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :  total_consumption(0){}

double ConsumptionAccumulator::getTotalConsumption()
{
    return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
    total_consumption += animal.getWaterConsumption();
}

class Cow : public FarmAnimal
{
    public:
        Cow(int weight);
    private:
        int weight;
};

Cow::Cow(int weight) : FarmAnimal(8.6 * (weight / 100))
{
    this->weight = weight;
}

class Sheep : public FarmAnimal
{
    public:
        Sheep(int weight);
    private:
        int weight;
};

Sheep::Sheep(int weight) : FarmAnimal(1.1 * (weight / 10))
{
    this->weight = weight;
}

class Horse : public FarmAnimal
{
    public:
        Horse(int weight);
    private:
        int weight;
};

Horse::Horse(int weight) : FarmAnimal(6.8 * (weight / 100))
{
    this->weight = weight;
}

int main()
{
    ConsumptionAccumulator accumulator;
    string str, animalType;
    int animalWeight;
    getline(cin, str);
    istringstream iss;

    while(!str.empty())
    {
        iss.str(str);

        iss >> animalType >> animalWeight;
        if(animalType == "cow")
            accumulator.addConsumption(Cow(animalWeight));
        else if(animalType == "sheep")
            accumulator.addConsumption(Sheep(animalWeight));
        else if(animalType == "horse")
            accumulator.addConsumption(Horse(animalWeight));

        iss.clear();
        getline(cin, str);
    }

    cout << accumulator.getTotalConsumption();
    return 0;
}
