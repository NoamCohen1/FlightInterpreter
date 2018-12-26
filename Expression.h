#ifndef INTERPRETERFLIGHT_EXPRESSION_H
#define INTERPRETERFLIGHT_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() = default;
};

#endif //INTERPRETERFLIGHT_EXPRESSION_H
