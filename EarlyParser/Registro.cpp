/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 10:56
 */

#include <string>
#include <iostream>

#include "Registro.h"

Registro::Registro() {
}

Registro::Registro(unsigned i_p, unsigned j_p, const string& A_p, const string& alfa_p, const string& beta_p, Gramatica* grammar_p) {
    i = i_p;
    j = j_p;
    A = A_p;
    alfa = alfa_p;
    beta = beta_p;
    grammar = grammar_p;
}

char Registro::splitVar() {
    char car;
    if (beta.size() > 1) {
        string aux(beta.substr(beta.size() - 2));
        if (grammar->isVar(car = *(aux.end() - 1)))
            return car;
        else
            return *(aux.end() - 2);
    }
    return beta[0];
}

void Registro::imprimir() {
    cout << "(" << i << ", " << j << ", " << A << ", " << alfa << ", " << beta << ")" << endl;  
}


