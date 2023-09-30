#include <climits>
#include <algorithm>
#include "Number.h"

using namespace std;

Number::Number(bool sign) : sign{sign} {}

Number::Number(const Number & number) : sign{number.sign} {}
Number::Number(Number && number) : sign{number.sign} {
    number.sign = 0;
}

Number & Number::operator=(const Number & number) {
    sign = number.sign;
    return * this;
}

Number & Number::operator=(Number && number) {
    sign = number.sign;
    number.sign = 0;
    return * this;
}


Number::~Number() {}

int Number::get_sign() const {
    return sign ? -1 : 1;
}

int Number::sign_compare(const bool & sign2) const {
    if (sign == sign2) {
        return 0;
    }
    return get_sign();
}

int Number::blocks_compare(const vector<int> & blocks1, const vector<int> & blocks2) const {
    int n = blocks1.size();
    int m = blocks2.size();
    if (n != m) {
        return n-m; 
    }
    n -= 1;
    while(n >= 1 && blocks1[n] == blocks2[n]) {
        n -= 1;
    }
    return blocks1[n] - blocks2[n];
}

char Number::digit(unsigned int d) const {
    if (d <= 9) {
        return '0' + d;
    }
    if (d < 32) {
        return 'A' + d-10;
    }
    return '*';
}




Integer::Integer() : blocks{0}, Number{} {}

Integer::Integer(const string & number) : Number{}, blocks{} {
    set_val(number);
}

Integer::Integer(const long long & number) : Number{number < 0}, blocks{} {
    set_val(number);
}

Integer::Integer(const Integer & number) : Number{number}, blocks{number.blocks} {}

Integer::Integer(Integer && number) : Number{move(number)}, blocks{move(number.blocks)} {
    number.blocks = vector<int>{0};
}

Integer::~Integer() {}


Integer & Integer::operator=(const long long & number) {
    sign = number < 0;
    set_val(number);
    return *this;
}

Integer & Integer::operator=(const Integer & number) {
    Number::operator=(number);
    blocks = number.blocks;
    return *this;
}

Integer & Integer::operator=(Integer && number) {
    Number::operator=(move(number));
    blocks = move(number.blocks);
    number.blocks = vector<int>{0};
    return *this;
}



void Integer::set_val(const long long & number) {
    blocks.clear();
    blocks.reserve(2);
    sign = number < 0;
    if (number == 0) {
        blocks.emplace_back(0);
        return;
    }
    for (long long n = sign ? -number : number; n != 0; n /= block_max_size()){
        blocks.emplace_back(n%block_max_size());
    }
}

void Integer::set_val(const string & number) {
    size_t start = 0;
    size_t n = number.length();
    if (number[0] == '-') {
        sign = true;
        start += 1;
    }
    else {
        sign = false;
    }
    while (number[start] == '0' && start < n-1) {
        start += 1;
    }

    blocks.clear();
    blocks.reserve((n-start-1)/block_max_len()+1);

    while (start+block_max_len() < n) {
        n -= block_max_len();
        blocks.emplace_back(stoi(number.substr(n, block_max_len())));
    }

    blocks.emplace_back(stoi(number.substr(start, n-start)));
    if (blocks.size() == 1 && blocks[0] == 0) {
        sign = false;
    }
}

Integer Integer::operator-() const {
    Integer r{*this};
    if (blocks.size() != 1 || blocks[0] != 0) {
        r.sign = !sign;
    } // if r != 0
    return r;
} 

void Integer::operator<<=(const unsigned int & unit) {
    if (operator==(0)) {
        return;
    }
    vector<int> tmp = vector<int>(unit, 0);
    blocks.insert(blocks.begin(), tmp.begin(), tmp.end());
}


Integer Integer::operator<<(const unsigned int & unit) const {
    Integer res{*this};
    res <<= unit;
    return res;
}

void Integer::operator>>=(const unsigned int & unit) {
    if (unit >= blocks.size()) {
        blocks = vector<int>{0};
        sign = false;
        return;
    }
    blocks.erase(blocks.begin(), blocks.begin()+unit);
}


Integer Integer::operator>>(const unsigned int & unit) const {
    Integer res{*this};
    res >>= unit;
    return res;
}


void Integer::operator+=(const Integer & number) {
    if (sign != number.sign) {
        sign = !sign;
        operator-=(number);
        if (blocks.size() != 1 || blocks[0] != 0) {
            sign = !sign;
        } 
        return;
    }
    int next = 0;
    for (int i = 0, l = number.blocks.size(); next != 0 || i < l; i += 1) {
        if (i < l) {
            next += number.blocks[i];
        }
        if (i == blocks.size()) {
            blocks.emplace_back(next%block_max_size());
        }
        else {
            next += blocks[i];
            blocks[i] = next%block_max_size();
        }
        next /= block_max_size();
    }
}

