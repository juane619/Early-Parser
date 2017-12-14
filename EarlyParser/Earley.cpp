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
    grammar = g;
    cadena = cad;


    for (auto ite = grammar.getVariables()->begin(); ite != grammar.getVariables()->end(); ++ite){
        check_var.insert(std::make_pair(*ite, false));
    }
    

}

bool Earley::parse() {
    initialization();
    cout << "init" << endl;
    comprobar();

    clausure();
    cout << "clausura" << endl;
    comprobar();


    return 1;
}

void Earley::initialization() {
    registros.resize(cadena.size() + 1);

    for (unsigned i = 0; i < grammar.getProducciones().size(); i++) {
        if (grammar.getProducciones()[i].parteIzq() == 'S')
            registros[0].push_back(Registro(0, 0, "S", "", grammar.getProducciones()[i].parteDer(), &grammar));
    }
    
    check_var.find('S')->second=true;
}

void Earley::clausure() {
    while (1) {
        char split_var;
        unsigned tamanio = registros[j].size();
        string aux;
        for (unsigned i = 0; i < tamanio; i++) {
            split_var = registros[j][i].splitVar();
            if (split_var != 'e' && check_var.find(split_var)->second == false) {
                aux = split_var;

                for (Produccion& prod : grammar.getProducciones())
                    if (prod.parteIzq() == split_var){
                        registros[j].push_back(Registro(j, j, aux, "", prod.parteDer(), &grammar));
                        check_var.find(split_var)->second=true;
                    }
            }
        }

        for (auto it = check_var.begin(); it != check_var.end() ; ++it)
            cout << it->first << " " << it->second << endl;
        
        auto it = check_var.begin();
        for (; it != check_var.end() && it->second == true; ++it)
            ;
        if (it == check_var.end())
            return;

        it = check_var.begin();
    }
}

void Earley::comprobar() {
    //comprobacion
    for (unsigned i = 0; i < registros.size(); i++) {
        cout << "j: " << i << "\n";
        for (unsigned j = 0; j < registros[i].size(); j++)
            registros[i][j].imprimir();
    }
    //fin comprobacion
}

