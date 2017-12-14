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
    //GRAMATICA 1 DE PRUEBA
    
//    Produccion p1("S>AB");
//    Produccion p2("S>BC");
//    Produccion p3("A>BA");
//    Produccion p4("A>a");
//    Produccion p5("B>CC");
//    Produccion p6("B>b");
//    Produccion p7("C>AB");
//    Produccion p8("C>a");
//
//    vector<Produccion> prods;
//
//    prods.push_back(p1);
//    prods.push_back(p2);
//    prods.push_back(p3);
//    prods.push_back(p4);
//    prods.push_back(p5);
//    prods.push_back(p6);
//    prods.push_back(p7);
//    prods.push_back(p8);
//
//    Gramatica gram(prods);
//
//    Earley earley1(gram, "baaaba");

    //GRAMATICA 2 DE PRUEBA
    
//    Produccion p1("S>T");
//    Produccion p2("S>S+T");
//    Produccion p3("T>F");
//    Produccion p4("T>T*F");
//    Produccion p5("F>a");
//    Produccion p6("F>b");
//    Produccion p7("F>(S)");
//
//    vector<Produccion> prods;
//
//    prods.push_back(p1);
//    prods.push_back(p2);
//    prods.push_back(p3);
//    prods.push_back(p4);
//    prods.push_back(p5);
//    prods.push_back(p6);
//    prods.push_back(p7);
//
//
//    Gramatica gram(prods);
//        
//    Earley earley1(gram, "(a+b)*a+a*b");
    
    //
    
//    Produccion p1("S>U");
//    Produccion p3("S>V");
//    Produccion p4("U>TaU");
//    Produccion p5("U>TaT");
//    Produccion p6("U>UaT");
//    Produccion p7("V>TbV");
//    Produccion p8("V>TbT");
//    Produccion p9("V>VbT");
//    Produccion p10("T>aTbT");
//    Produccion p11("T>bTaT");
//    Produccion p12("T>z");
//
//    vector<Produccion> prods;
//
//    prods.push_back(p1);
//    prods.push_back(p3);
//    prods.push_back(p4);
//    prods.push_back(p5);
//    prods.push_back(p6);
//    prods.push_back(p7);
//    prods.push_back(p8);
//    prods.push_back(p9);
//    prods.push_back(p10);
//    prods.push_back(p11);
//    prods.push_back(p12);
//
//    Gramatica gram(prods);
//        
//    Earley earley1(gram, "azbzbzbz");
    
//        Produccion p1("S>AA");
//    Produccion p2("A>AAA");
//    Produccion p3("A>a");
//    Produccion p4("A>b");
//
//    vector<Produccion> prods;
//
//    prods.push_back(p1);
//    prods.push_back(p2);
//    prods.push_back(p3);
//    prods.push_back(p4);
//
//    Gramatica gram(prods);
//        
//    Earley earley1(gram, "aaaab");
    
    
    Produccion p2("S>S+M");
    Produccion p3("S>M");
    Produccion p4("M>M*T");
    Produccion p5("M>T");
    Produccion p6("T>2");

    vector<Produccion> prods;

    prods.push_back(p2);
    prods.push_back(p3);
    prods.push_back(p4);
    prods.push_back(p5);
    prods.push_back(p6);

    Gramatica gram(prods);
        
    Earley earley1(gram, "2+2+2");
    
    cout << earley1.parse() << endl;

    return 0;
}