Integer Integer::operator+(const Integer & number) const {
    Integer res {*this};
    res += number;
    return res;
}


Integer & Integer::operator++() {
    operator+=(1);
    return *this;
}

Integer Integer::operator++(int) {
    Integer res{*this};
    operator+=(1);
    return res;
}

void Integer::operator-=(const Integer & number) {
    if (this == &number) {
        blocks = vector<int>{0};
        sign = false;
        return;
    }
    if (sign != number.sign) {
        sign = !sign;
        operator+=(number);
        sign = !sign;
        return;
    }
    for (int i = 0, l = number.blocks.size(); i < l; i += 1) {
        if (i == blocks.size()) {
            blocks.emplace_back(-number.blocks[i]);
        }
        else {
            blocks[i] -= number.blocks[i];
        }
    }
    while (blocks.size() > 1 && blocks.back() == 0) {
        blocks.pop_back();
    }
    if (blocks.size() == 1 && blocks[0] == 0) {
        sign = false;
        return;
    }
    if (blocks.back() < 0) {
        for (int i = 0, l = blocks.size(); i < l; i += 1) {
            blocks[i] = -blocks[i];
        }
        sign = !sign;
    }
    for (int i = 0, l = blocks.size()-1; i < l; i += 1) {
        if (blocks[i] < 0) {
            blocks[i] += block_max_size();
            blocks[i+1] -= 1;
        }
    }
    if (blocks.back() == 0) {
        blocks.pop_back();
    }
}

Integer Integer::operator-(const Integer & number) const {
    Integer res {*this};
    res -= number;
    return res;
}

Integer & Integer::operator--() {
    operator-=(1);
    return *this;
}

Integer Integer::operator--(int) {
    Integer res{*this};
    operator-=(1);
    return res;
}

void Integer::operator*=(const Integer & number) {
    operator=(*this * number);
}

void Integer::operator*=(const long long & number) {
    if (number == 0) {
        set_val(0);
        return;
    }
    if (number < 0) {
        sign = !sign;
        operator*=(-number);
        return;
    }
    if (number >= block_max_size()) {
        operator*=(Integer{number});
        return;
    }
    long long cur = 0;
    for (int & b : blocks) {
        cur += number*b;
        b = cur%block_max_size();
        cur /= block_max_size();
    }
    while (cur > 0) {
        blocks.emplace_back(cur%block_max_size());
        cur /= block_max_size();
    }
}

Integer Integer::operator*(const Integer & number) const {
    if (*this == 0 || number == 0) {
        return Integer{0};
    }
    Integer res{0};
    size_t n = blocks.size();
    for (size_t i = 0; i < n; i += 1) {
        res += (number*blocks[i]) << i;
    }
    res.sign = sign != number.sign;
    return res;
}

Integer Integer::operator*(const long long & number) const {
    Integer res {*this};
    res *= number;
    return res;
}

Integer Integer::operator/(const Integer & number) const {
    Integer res{};
    Integer rmd{};
    div(number, res, rmd);
    return res;
}

Integer Integer::operator/(const long long & number) const {
    Integer res{};
    Integer rmd{};
    div(number, res, rmd);
    return res;
}

Integer Integer::operator%(const Integer & number) const {
    Integer res{};
    Integer tmp{};
    div(number, tmp, res);
    return res;
}

Integer Integer::operator%(const long long & number) const {
    Integer res{};
    Integer tmp{};
    div(number, tmp, res);
    return res;
}


void Integer::div(const Integer & dvs, Integer & qtn, Integer & rmd) const {
    if (dvs == 0) {
        err_div_0();
    }

    if (dvs < block_max_size() && dvs > -block_max_size()) {
        div(dvs.to_ll(), qtn, rmd);
    }
    int m = blocks.size();
    int n = dvs.blocks.size();
    rmd = Integer(*this);

    if (blocks_compare(blocks, dvs.blocks) < 0) {
        qtn.set_val(0);
        return;
    }

    bool resSign = sign != dvs.sign;
    rmd.sign = false;

    vector<Integer> dvsP2 {dvs};
    dvsP2[0].sign = false;
    dvsP2.reserve(31);
    
    
    if (blocks_compare(operator>>(m-n).blocks, dvs.blocks) < 0) {
        m -= 1;
    }
    qtn = Integer(1) << m-n;
    
    for (int l = m-n; l >= 0; l -= 1) {
        int block = 0;
        Integer srmd{rmd >> l};
        while (dvsP2.back() < srmd) {
            dvsP2.emplace_back(dvsP2.back()*2);
        }
        int dl = dvsP2.size();
        //cout << "dl = " << dl << endl;
        int fac = pow(2,dl-1);
        for (int k = dl-1; k >= 0; k -= 1) {
            Integer d = dvsP2[k] << l;
            if (rmd >= d) {
                block += fac;
                rmd -= d;
                //cout << rmd << ", " << d << endl;
                //cout << block << endl;

            }
            fac /= 2;
        }
        qtn.blocks[l] = block;
    }

    qtn.sign = resSign;
    if (rmd != 0) {
        rmd.sign = sign;
    }
}

