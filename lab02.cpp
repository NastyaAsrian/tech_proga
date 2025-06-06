#include<iostream>

using namespace std;

class vect{
          private:
                int dim;            //измерение
                inline static int count = 0;
          public:
                double* b;
                int num;
                vect(int d){
                    dim = d;
                    b = new double[dim]{};
                    num = count + 1;
                    cout << "Вы молодчики, есть вектор"<< num << endl;
                }
                ~vect(){
                    cout << "KICK HIM OFF!"<< num<< "Bye! Bye!"<< endl;
                    delete[] b;
                }
                vect operator+(const vect& v) const{
                    vect sum(dim);
                    for (int i{}; i < dim; i++) {
                        sum.b[i] = v.b[i] + b[i];
                    }
                    cout << "Сложилось всё у"<< num << "и"<< v.num << "хорошо" << endl;
                    return sum;
                }
                vect operator-(const vect& v) const{
                    vect sub(dim);
                    for (int i{}; i < dim; i++) {
                        sub.b[i] = b[i] - v.b[i];
                    }
                    cout << "Отнялось всё у"<< num << "и"<< v.num << ", хорошо, что не ноги" << endl;
                    return sub;
                }
                vect operator-() const{
                    vect one(dim);
                    for (int i{}; i < dim; i++) {
                        one.b[i] = -b[i];
                    }
                    cout <<  num << "стал противоположным!" << endl;
                    return one;
                }
                vect operator*(const vect& v) const{
                    double mult(dim);
                    for (int i{}; i < dim; i++) {
                        mult += v.b[i] * b[i];
                    }
                    cout << "Умножились"<< num << "и"<< v.num << "хорошо" << endl;
                    return mult;
                }
                friend vect operator*(double k, const vect& v){
                    vect multn(v.dim);
                    for (int i{}; i < v.dim; i++) {
                        multn.b[i] = v.b[i] + k;
                    }
                    cout << "Умножились"<< k << "и"<< v.num << "хорошо" << endl;
                    return multn;
                }
                void show(){
                    cout << "Вектор под номером (барабанная дробь):"<< num<< "c кордами:";
                    for (int i{}; i<dim; i++){
                        cout << b[i]<<" ";
                    }
                    cout << endl;
                }
        };

class matr{
          private:
                 int dim;
                 int num;
               inline  static int count = 0;
          public:
                double* a;
                matr(int d){
                    dim = d;
                    a = new double[dim*dim]{};
                    num = count + 1;
                    cout << "Вы молодчики, есть матрица"<< num << endl;
                }
                ~matr(){
                    cout << "KICK HIM OFF!"<< num<< "Bye! Bye!"<< endl;
                    delete[] a;
                }
                matr operator+(const matr& m) const{
                    matr sum(dim);
                    for (int i{}; i < dim*dim; i++) {
                        sum.a[i] = m.a[i] + a[i];
                    }
                    cout << "Сложилось всё у"<< num << "и"<< m.num << "хорошо" << endl;
                    return sum;
                }
                matr operator-(const matr& m) const{
                    matr sub(dim);
                    for (int i{}; i < dim*dim; i++) {
                        sub.a[i] = a[i] - m.a[i];
                    }
                    cout << "Отнялось всё у"<< num << "и"<< m.num << ", хорошо, что не ноги" << endl;
                    return sub;
                }
                matr operator-() const{
                    matr one(dim);
                    for (int i{}; i < dim*dim; i++) {
                        one.a[i] = -a[i];
                    }
                    cout <<  num << "стал противоположным!" << endl;
                    return one;
                }
                matr operator*(const matr& m) const {
                    cout << "Умножение матриц #" << num << " * #" << m.num << endl;
                    matr result(dim);
                    for (int i = 0; i < dim; ++i){
                        for (int j = 0; j < dim; ++j){
                            for (int k = 0; k < dim; ++k){
                                result.a[i * dim + j] += a[i * dim + k] * m.a[k * dim + j];
                            }}}
                    return result;
                    }
                friend matr operator*(double k, const matr& m){
                    matr multn(m.dim);
                    for (int i{}; i < m.dim; i++) {
                        multn.a[i] = m.a[i] + k;
                    }
                    cout << "Умножились"<< k << "и"<< m.num << "хорошо" << endl;
                    return multn;
                }
                vect operator*(const vect& v) const {
                    cout << "Умножение матрицы на вектор" << num << "и" << v.num << endl;
                    vect result(dim);
                    for (int i = 0; i < dim; ++i){
                        for (int j = 0; j < dim; ++j){
                            result.b[i] += a[i * dim + j] * v.b[j];
                        }}
                    return result;
                    }
                void show(){
                    cout << "Матрица под номером (барабанная дробь):"<< num<< "c кордами:";
                    for (int i{}; i<dim; i++){
                        for (int j = 0; j < dim; ++j){
                            cout << a[i*dim + j]<<" ";
                        }
                        cout << endl;
                    }
                
                }
           
};

int main()
{
    vect v1(3), v2(3);
    v1.b[0] = 1; v1.b[1] = 2; v1.b[2] = 3;
    v2.b[0] = 4; v2.b[1] = 5; v2.b[2] = 6;

    vect v3 = v1 + v2;
    v3.show();

    vect v4 = -v1;
    v4.show();

    vect v5 = 2.0 * v1;
    v5.show();

    matr m1(3), m2(3);
    for (int i = 0; i < 9; ++i) {
        m1.a[i] = i + 1;
        m2.a[i] = 9 - i;
    }

    matr m3 = m1 + m2;
    m3.show();

    matr m4 = m1 * m2;
    m4.show();

    vect v6 = m1 * v1;
    v6.show();

    return 0;
}
