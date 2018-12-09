#include <iostream>
#include <vector>

using namespace std;

class Matric {
    private:
        vector <vector<int>> mat;
        const int dimy = 0;
        const int dimx = 0;
    public:
        Matric(int const y = 1, int x = 1) :dimx(x), dimy(y) {
            for (int i = 0; i < y; i++) {
                mat.insert(mat.end(), vector <int>(x));
                for (int j = 0; j < x; ++j)
                    mat[i][j] = 0;
            }
        }
        void AddElem(int q) {
            if (q == NULL)
                throw string("value is empty");
            for (int i = 0; i < dimy; i++)
            {
                for (int j = 0; j < dimx; j++) {
                    mat[i][j] += q;
                }
            }
        }
        Matric AddMatrics(Matric c) {
            if (c.dimx != dimx||c.dimy != dimy)
                throw string("Matrices don't fit.\n");
            Matric n(dimy, dimy);
            for (size_t i = 0; i < dimy; i++)
            {
                for (size_t j = 0; j < dimx; j++) {
                    n.mat[i][j] = this->mat[i][j] + c.mat[i][j];
                }
            }
            return n;
        }
        void print() {
            for (size_t i = 0; i < this->dimy; i++)
            {
                for (size_t j = 0; j < this->dimx; j++) {
                    cout << this->mat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
	int x, y;
	cin >> x >> y;
	Matric a(y, x);
	cin >> x >> y;
	Matric b(y, x);
	cin >> x >> y;
	Matric c(y, x);
	try { a.AddMatrics(b).print(); }
	catch (string e) { cout << e; }
	try { a.AddMatrics(c).print(); }
	catch (string e) { cout << e; }
	try { b.AddMatrics(c).print(); }
	catch (string e) { cout << e; }

	return 0;
}
