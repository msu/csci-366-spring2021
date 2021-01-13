//
// Created by carson on 9/17/20.
//
#include <iostream>
using namespace std;

#include "CPPDemo.h"

void CPPDemo::doIt() {
    cout << "Did it... " << _called++ << "\n";
}

unsigned long long CPPDemo::addrOfCalled() {
    return reinterpret_cast<unsigned long long>(&_called);
}

void stack_object_demo() {
    CPPDemo demo = CPPDemo();
    demo.doIt();
    demo.doIt();
    demo.doIt();
    cout << "Addr of demo: " << reinterpret_cast<unsigned long long>(&demo) << "\n";
    cout << "Addr of called: " << demo.addrOfCalled() << "\n";
}

void new_object_demo() {
    CPPDemo * demo = new CPPDemo();
    demo->doIt();
    demo->doIt();
    demo->doIt();
    cout << "Addr of demo: " << reinterpret_cast<unsigned long long>(demo) << std::endl;
    cout << "Addr of called: " << demo->addrOfCalled() << "\n";
}

void constructor_demo(){
    ConstructorDemo demo = ConstructorDemo(10);
    ConstructorDemo * demo2 = new ConstructorDemo(100);
    // leak?
}

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void write_to_file() {
    // Try to open file.
    std::ofstream file("example.txt");

    if (!file.is_open()) {
        throw std::runtime_error("unable to open file");
    }

    // Write |message| to |file|.
    file << "C++ isn't that bad..." << "\n";
}

int main() {
    constructor_demo();
}

ConstructorDemo::ConstructorDemo(int pi) {
    this->i = pi;
    cout << "Constructing a ConstructorDemo " << i << "\n";
    buffer = static_cast<char *>(malloc(i));
}

ConstructorDemo::~ConstructorDemo() {
    cout << "Destructing a ConstructorDemo " << i << "\n";
    free(buffer);
}

