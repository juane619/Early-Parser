/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Earley.cpp
 * Author: juane
 * 
 * Created on 12 December 2017, 11:32
 */

#include "Earley.h"

Earley::Earley(const Gramatica& g, const string& cad) {
    grammar=g;
    cadena = cad;
}


bool Earley::parse() {
    initialization();
    
    //comprobacion
    for (unsigned i = 0; i < registros.size(); i++)
        for (unsigned j = 0; j < registros[i].size(); j++)
            registros[i][j].imprimir();
    //fin comprobacion
    
    return 1;
}

void Earley::initialization() {
    registros.resize(cadena.size());

    for (unsigned i = 0; i < grammar.getProducciones().size(); i++) {
        if (grammar.getProducciones()[i].parteIzq() == 'S')
            registros[0].push_back(Registro(0, 0, "S", "", grammar.getProducciones()[i].parteDer(), &grammar));
    }
}
