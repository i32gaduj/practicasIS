/*
 * Citas.cpp
 *
 *  Created on: 14/08/2015
 *      Author: juanma
 */
#include <iostream>
#include "Citas.h"
#include <string>

using namespace std;

Citas::Citas() {
	// TODO Auto-generated constructor stub

}


Citas::~Citas() {
	// TODO Auto-generated destructor stub
}


	void Citas::setFecha(string fecha){

		fecha_=fecha;

	}
	string Citas::getFecha(){

		return fecha_;

	}

	void Citas::setHora(string hora){

		hora_=hora;

	}
	string Citas::getHora(){

		return hora_;

	}

	void Citas::setMotivo(string motivo){

		motivo_=motivo;

	}
	string Citas::getMotivo(){

		return motivo_;

	}



