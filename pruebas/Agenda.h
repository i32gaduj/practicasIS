/*
 * Agenda.h
 *
 *  Created on: 15/08/2015
 *      Author: juanma
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include "Citas.h"
#include "Pacientes.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct datos{

	string nombre;
	string apellidos;
	string DNI;
	string fechaN;
	int telefono;
	string fechaC;
	string hora;
	string motivo;

};

class Agenda: public Citas, public Pacientes{
public:
	
	
	Agenda();
	virtual ~Agenda();

	int menu();
	void insertarPacientes(struct datos X);
	void modificarPacientes(string DNI,struct datos X);
	void eliminarPacientes(string DNI);
	int buscarPaciente(string nombre);
	void listarPacientes();

	//Funciones de persistencia
	void cargarAgenda();
	void guardarPacientesVector();

	//Funcion que devuelve el tamaño del vector(necesaria para los test)
	vector <datos> Vector();


private:
	vector <datos> v;

};

#endif /* AGENDA_H_ */
