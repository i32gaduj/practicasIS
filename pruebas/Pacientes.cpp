/*
 * Pacientes.cpp
 *
 *  Created on: 13/08/2015
 *      Author: juanma
 */

#include "Pacientes.h"
#include <iostream>
#include <string>
using namespace std;

Pacientes::Pacientes() {
	// TODO Auto-generated constructor stub

}


	void Pacientes::setNombre(string nombre){

		nombre_=nombre;

	}
	string Pacientes::getNombre(){

		return nombre_;

	}

	void Pacientes::setApellidos(string apellidos){

		apellidos_=apellidos;

	}
	string Pacientes::getApellidos(){

		return apellidos_;

	}

	void Pacientes::setDNI(string DNI){

		DNI_=DNI;

	}
	string Pacientes::getDNI(){

		return DNI_;

	}

	void Pacientes::setFechaNacimiento(string fechaNacimiento){

		fechaNacimiento_=fechaNacimiento;

	}
	string Pacientes::getFechaNacimiento(){

		return fechaNacimiento_;

	}

	void Pacientes::setTelefono(int telefono){

		telefono_=telefono;

	}
	int Pacientes::getTelefono(){

		return telefono_;

	}

Pacientes::~Pacientes() {
	// TODO Auto-generated destructor stub
}

