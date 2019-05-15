#include<iostream>
class Formula {
    public:
    virtual int eval() const = 0;
    virtual void clone(Formula*&) const = 0;
    virtual ~Formula(){}
};

class Id: public Formula {
    int _id;
    public:
    Id(int value): _id(value){}
    int eval() const override{
        return _id;
    }
    void clone(Formula*& target) const override{
        target = new Id(*this);
    }
};

class Sum: public Formula {
    Formula* _lhs;
    Formula* _rhs;
    public:
    Sum(Formula* lhs, Formula* rhs) {
        lhs->clone(_lhs);
        rhs->clone(_rhs);
    }
    int eval() const override{
        return _lhs->eval() + _rhs->eval();
    }
    void clone(Formula*& target) const override {
        target = new Sum(*this);
    }
    ~Sum() {
        delete _lhs;
        delete _rhs;
    }
};

int main() {
    Id i(2);
    // std::cout<<i.eval();
    Formula* t_sum = new Sum(new Id(1), new Id(4));
    std::cout<<t_sum->eval();
    delete t_sum;
}
