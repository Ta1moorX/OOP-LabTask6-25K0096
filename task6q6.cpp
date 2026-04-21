#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string brand, model;
public:
    Device(string b, string m) : brand(b), model(m) {}
    void display() {
        cout << "Brand: " << brand
             << " | Model: " << model << endl;
    }
};

class Smartphone : virtual public Device {
protected:
    int simSlots;
public:
    Smartphone(string b, string m, int s)
        : Device(b, m), simSlots(s) {}
    void display() {
        Device::display();
        cout << "SIM Slots: " << simSlots << endl;
    }
};

class Tablet : virtual public Device {
protected:
    bool stylusSupport;
public:
    Tablet(string b, string m, bool st)
        : Device(b, m), stylusSupport(st) {}
    void display() {
        Device::display();
        cout << "Stylus Support: " << (stylusSupport ? "Yes" : "No") << endl;
    }
};


class HybridDevice : public Smartphone, public Tablet {
    string specialFeature;
public:

    HybridDevice(string b, string m, int s, bool st, string feat)
        : Device(b, m),           
          Smartphone(b, m, s),
          Tablet(b, m, st),
          specialFeature(feat) {}

    void display() {
        Device::display();        
        cout << "SIM Slots:" << simSlots                         << endl;
        cout << "Stylus Support:" << (stylusSupport ? "Yes" : "No")   << endl;
        cout << "Special Feature:" << specialFeature                  << endl;
    }
};

int main() {
    HybridDevice hd("Samsung", "Galaxy Ultra Tab", 2, true, "Foldable Screen");
    cout << "Hybrid Device Details" << endl;
    hd.display();
    return 0;
}
