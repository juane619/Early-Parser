/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juane
 *
 * Created on 12 December 2017, 10:32
 */

#include <cstdlib>
#include <iostream>

#include "Earley.h"

using namespace std;

int main(int argc, char** argv) {
    Produccion p1("S>AB");
    Produccion p2("S>BC");
    Produccion p3("A>BA");
    Produccion p4("A>a");
    Produccion p5("B>CC");
    Produccion p6("B>b");
    Produccion p7("C>AB");
    Produccion p8("C>a");

    vector<Produccion> prods;

    prods.push_back(p1);
    prods.push_back(p2);
    prods.push_back(p3);
    prods.push_back(p4);
    prods.push_back(p5);
    prods.push_back(p6);
    prods.push_back(p7);
    prods.push_back(p8);


    Gramatica gram(prods);

    for (unsigned i = 0; i < gram.getProducciones().size(); i++)
        gram.getProducciones()[i].imprimir();

    Earley earley1(gram, "baa");

    earley1.parse();

    return 0;
}

