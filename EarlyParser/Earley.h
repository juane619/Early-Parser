/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Earley.h
 * Author: juane
 *
 * Created on 12 December 2017, 11:32
 */

#ifndef EARLEY_H
#define EARLEY_H

#include <string>
#include <vector>
#include "Gramatica.h"
#include "Registro.h"

using namespace std;

class Earley {
public:
    Earley(const Gramatica& g, const string& cad);
    
    bool parse();
private:
    Gramatica grammar;
    string cadena;
    vector<vector<Registro> > registros;
    
    unsigned j=0;
    unsigned h=0;
    unsigned i=0;
    
    void initialization();
    void clausure();
    void advance();
    void termination();
};

#endif /* EARLEY_H */

