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


    for (auto ite = grammar.getVariables()->begin(); ite != grammar.getVariables()->end(); ++ite) {
        check_var.insert(std::make_pair(*ite, false));
    }

}

bool Earley::parse() {
    initialization();

    do {
        clausure();

        for (auto it = check_var.begin(); it != check_var.end(); it++) {
            if (it->first != 'S')
                it->second = false;
        }

        advance();
        j++;
        termination();
        i++;
        cout << "Comprobacion: " << endl;
        comprobar();
    } while (j < cadena.size());

    return 1;
}

void Earley::initialization() {
    registros.resize(cadena.size() + 1);

    for (unsigned i = 0; i < grammar.getProducciones().size(); i++) {
        if (grammar.getProducciones()[i].parteIzq() == 'S')
            registros[0].push_back(Registro(0, 0, "S", "", grammar.getProducciones()[i].parteDer(), &grammar));
    }

    check_var.find('S')->second = true;
}

void Earley::clausure() {
    while (1) {
        char split_var;
        unsigned tamanio = registros[j].size();
        string aux;
        for (unsigned k = 0; k < tamanio; k++) {
            split_var = registros[j][k].splitVar();
            if (split_var != 'e' && check_var.find(split_var)->second == false) {
                aux = split_var;

                for (Produccion& prod : grammar.getProducciones())
                    if (prod.parteIzq() == split_var) {
                        registros[j].push_back(Registro(j, j, aux, "", prod.parteDer(), &grammar));
                        check_var.find(split_var)->second = true;
                    }
            }
        }

        auto it = check_var.begin();
        for (; it != check_var.end() && it->second == true; ++it)
            ;
        if (it == check_var.end())
            return;

        it = check_var.begin();
    }
}

void Earley::advance() {
    char split_ter;
    string aux;

    for (unsigned k = 0; k < registros[j].size(); k++) {
        if (registros[j][k].getI() == i) {
            split_ter = registros[j][k].splitTer();
            if (split_ter != 'e' && split_ter == cadena[j]) {
                aux = split_ter;
                string beta_aux = registros[j][k].getBeta();
                beta_aux.erase(beta_aux.begin());
                registros[j + 1].push_back(Registro(i, j + 1, registros[j][k].getA(), registros[j][k].getAlfa() + aux, beta_aux, &grammar));
            }
        }
    }
}

void Earley::termination() {

    for (unsigned h = 0; h <= i; h++) { //h
        for (unsigned k = 0; k < registros[i].size(); k++) { //registros i
            if (registros[i][k].getI() == i) {
                for (unsigned l = 0; l < registros[j].size(); l++) { //registros j
                    char char_split_var;
                    string aux_split_var;

                    char_split_var = registros[i][k].splitVar();
                    aux_split_var = char_split_var;

                    if (registros[j][l].getJ() == j && aux_split_var == registros[j][l].getA() && registros[j][l].getBeta().empty()) {
                        string beta_aux = registros[i][k].getBeta();
                        beta_aux.erase(beta_aux.begin());
                        registros[j].push_back(Registro(h, j, registros[i][k].getA(), registros[i][k].getAlfa() + registros[j][l].getA(), beta_aux, &grammar));
                    }
                }
            }
        }
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

