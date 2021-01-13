//
// Created by carson on 9/17/20.
//

#ifndef INC_366_DEMOS_CPPDEMO_H
#define INC_366_DEMOS_CPPDEMO_H

class CPPDemo {
public:
    void doIt();
    unsigned long long int addrOfCalled();
private:
    int _called = 0;
};

class ConstructorDemo {
public:
    ConstructorDemo(int);
    ~ConstructorDemo();
private:
    int i = 0;
    char * buffer;
};

#endif //INC_366_DEMOS_CPPDEMO_H
