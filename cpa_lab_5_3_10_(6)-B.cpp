#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class FlightBooking {
    public:
        FlightBooking(int id, int capacity, int reserved = 0);
        void printStatus();
        bool reserveSeats(int number_ob_seats);
        bool cancelReservations(int number_ob_seats);
        int getID() { return id; };
    private:
        int id;
        int capacity;
        int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	if (reserved<0)
		this->reserved = 0;
	if (reserved * 100 / capacity>105)
		this->reserved = 105 * capacity / 100;
	else
		this->reserved = reserved;
	this->capacity = capacity;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if ((reserved + number_ob_seats) * 100 / capacity > 105)
		return false;
	reserved += number_ob_seats;
	return true;
}
bool FlightBooking::cancelReservations(int number_ob_seats)
{
	if (reserved < number_ob_seats)
		return false;

	reserved -= number_ob_seats;
	return true;
}
void FlightBooking::printStatus()
{
	cout << "Flight " << id << " : " << reserved << "\\" << capacity << " ("
        << reserved * 100 / capacity << "%) seats reserved" << endl;
}
int main() {
	vector<FlightBooking> booking;
	string temp;
	string command = "";
	int i, id, capacity, n;

	while (command != "quit")
	{
		cout << "What would you like to do?: ";
		getline(cin, command);
		i = -1;

		if (command.find("add") != -1) {
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			n = atoi(command.substr(command.find(" ")).c_str());

			while (++i < booking.size())
				if (booking[i].getID() == id) break;

			if (i == booking.size() || !booking[i].reserveSeats(n)) {
				cout << "Cannot perform this operation" << endl;
			};
		}
		if (command.find("cancel") != -1) {
			command = command.substr(command.find(" ") + 1);
			id = atoi(command.c_str());
			n = atoi(command.substr(command.find(" ")).c_str());

			while (++i < booking.size())
				if (booking[i].getID() == id) break;

			if (i == booking.size() || !booking[i].cancelReservations(n)) {
				cout << "Cannot perform this operation" << endl;
			};
		}
		if (command.find("create") != -1) {
			try {
				command = command.substr(command.find(" ") + 1);
				id = atoi(command.c_str());
				capacity = atoi(command.substr(command.find(" ")).c_str());
				booking.push_back(FlightBooking(id, capacity));
			}
			catch(...)
			{
				cout << "Cannot perform this operation" << endl;
			}
		}
		if (command.find("delete") != -1) {
			id = atoi(command.substr(command.find(" ")).c_str());

			while (++i < booking.size())
				if (booking[i].getID() == id) break;

			if (i == booking.size())
				cout << "Cannot perform this operation" << endl;
			else
				booking.erase(booking.begin() + i);
		}

		for (int i = 0; i < booking.size(); ++i)
		{
			booking[i].printStatus();
		}
	}
	return 0;
}
