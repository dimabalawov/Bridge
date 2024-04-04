#include <iostream>
#include <string>

using namespace std;



class Device
{
protected:
    string name;
public:
    virtual void Print() = 0;
};

class GPU : public Device
{
    int memory;
public:
    GPU(string name, int memory)
    {
        this->memory = memory;
        this->name = name;
    }
    void Print() override
    {
        cout << "GPU Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Memory: " << memory << endl << endl;
    }
};

class CPU : public Device
{
    double frequency;
public:
    CPU(string name, double frequency)
    {
        this->frequency = frequency;
        this->name = name;
    }
    void Print() override
    {
        cout << "CPU Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Frequency: " << frequency << endl << endl;
    }
};

class HardDrive : public Device
{
    int memory;
public:
    HardDrive(string name, int memory)
    {
        this->memory = memory;
        this->name = name;
    }
    void Print() override
    {
        cout << "HardDrive Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Memory: " << memory << endl <<endl;
    }
};

class RAM : public Device
{
    int memory;
public:
    RAM(string name, int memory)
    {
        this->memory = memory;
        this->name = name;
    }
    void Print() override
    {
        cout << "RAM Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Memory: " << memory << endl << endl;
    }
};


class DeviceReport {
protected:
    Device* device;
public:
    DeviceReport(Device* dev) : device(dev) {}

    virtual void MakeReport() = 0;
};

class DeviceReportBridge : public DeviceReport {
public:
    DeviceReportBridge(Device* dev) : DeviceReport(dev) {}

    void MakeReport() override
    {
        device->Print();
    }
};

int main() {
    GPU gpu("Nvidia GTX 1080 TI", 16);
    DeviceReportBridge gpuReport(&gpu);
    gpuReport.MakeReport();


    CPU cpu("Intel Core i9-14900K", 4.4);
    DeviceReportBridge cpuReport(&cpu);
    cpuReport.MakeReport();


    HardDrive drive("Seagate BarraCuda", 2000);
    DeviceReportBridge driveReport(&drive);
    driveReport.MakeReport();


    RAM ram("Kingston", 2000);
    DeviceReportBridge ramReport(&ram);
    ramReport.MakeReport();

}
