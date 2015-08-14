/*
 * Pacientes.h
 *
 *  Created on: 13/08/2015
 *      Author: juanma
 */

#ifndef PACIENTES_H_
#define PACIENTES_H_
#include <iostream>
#include <string>
using namespace std;

class Pacientes {
public:
	Pacientes();
	virtual ~Pacientes();

	void setNombre(string nombre);
	string getNombre();

	void setApellidos(string apellidos);
	string getApellidos();

	void setDNI(string DNI);
	string getDNI();

	void setFechaNacimiento(string fechaNacimiento);
	string getFechaNacimiento();

	void setTelefono(int telefono);
	int getTelefono();

private:

	string nombre_;
	string apellidos_;
	string DNI_;
	string fechaNacimiento_;
	int telefono_;


};

#endif /* PACIENTES_H_ */
