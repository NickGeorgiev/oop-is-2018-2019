#include<iostream>

template<class T>
struct FormulaValue {
    T data;
    FormulaValue(const T& _data): data(_data) {}
    const T value() const {
        return data;
    }
};

template<class T>
class Cloneable {
    public:
    virtual void clone(T*&) const = 0;
};

class Formula: public Cloneable<Formula> {
    public:
    virtual FormulaValue<int> eval() const = 0;
    virtual ~Formula(){}
};

template<class T>
class Id: public Formula {
    int _id;
    public:
    Id(int value): _id(value){}
    FormulaValue<T> eval() const override{
        return FormulaValue<T>(_id);
    }
    void clone(Formula*& target) const override{
        target = new Id(*this);
    }
};

template<class T>
class Sum: public Formula {
    Formula* _lhs;
    Formula* _rhs;
    public:
    Sum(Formula* lhs, Formula* rhs) {
        lhs->clone(_lhs);
        rhs->clone(_rhs);
    }
    FormulaValue<T> eval() const override {
        return FormulaValue<T> (_lhs->eval().value() + _rhs->eval().value());
    }
    void clone(Formula*& target) const override {
        target = new Sum(*this);
    }
    ~Sum() {
        delete _lhs;
        delete _rhs;
    }
};

template<class T>
class Diff: public Formula {
    Formula* _lhs;
    Formula* _rhs;
    public:
    Diff(Formula* lhs, Formula* rhs) {
        lhs->clone(_lhs);
        rhs->clone(_rhs);
    }
    FormulaValue<T> eval() const override {
        return FormulaValue<T> (_lhs->eval().value() - _rhs->eval().value());
    }
    void clone(Formula*& target) const override {
        target = new Diff(*this);
    }
    ~Diff() {
        delete _lhs;
        delete _rhs;
    }
};

int main() {
    Id<int> i(2);
    // std::cout<<i.eval();
    // expr = ((1 + 2) + ((2 - 3) + 1))
    Formula* t_sum = new Sum<int>(
        new Sum<int>(new Id<int>(1), new Id<int>(2)),
        new Sum<int>(
            new Diff<int>(
                new Id<int>(2),
                new Id<int>(3)
            ),
            new Id<int>(1)
        )
    );
    std::cout<<t_sum->eval().value();
    delete t_sum;
}
