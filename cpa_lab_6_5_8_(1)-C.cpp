#include <iostream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

class IPAddress{
    private:
        string address;
    public:
        IPAddress() {};
        IPAddress(string address);
        string GetAddress();
};

IPAddress::IPAddress(string address){
    int octet, i = 0;
    string oct;
    istringstream iss;
    iss.str(address);

    while(getline(iss, oct, '.')){
        stringstream ss(oct);
        ss >> octet;
        if(octet < 0 || octet > 255 || ++i > 4)
            throw invalid_argument("Not valid IP address");
    }

    if(i != 4)
        throw invalid_argument("Not valid IP address");

    this->address = address;
}

string IPAddress::GetAddress(){
    return this->address;
}

class Network{
    private:
        vector<IPAddress> addresses;
        string name;
    public:
        Network(string name);
        void AddAddress(IPAddress address);
        void PrintNetwork();
};

Network::Network(string name) {
    this->name = name;
}

void Network::AddAddress(IPAddress address){
    this->addresses.push_back(address);
}

void Network::PrintNetwork(){
    cout << this->name << ":" << endl;
    for(int i = 0; i < this->addresses.size(); ++i)
        cout << this->addresses[i].GetAddress() << endl;
}

int main()
{
    string address;
    IPAddress ipAddress;
    Network network1 = Network("Network 1"), network2 = Network("Network 2");

    for(int i = 1; i < 6; ++i)
    {
        cout << "Enter valid IP address Number " << i << ":" << endl;
        cin >> address;
        try{
            ipAddress = IPAddress(address);
            if(i <= 3)
                network1.AddAddress(ipAddress);
            if(i >= 3)
                network2.AddAddress(ipAddress);
        }
        catch (const exception& e){
            cout << e.what() << " Try again." << endl;
            --i;
        }
    }
    cout << endl;
    network1.PrintNetwork();
    network2.PrintNetwork();
    return 0;
}
