#include <iostream>
#include "sstream"

using namespace std;

class Figure
{
    public:
        Figure() {
            x1 = 2;
            y1 = 1;
        }
        virtual bool CanIgo(string pos) {
            return true;
        }
        void DetPos(string pos) {
            switch (pos[0]) {
                case 'a':
                    x = 1;
                    break;
                case 'b':
                    x = 2;
                    break;
                case 'c':
                    x = 3;
                    break;
                case 'd':
                    x = 4;
                    break;
                case 'e':
                    x = 5;
                    break;
                case 'f':
                    x = 6;
                    break;
                case 'g':
                    x = 7;
                    break;
                case 'h':
                    x = 8;
                    break;
                default:
                    break;
            }
            stringstream ss;
            ss << pos[1];
            ss >> y;
        }
    protected:
        int x, y;
        int x1, y1;
};

class Man : public Figure {
    public:
        Man() :Figure() { }
        bool CanIgo(string pos) {
            DetPos(pos);
            return (((x1 - x) == 1 || (x - x1) == 1) && ((y - y1 == 1) || (y1 - y == 1)));
        }
};

class King :public Figure {
    public:
        King() :Figure() { }
        bool CanIgo(string pos) {
            DetPos(pos);
            return (bool)(((x1 - x) > 0) ? (x1 - x) : (x - x1))== ((y1 - y) > 0) ? (y1 - y) : (y - y1);
        }
};

int main()
{
	Figure *m, *k;
	m = new Man;
	k = new King;
	string q;

	cout << "Enter position where Man want to go from b1: ";
	getline(cin, q);
	cout << ((m->CanIgo(q.substr(q.length() - 2))) ? "true" : "false") << endl;
	cout << "Enter position where King want to go from b1: ";
	getline(cin, q);
	cout << ((k->CanIgo(q.substr(q.length() - 2))) ? "true" : "false") << endl;
	cout << "Enter position where Man want to go from b1: ";
	getline(cin, q);
	cout << ((m->CanIgo(q.substr(q.length() - 2))) ? "true" : "false") << endl;

	return 0;
}
