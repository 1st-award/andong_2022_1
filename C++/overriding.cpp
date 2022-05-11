#include <iostream>

using namespace std;

class TransPort {
protected:
    int width, height, max_speed, tire;
public:
    TransPort() {
        cout <<"TransPort Instruct" << endl;
    }
    ~TransPort() {
        cout << "TransPort Destruct" << endl;
    }
    virtual void Pr(){
        cout << "TransPort" << endl;
    };
};

class Bike : public TransPort {
public:
    Bike(int width, int height, int max_speed, int tire) {
        cout << "Bike Instruct" << endl;
        this->width = width;
        this->height = height;
        this->max_speed = max_speed;
        this->tire = tire;
    }

    void Pr() {
        cout << "==== Bike ====" << endl;
        cout << "Width : " << width << "mm Height : " << height << "mm" << endl;
        cout << "Max Speed : " << max_speed << "KM/H Tire : " << tire << endl;
    }
};

class Car : public TransPort {
public:
    Car(int width, int height, int max_speed, int tire) {
        cout << "Car Instruct" << endl;
        this->width = width;
        this->height = height;
        this->max_speed = max_speed;
        this->tire = tire;
    }

    void Pr() {
        cout << "==== Car ====" << endl;
        cout << "Width : " << width << "mm Height : " << height << "mm" << endl;
        cout << "Max Speed : " << max_speed << "KM/H Tire : " << tire << endl;
    }
};

int main(void) {
    TransPort *tp;
    Bike bike(120, 80, 60, 2);
    Car car(4990, 1890, 240, 4);

    tp = &bike;
    tp->Pr();

    tp = &car;
    tp->Pr();


}
