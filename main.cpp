#include <climits>


#include "Number.h"

using namespace std;


Integer fib(int n) {
    if (n <= 2) {
        return Integer(1);
    }
    Integer x{1}, y{0};
    while (n != 2) {
        n -= 1;
        Integer tmp{x};
        x += y;
        y = tmp;
    }
    return x;
}


int rfib(const Integer & x, const Integer & y) {
    Integer a{x}, b{y};
    int n = 2;
    while(b != Integer{0}) {
        n += 1;
        a -= b;
        Integer tmp{a};
        a = b;
        b = tmp;
    }
    return n;
}


int main() {
    Integer i{};
    Integer j{};

/*
    cout << "Constructor/Assignment Operator Test:\n\nPlease input i and j:\n";
    cin >> i >> j;

    cout << "Your input is:\n";
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    cout << "\nCopy i and construct k:\n";
    Integer k{i};
    cout << "i = " << i << endl;
    cout << "k = " << k << endl;

    cout << "\nMove j and construct h:\n";
    Integer h{move(j)};
    cout << "j = " << j << endl;
    cout << "h = " << h << endl;

    cout << "\nCopy i to j:\n";
    j = i;
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;

    cout << "\nMove -1000 to i: \n";
    i = Integer{"-1000"};
    cout << "i = " << i << endl;

    cout << "\nConstruct x with long long value -10000000000000:\n";
    Integer x{-10000000000000};
    cout << "x = " << x << endl;

    cout << "\nSet x to -100000000000000000:\n";
    x = -100000000000000000;
    cout << "x = " << x << endl;
*/

    cout << "\nComparison Operators Test (Integer):\n";
    i = Integer{"999999999999999999999999999999999999"};
    j = Integer{"1000000000000000000000000000000000000"};
    cout << "Compare " << i << ", " << j << ":\n";
/*
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }

    i = Integer{"-999999999999999999999999999999999999"};
    j = Integer{"1000000000000000000000000000000000000"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }

    i = Integer{"999999999999999999999999999999999999"};
    j = Integer{"-1000000000000000000000000000000000000"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }
    i = Integer{"-999999999999999999999999999999999999"};
    j = Integer{"-1000000000000000000000000000000000000"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }
    i = Integer{"0"};
    j = Integer{"-0"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }

    i = Integer{"0"};
    j = Integer{"1"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }

    i = Integer{"0"};
    j = Integer{"-1"};
    cout << "Compare " << i << ", " << j << ":\n";
    if (i == j) {
        cout << "i = j\n";
    }
    if (i != j) {
        cout << "i != j\n";
    }
    if (i < j) {
        cout << "i < j\n";
    }
    if (i <= j) {
        cout << "i <= j\n";
    }
    if (i > j) {
        cout << "i > j\n";
    }
    if (i >= j) {
        cout << "i >= j\n";
    }
*/

    cout << "\nComparison Operators Test (long long):\n";
    long long i2 = 999999999999999999;
    long long j2 = 1000000000000000000;
/*
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = -999999999999999999;
    j2 = 1000000000000000000;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = 999999999999999999;
    j2 = -1000000000000000000;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = -999999999999999999;
    j2 = -1000000000000000000;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = 0;
    j2 = 0;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = 0;
    j2 = 1;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }

    i2 = 0;
    j2 = 1;
    cout << "Compare " << i2 << ", " << j2 << ":\n";
    if (i2 == j2) {
        cout << "i2 = j2\n";
    }
    if (i2 != j2) {
        cout << "i2 != j2\n";
    }
    if (i2 < j2) {
        cout << "i2 < j2\n";
    }
    if (i2 <= j2) {
        cout << "i2 <= j2\n";
    }
    if (i2 > j2) {
        cout << "i2 > j2\n";
    }
    if (i2 >= j2) {
        cout << "i2 >= j2\n";
    }
*/

    Integer k{0};
    Integer h{-1111111111};
    cout << "<<, >>:\n" << "k, h = " << k << ", " << h << endl;

/*
    cout << "k << 20 = " << (k << 20) << endl;
    h <<= 1;
    cout << "h <<= 1, k = " << h << endl;
    cout << "k >> 20 = " << (k >> 20) << endl;
    cout << "h >> 1 = " << (h >> 1) << endl;
    cout << "h >> 2 = " << (h >> 2) << endl;
    cout << "h >> 3 = " << (h >> 3) << endl;
*/

    i = Integer(0);
    j = Integer(0);
    cout << "\n+=, -=:\ni = j = " << i << "\n";


/*
    i += -1000000000000000000;
    j += 1000000000000000000;
    cout << "i += -1000000000000000000\ni = " << i << endl;
    cout << "j += 1000000000000000000\nj = " << j << endl;

    i += 1;
    j += -1;
    cout << "i += 1\ni = " << i << endl;
    cout << "j += -1\nj = " << j << endl;

    i += -2;
    j += 2;
    cout << "i += -2\ni = " << i << endl;
    cout << "j += 2\nj = " << j << endl;

    i -= -1000000000000000000;
    j -= 1000000000000000000;
    cout << "i -= -1000000000000000000\ni = " << i << endl;
    cout << "j -= 1000000000000000000\nj = " << j << endl;

    i -= 1;
    j -= -1;
    cout << "i -= 1\ni = " << i << endl;
    cout << "j -= -1\nj = " << j << endl;

    i -= -2;
    j -= 2;
    cout << "i -= -2\ni = " << i << endl;
    cout << "j -= 2\nj = " << j << endl;

    i -= -1;
    j -= 1;
    cout << "i -= -1\ni = " << i << endl;
    cout << "j -= 1\nj = " << j << endl;

*/  
/*
    cout << "counter: from 0 to 99999999999999999*100, sep = 99999999999999999";
    Integer t{};
    for (int i = 0; i <= 100; i += 1) {
        cout << t << endl;
        t += 99999999999999999;
    }

    cout << "counter: from 99999999999999999*100 to -99999999999999999*1000, sep = 99999999999999999\n";
    for (int i = 0; i <= 201; i += 1) {
        cout << t << endl;
        t -= 99999999999999999;
    }
    */

    Integer a("99999999999999999999999999");
    Integer b(a);
    Integer c("-99999999999999999999999999");
    Integer d(c);
   /*
    cout << "a = b = "<< a << ", c = d = "<< d << "\na += a:\n";
    a += a;
    cout << "a = " << a << endl;

    cout << "a -= b:\n";
    a -= b;
    cout << "a = " << a << endl;

    cout << "a += c:\n";
    a += c;
    cout << "a = " << a << endl;

    cout << "a -= d:\n";
    a -= d;
    cout << "a = " << a << endl;

    cout << "d -= a\n";
    d -= a;
    cout << "d = " << d << endl;

    cout << "d += b\n";
    d += b;
    cout << "d = " << d << endl;

    cout << "d -= c\n";
    d -= c;
    cout << "d = " << d << endl;

    cout << "d += d\n";
    d += d;
    cout << "d = " << d << endl;

    cout << "a += d\n";
    a += d;
    cout << "a = " << a << endl;

    cout << "c += d\n";
    c += d;
    cout << "c = " << c << endl;

    c = Integer{"-1"};
    while (c > Integer{"-100000000000000000000000000000000000000000000000000"}) {
        cout << "c += c\n";
        c += c;
        cout << "c = " << c << endl;
    }

    cout << "\nneg (-):\n";
    a = Integer(0);
    b = Integer(1);
    c = Integer(-1);

    cout << "a = " << a << ", -a = " << (-a) << endl; 
    cout << "b = " << b << ", -b = " << (-b) << endl; 
    cout << "c = " << c << ", -c = " << (-c) << endl;
*/
/*
    a = Integer{999999999999999999};
    b = Integer{1};
    cout << "\n+, -:\na, b = " << a << ", " << b << endl; 
    c = a+b;
    cout << "a + b = " << a << " + " << b << " = " << c << endl;
    cout << "a - b = " << a-b << endl;
    cout << "a + -b = " << a+(-b) << endl;
    cout << "a - -b = " << a-(-b) << endl;
    cout << "a + 100000000000000000 = " << a + 100000000000000000 << endl;
    cout << "a - 100000000000000000 = " << a - 100000000000000000 << endl;
    cout << "a + -100000000000000000 = " << a + -100000000000000000 << endl;
    cout << "a - -100000000000000000 = " << a - -100000000000000000 << endl;
*/


/*
    cout << "fibonacci numbers, n = 100, 1000, 100000" << endl;
    cout << fib(100) << "\n";
    cout << fib(1000) << "\n";
    cout << fib(100000) << "\n";

    cout << "rfib\n";
    cout << rfib(fib(10000), fib(9999)) << endl;
//*/

    a = Integer{"999999999999999999"};
    b = Integer{"-999999999999999999"};
    c = Integer{"123456789101112131"};
    cout << "\n*:\n" << "a = " << a << endl;

/*
    cout << "a * 0 = " << a*0 << endl;
    cout << "a * 0 = " << a*Integer{0} << endl;
    cout << "b * 0 = " << b*0 << endl;
    cout << "b * 0 = " << b*Integer{0} << endl;
    cout << "a * 2 = " << a*2 << endl;
    cout << "a * 2 = " << a*Integer{2} << endl;
    cout << "b * 2 = " << b*2 << endl;
    cout << "b * 2 = " << b*Integer{2} << endl;
    cout << "a * -2 = " << a*-2 << endl;
    cout << "a * -2 = " << a*Integer{-2} << endl;
    cout << "b * -2 = " << b*-2 << endl;
    cout << "b * -2 = " << b*Integer{-2} << endl;
    cout << "a * 999999999 = " << a*999999999 << endl;
    cout << "a * 999999999 = " << a*Integer{999999999} << endl;
    cout << "b * 999999999 = " << b*999999999 << endl;
    cout << "b * 999999999 = " << b*Integer{999999999} << endl;
    cout << "a * -999999999 = " << a*-999999999 << endl;
    cout << "a * -999999999 = " << a*Integer{-999999999} << endl;
    cout << "b * -999999999 = " << b*-999999999 << endl;
    cout << "b * -999999999 = " << b*Integer{-999999999} << endl;

    cout << "a * 9999999999 = " << a*9999999999 << endl;
    cout << "b * 9999999999 = " << b*9999999999 << endl;
    cout << "a * -9999999999 = " << a*-9999999999 << endl;
    cout << "b * -9999999999 = " << b*-9999999999 << endl;

    cout << "a * a = " << a * a << endl;
    cout << "b * b = " << b * b << endl;
    cout << "a * a * c * c = " << a * a * c * c << endl;
    cout << "c * c * a * a = " << c * c * a * a << endl;
    cout << "a * c * a * c = " << a * c * a * c << endl;

//*/


    cout << "\npwr:\n 2^[0-100]\n";
    
/*
    for (int i = -1; i <= 100; i += 1) {
        cout << "2^" << i << " = " << Integer{2}.pwr(i) << endl;
    }

    for (int i = 100; i <= 10000; i += 100) {
        cout << "2^" << i << " = " << Integer{2}.pwr(i) << endl;
    }
*/

/*
    cout << "2^199999 = " << Integer{2}.pwr(199999) << endl;
*/

    
    cout << "\n/:\n";
/*
    cout << "self:\n";
    a = Integer{"999999999999999999"};
    cout << a << " / " << a << " = " << a/a << ", ";
    cout << "real: " << a.to_ll()/a.to_ll() << endl;
    cout << a << " % " << a << " = " << a%a << ", ";
    cout << "real: " << a.to_ll()%a.to_ll() << endl;
    cout << a << " / " << -a << " = " << a/-a << ", ";
    cout << "real: " << a.to_ll()/-a.to_ll() << endl;
    cout << a << " % " << -a << " = " << a%-a << ", ";
    cout << "real: " << a.to_ll()%-a.to_ll() << endl;
    cout << -a << " / " << a << " = " << -a/a << ", ";
    cout << "real: " << -a.to_ll()/a.to_ll() << endl;
    cout << -a << " % " << a << " = " << -a%a << ", ";
    cout << "real: " << -a.to_ll()%-a.to_ll() << endl;
    cout << -a << " / " << -a << " = " << -a/-a << ", ";
    cout << "real: " << -a.to_ll()/-a.to_ll() << endl;
    cout << -a << " % " << -a << " = " << -a%-a << ", ";
    cout << "real: " << -a.to_ll()%-a.to_ll() << endl;

    a = Integer{"999999999999999999"};
    b = Integer{"999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"999999999999999999"};
    b = Integer{"-999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"-999999999999999999"};
    b = Integer{"999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"-999999999999999999"};
    b = Integer{"-999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << " = " << a/b.to_ll() << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << " = " << a%b.to_ll() << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"999999999999999999"};
    b = Integer{"1999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << " = " << a/b.to_ll() << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << " = " << a%b.to_ll() << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"1999999999999999999"};
    b = Integer{"999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << " = " << a/b.to_ll() << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << " = " << a%b.to_ll() << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;

    a = Integer{"1999999999999999999"};
    b = Integer{"1999999999"};
    cout << "\na,b = " << a << ", " << b << endl;
    cout << "a / b" << " = " << a/b << " = " << a/b.to_ll() << ", ";
    cout << "real: " << a.to_ll()/b.to_ll() << endl;
    cout << "a % b" << " = " << a%b << " = " << a%b.to_ll() << ", ";
    cout << "real: " << a.to_ll()%b.to_ll() << endl;
   
    
    cout << "\nsmall\n";
    a = Integer{888888888888888888};
    cout << a << " / " << 1 << " = " << a/1 << ", ";
    cout << "real: " << a.to_ll()/1 << endl;
    cout << a << " % " << 1 << " = " << a%1 << ", ";
    cout << "real: " << a.to_ll()%1 << endl;
    cout << -a << " / " << 1 << " = " << -a/1 << ", ";
    cout << "real: " << -a.to_ll()/1 << endl;
    cout << -a << " % " << 1 << " = " << -a%1 << ", ";
    cout << "real: " << -a.to_ll()%1 << endl;
    cout << a << " / " << -1 << " = " << a/-1 << ", ";
    cout << "real: " << a.to_ll()/-1 << endl;
    cout << a << " % " << -1 << " = " << a%-1 << ", ";
    cout << "real: " << a.to_ll()%-1 << endl;
    cout << -a << " / " << -1 << " = " << -a/-1 << ", ";
    cout << "real: " << -a.to_ll()/-1 << endl;
    cout << -a << " % " << -1 << " = " << -a%-1 << ", ";
    cout << "real: " << -a.to_ll()%-1 << endl;

    cout << a << " / " << 10 << " = " << a/10 << ", ";
    cout << "real: " << a.to_ll()/10 << endl;
    cout << a << " % " << 10 << " = " << a%10 << ", ";
    cout << "real: " << a.to_ll()%10 << endl;
    cout << -a << " / " << 10 << " = " << -a/10 << ", ";
    cout << "real: " << -a.to_ll()/10 << endl;
    cout << -a << " % " << 10 << " = " << -a%10 << ", ";
    cout << "real: " << -a.to_ll()%10 << endl;
    cout << a << " / " << -10 << " = " << a/-10 << ", ";
    cout << "real: " << a.to_ll()/-10 << endl;
    cout << a << " % " << -10 << " = " << a%-10 << ", ";
    cout << "real: " << a.to_ll()%-10 << endl;
    cout << -a << " / " << -10 << " = " << -a/-10 << ", ";
    cout << "real: " << -a.to_ll()/-10 << endl;
    cout << -a << " % " << -10 << " = " << -a%-10 << ", ";
    cout << "real: " << -a.to_ll()%-10 << endl;

    cout << a << " / " << 233 << " = " << a/233 << ", ";
    cout << "real: " << a.to_ll()/233 << endl;
    cout << a << " % " << 233 << " = " << a%233 << ", ";
    cout << "real: " << a.to_ll()%233 << endl;
    cout << -a << " / " << 233 << " = " << -a/233 << ", ";
    cout << "real: " << -a.to_ll()/233 << endl;
    cout << -a << " % " << 233 << " = " << -a%233 << ", ";
    cout << "real: " << -a.to_ll()%233 << endl;
    cout << a << " / " << -233 << " = " << a/-233 << ", ";
    cout << "real: " << a.to_ll()/-233 << endl;
    cout << a << " % " << -233 << " = " << a%-233 << ", ";
    cout << "real: " << a.to_ll()%-233 << endl;
    cout << -a << " / " << -233 << " = " << -a/-233 << ", ";
    cout << "real: " << -a.to_ll()/-233 << endl;
    cout << -a << " % " << -233 << " = " << -a%-233 << ", ";
    cout << "real: " << -a.to_ll()%-233 << endl;
//*/

    cout << "in_base()\n";
///*
    cout << 0 << " in base 2: " << Integer{0}.in_base(2) << endl;
    cout << 0 << " in base 16: " << Integer{0}.in_base(16) << endl;
    cout << 0 << " in base 32: " << Integer{0}.in_base(32) << endl << endl;

    cout << 100 << " in base 2: " << Integer{100}.in_base(2) << endl;
    cout << 100 << " in base 16: " << Integer{100}.in_base(16) << endl;
    cout << 100 << " in base 32: " << Integer{100}.in_base(32) << endl << endl;

    cout << -100 << " in base 2: " << Integer{-100}.in_base(2) << endl;
    cout << -100 << " in base 16: " << Integer{-100}.in_base(16) << endl;
    cout << -100 << " in base 32: " << Integer{-100}.in_base(32) << endl << endl;

    for (Integer i{999999999999900000}; i < Integer{1000000000000100000}; i += 10000) {
        cout << i << " in base 2: " << i.in_base(2) << endl;
        cout << i << " in base 16: " << i.in_base(16) << endl;
        cout << i << " in base 32: " << i.in_base(32) << endl << endl; 
    }
//*/
    return 0;
} 