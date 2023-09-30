
#ifndef NUMBER_H
#define NUMBER_H

#include <iostream> 
#include <vector>
#include <string>
#include <cmath>

class Number {

    protected:
    bool sign;

    // get sign
    //      sign = false: 1
    //      sign = false: -1
    int get_sign() const;

    // compare sign
    //    sign = sign2: 0
    //    sign != sign2: getSign()
    int sign_compare(const bool & sign2) const;

    // compare block
    int blocks_compare(const std::vector<int> & block1, const std::vector<int> & block2) const;

    // digit representation, [d < 32]
    //    digit(0) = '0'
    //    digit(10) = 'A'
    //    digit(32) = '*'
    char digit(unsigned int d) const;


    public:
    Number(bool sign = false);
    Number(const Number & number);
    Number(Number && number);
    virtual Number & operator=(const Number & number);
    virtual Number & operator=(Number && number);


    ~Number();

    // set value
    virtual void set_val(const long long & number) = 0;
    virtual void set_val(const std::string & number) = 0;

    // string representation
    virtual std::string rps() const = 0;

};

class Integer: public Number {
    std::vector<int> blocks;

    inline int block_max_len() const {
        return 9;
    }
    
    inline int block_max_size() const {
        return pow(10,block_max_len());
    }
    
    public:
    Integer();
    Integer(const std::string & number);
    Integer(const long long & number);
    Integer(const Integer & number);
    Integer(Integer && number);
    Integer & operator=(const long long & number);
    Integer & operator=(const Integer & number);
    Integer & operator=(Integer && number);
    ~Integer();

    Integer operator-() const;

    inline bool operator==(const Integer & number) const {
        return sign_compare(number.sign) == 0 && blocks_compare(blocks, number.blocks) == 0;
    }

    inline bool operator==(const long long & number) const {
        return operator==(Integer{number});
    }

    inline bool operator!=(const Integer & number) const {
        return !operator==(number);
    }

    inline bool operator!=(const long long & number) const {
        return !operator==(number);
    }

    inline bool operator<(const Integer & number) const {
        return sign_compare(number.sign) < 0 || 
            (sign_compare(number.sign) == 0 && get_sign()*blocks_compare(blocks, number.blocks) < 0);
    }

    inline bool operator<(const long long & number) const {
        return operator<(Integer{number});
    }


    inline bool operator<=(const Integer & number) const{
        return sign_compare(number.sign) < 0 || 
            (sign_compare(number.sign) == 0 && get_sign()*blocks_compare(blocks, number.blocks) <= 0);
    }

    inline bool operator<=(const long long & number) const{
        return operator<=(Integer{number});
    }

    inline bool operator>(const Integer & number) const {
        return !operator<=(number);
    }

    inline bool operator>(const long long & number) const {
        return !operator<=(number);
    }

    inline bool operator>=(const Integer & number) const{
        return !operator<(number);
    }
    
    inline bool operator>=(const long long & number) const{
        return !operator<(number);
    }


    void operator<<=(const unsigned int & unit);

    Integer operator<<(const unsigned int & unit) const;

    void operator>>=(const unsigned int & unit);

    Integer operator>>(const unsigned int & unit) const;

    Integer operator+(const Integer & number) const;

    inline Integer operator+(const long long & number) const {
        return operator+(Integer{number});
    }

    void operator+=(const Integer & number);

    inline void operator+=(const long long & number) {
        operator+=(Integer{number});
    }

    Integer & operator++();

    Integer operator++(int);
    
    Integer operator-(const Integer & number) const;

    inline Integer operator-(const long long & number) const {
        return operator-(Integer{number});
    }
    
    void operator-=(const Integer & number);

    inline void operator-=(const long long & number) {
        operator-=(Integer{number});
    }
    
    Integer & operator--();

    Integer operator--(int);

    Integer operator*(const Integer & number) const;

    Integer operator*(const long long & number) const;

    void operator*=(const Integer & number);

    void operator*=(const long long & number);

    Integer operator/(const Integer & number) const;

    Integer operator/(const long long & number) const;

    inline void operator/=(const Integer & number) {
        operator=(operator/(number));
    }

    inline void operator/=(const long long & number) {
        operator=(operator/(number));
    }

    Integer operator%(const Integer & number) const;

    Integer operator%(const long long & number) const;

    inline void operator%=(const Integer & number) {
        operator=(operator%(number));
    }

    inline void operator%=(const long long & number) {
        operator=(operator%(number));
    }

    // division, store quotient and remainder
    void div(const Integer & dvs, Integer & qtn, Integer & rmd) const;
    void div(long long dvs, Integer & qtn, Integer & rmd) const;


    // print division error
    void err_div_0() const;

    // power function, [n < 10^6]
    //    Integer{2}.pwr(4) = 16
    Integer pwr(const int & n) const;

    // base b representation, [b <= 32]
    //    Integer{16}.in_base(2) = "10000"
    //    Integer{15}.in_base(16) = "E"
    std::string in_base(unsigned int b) const;

    // print base error
    void err_base() const;

    // convert Integer to long long if possible
    long long to_ll() const;

    void err_ll_overflow() const;

    
    virtual void set_val(const long long & number) override;
    virtual void set_val(const std::string & number) override;
    virtual std::string rps() const override;

};

std::istream & operator>>(std::istream & in, Integer & number);
std::ostream & operator<<(std::ostream & out, const Integer & number);
inline std::ostream & operator<<(std::ostream & out, const Integer && number) {
    return out << number;
}


#endif