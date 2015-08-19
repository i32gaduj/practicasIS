/*
 * Agenda.cpp
 *
 *  Created on: 15/08/2015
 *      Author: juanma
 */

#include "Agenda.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>


Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
	// TODO Auto-generated destructor stub
}


int Agenda::menu(){					//Imprime por pantalla las opciones del programa

int opc;

	cout <<"********************  MENÚ  ******************\n\n"<<endl;
	cout <<"1-Insertar paciente"<<endl;
	cout <<"2-Modificar paciente"<<endl;
	cout <<"3-Eliminar paciente"<<endl;
	cout <<"4-Buscar pacientes"<<endl;
	cout <<"5-Listar pacientes y citas"<<endl;
	cout <<"6-Salir del programa\n"<<endl;

		cout<<"Opción: ";
		cin>>opc;

	return opc;
}

void Agenda::insertarPacientes(struct datos X){ //Mete los datos del argumento en el vector y
												//guarda la informacion en el fichero



	v.push_back(X);
	guardarPacientesVector();


}



void Agenda::listarPacientes(){		//Recorre el fichero mostrando los datos de los pacientes
	string s;
	int n;

	ifstream f;
	f.open("Fichero_datos", ios::in);


	cout<<"==================== Datos pacientes ==================="<<"\n\n";

	while(getline(f,s,'\n')){
	setNombre(s);
	cout<<"		Nombre: "<<getNombre()<<"\n";


	getline(f,s,'\n');
	setApellidos(s);
	cout<<"		Apellidos: "<<getApellidos()<<"\n";


	getline(f,s,'\n');
	setDNI(s);
	cout<<"		DNI:"<<getDNI()<<"\n";


	getline(f,s,'\n');
	setFechaNacimiento(s);
	cout<<"		Fecha de nacimiento: "<<getFechaNacimiento()<<"\n";


	getline(f,s,'\n');
	n=atoi(s.c_str());
	setTelefono(n);
	cout<<"		Telefono: "<<getTelefono()<<"\n";

	cout<<endl;
	cout<<"- - - Cita del paciente "<<getNombre()+" "+getApellidos()+" - - -"<<endl;
	cout<<endl;

	getline(f,s,'\n');
	setFecha(s);
	cout<<"		Fecha de la cita: "<<getFecha()<<"\n";


	getline(f,s,'\n');
	setHora(s);
	cout<<"		Hora de la cita: "<<getHora()<<"\n";


	getline(f,s,'\n');
	setMotivo(s);
	cout<<"		Motivo de la cita: "<<getMotivo()<<"\n\n";
	cout<<"========================================================="<<endl;
	}

}



int Agenda::buscarPaciente(string nombre){ //Muestra los pacientes que tengan el nombre 'z'

	string s;
		int n;
		int flag4=0;

		ifstream f;
		f.open("Fichero_datos", ios::in);





		while(getline(f,s,'\n')){
		setNombre(s);

		getline(f,s,'\n');
		setApellidos(s);

		getline(f,s,'\n');
		setDNI(s);

		getline(f,s,'\n');
		setFechaNacimiento(s);

		getline(f,s,'\n');
		n=atoi(s.c_str());
		setTelefono(n);

		getline(f,s,'\n');
		setFecha(s);

		getline(f,s,'\n');
		setHora(s);

		getline(f,s,'\n');
		setMotivo(s);


		if(nombre==getNombre()){

			cout<<"		Nombre: "<<getNombre()<<"\n";
			cout<<"		Apellidos: "<<getApellidos()<<"\n";
			cout<<"		DNI:"<<getDNI()<<"\n";
			cout<<"		Fecha de nacimiento: "<<getFechaNacimiento()<<"\n";
			cout<<"		Telefono: "<<getTelefono()<<"\n";
			cout<<endl;
			cout<<"- - - Cita del paciente "<<getNombre()+" "+getApellidos()+" - - -"<<endl;
			cout<<endl;
			cout<<"		Fecha de la cita: "<<getFecha()<<"\n";
			cout<<"		Hora de la cita: "<<getHora()<<"\n";
			cout<<"		Motivo de la cita: "<<getMotivo()<<"\n\n";
			cout<<"========================================================="<<endl;

			flag4=1;
		}


	}
		return flag4;
}

void Agenda::eliminarPacientes(string DNI){ //Elimina del vector y del fichero al paciente con DNI 'X'
unsigned int i;


for(i=0;i<v.size();i++){

	if(v[i].DNI==DNI){
	v.erase(v.begin() + i);
	guardarPacientesVector();
	}

}



}




void Agenda::modificarPacientes(string DNI,struct datos X){ //Modifica los datos de un paciente 'X'
															//por los de un paciente 'Y'
unsigned int i;


	for(i=0;i<v.size();i++){

		if(v[i].DNI==DNI){
		v[i]=X;
		guardarPacientesVector();
		}

	}



}

void Agenda::guardarPacientesVector(){ //Recorre el vector y vuelca cada campo al fichero.

unsigned int i;

ofstream fichero("Fichero_datos",ios::trunc);




	for(i=0;i<v.size();i++){

		fichero<<v[i].nombre<<"\n";
		fichero<<v[i].apellidos<<"\n";
		fichero<<v[i].DNI<<"\n";
		fichero<<v[i].fechaN<<"\n";
		fichero<<v[i].telefono<<"\n";
		fichero<<v[i].fechaC<<"\n";
		fichero<<v[i].hora<<"\n";
		fichero<<v[i].motivo<<"\n";


	}

fichero.close();

}

void Agenda::cargarAgenda(){				//Lee el contenido del fichero y lo mete en el vector


string s;
struct datos N;


cout<<"\nCargando agenda..."<<"\n\n";

ifstream f;
f.open("Fichero_datos", ios::in);


	while(getline(f,s,'\n')){
			N.nombre=s;

			getline(f,s,'\n');
			N.apellidos=s;

			getline(f,s,'\n');
			N.DNI=s;

			getline(f,s,'\n');
			N.fechaN=s;

			getline(f,s,'\n');
			N.telefono=atoi(s.c_str());

			getline(f,s,'\n');
			N.fechaC=s;

			getline(f,s,'\n');
			N.hora=s;

			getline(f,s,'\n');
			N.motivo=s;

	v.push_back(N);
	}


f.close();
}


vector <datos> Agenda::Vector(){ 			//Obtiene los datos del vector que esta en la parte
											//y los vuelca a otro vector, que se podrá usar en
	vector <datos> x;						//el main.cpp y los tests
	x=v;

return x;
}