void Integer::div(long long dvs, Integer & qtn, Integer & rmd) const {
    if (dvs == 0) {
        err_div_0();
    }
    if (dvs >= block_max_size() || dvs <= -block_max_size()) {
        div(Integer{dvs}, qtn, rmd);
        return;
    }
    qtn = Integer{1};
    qtn.sign = sign;
    if (dvs < 0) {
        dvs *= -1;
        qtn.sign = !sign;
    }

    int i = blocks.size() - 2;
    long long rm = blocks.back();
    if (i == -1 && rm < dvs) {
        rmd = *this;
        qtn = 0;
        return;
    }
    if (i >= 0 && rm < dvs) {
        rm *= block_max_size();
        rm += blocks[i];
        i -= 1;
    }
    qtn <<= i+1;
    while (rm >= dvs) {
        qtn.blocks[i+1] = rm/dvs;
        rm %= dvs;
        if (i >= 0) {
            rm *= block_max_size();
            rm += blocks[i];
            i -= 1;
        }
    }
    rmd = Integer{rm};
    if (rmd != 0) {
        rmd.sign = sign;
    }
}

void Integer::err_div_0() const {
    cerr << "\nerror: division by 0\n";
    exit(-1);
}

Integer Integer::pwr(const int & n) const {
    if (n < 0) {
        return Integer{0};
    }
    if (n == 0) {
        return Integer{1}; 
    }
    if (n >= pow(10, 6)){
        return Integer{-1};
    }
    vector<Integer> pwrVal{Integer{0}, Integer{*this}};
    pwrVal.reserve(31);
    for (int i = 1, j = 1; j <= n; i += 1, j *= 2) {
        pwrVal.emplace_back(pwrVal[i]*pwrVal[i]);
    }
    Integer res{1};
    for (int l = n, i = 1; l != 0; l /= 2, i += 1) {
        if (l%2 == 1) {
            res *= pwrVal[i];
        }
    }
    return res;
}

string Integer::in_base(unsigned int b) const {
    string res{};
    if (b <= 1 || b > 32) {
        err_base();
    }
    Integer rm{*this};
    rm.sign = false;
    int nb_size = 0;
    for (int bms = block_max_size(); bms != 0; bms /= b) {
        nb_size += 1;
    }
    res.reserve(nb_size*blocks.size());
    while (rm != 0) {
        Integer qt{}, nr{};
        rm.div(b, qt, nr);
        res += digit(nr.to_ll());
        rm = move(qt);
    }
    if (sign) {
        res += '-';
    }
    reverse(res.begin(), res.end());
    return res;
}

void Integer::err_base() const {
    cerr << "\nerror: in valid base\n";
    exit(-1);
}

long long Integer::to_ll() const {
    if (*this >= LLONG_MAX-1 || *this <= LLONG_MIN+1) {
        err_ll_overflow();
    }
    long long res = 0;
    for (int i = blocks.size()-1; i >= 0; i -= 1) {
        res *= block_max_size();
        res += blocks[i];
    }
    if (sign) {
        res *= -1;
    }
    return res;
}

void Integer::err_ll_overflow() const {
    cout << "\nerror: long long overflow\n";
    exit(-1);
}


string Integer::rps() const {
    string res{};
    int n = blocks.size();
    res.reserve(block_max_len()*n + 1);
    if (sign) {
        res += '-';
    }
    n -= 1;
    res += to_string(blocks[n]);
    while (n != 0) {
        n -= 1;
        string nb = to_string(blocks[n]);
        res += string(block_max_len()-nb.size(), '0');
        res += nb;
    }
    return res;
}




istream & operator>>(istream & in, Integer & number) {
    string s{};
    in >> s;
    number.set_val(s);
    return in;
}

ostream & operator<<(ostream & out, const Integer & number) {
    out << number.rps();
    return out;
}