#include <iostream>

using namespace std;

class Car
{
	private:
		int gasolineGauge;
	public:
		int GetGasGauge()
		{
			return gasolineGauge;
		}
		Car(int gasoline) : gasolineGauge(gasoline) {}
		Car() : gasolineGauge(0) {}
};


class HybridCar : public Car{
	private:
		int electricGauge;
	public:
		int GetElecGauge()
		{
			return electricGauge;
		}
		HybridCar(int electric=0, int gasoline=0) : electricGauge(electric) , Car(gasoline){}
};

class HybridWaterCar : public HybridCar
{
	private:
		int waterGauge;
	public:
		void ShowCurrentGauge()
		{
			cout << "Remaining gasoline : " << GetGasGauge() << endl;
			cout << "Remaining electric : " << GetElecGauge() << endl;
			cout << "Remaining water : " << waterGauge << endl;
		}
		HybridWaterCar(int water=0, int electric=0, int gasoline=0) : waterGauge(water), HybridCar(electric, gasoline) {};
};

int main(void)
{
	HybridWaterCar car(10, 10, 10);
	car.ShowCurrentGauge();
	cout << "==========================" << endl;
	HybridWaterCar car2(20, 30, 40);
	car2.ShowCurrentGauge();
	return(0);
}