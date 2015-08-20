/*
 * main.cpp
 *
 *  Created on: 13/08/2015
 *      Author: juanma
 */

#include "Agenda.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){

	int opc;
	struct datos X;
	vector<datos>N;
	unsigned int i;
	int flag2=0;
	int flag3=0;
	int j;
	string nombre,DNI;
	Agenda x;
	x.cargarAgenda();



	do{
	opc=x.menu();


	switch (opc){

		case 1: // insertar



			cout<<"**************Introduce los datos del paciente***************"<<"\n";
			cout<<"-------------------------------------------------------------\n"<<endl;



			cout<<"Introduce el nombre del paciente: ";
			getchar();
			getline(cin,X.nombre,'\n');

			cout<<"Introduce los apellidos del paciente: ";
			getline(cin,X.apellidos,'\n');

			cout<<"Introduce el DNI del paciente: ";
			getline(cin,X.DNI,'\n');


			cout<<"Introduce la fecha de nacimiento del paciente(opcional): ";
			getline(cin,X.fechaN,'\n');

			cout<<"Introduce el teléfono del paciente (solo números.Ej:123456789): ";
			cin>>X.telefono;


			cout<<"Introduce la fecha de la cita: ";
			getchar();
			getline(cin,X.fechaC,'\n');

			cout<<"Introduce la hora de la cita: ";
			getline(cin,X.hora,'\n');

			cout<<"Introduce el motivo de la cita: ";
			getline(cin,X.motivo,'\n');

			cout<<"Comprobando la consistencia de los datos..."<<endl;
			cout<<endl;
			N=x.Vector();
//==============================CONSISTENCIA DE DATOS==========================================

			for(i=0;i<N.size();i++){

				if(N[i].DNI==X.DNI){
					cout<<"EL DNI YA EXISTE... Regresando al menú..."<<endl;
					return main();
				}

			}


			for(i=0;i<N.size();i++){

					if(N[i].nombre==X.nombre && N[i].apellidos==X.apellidos){
					cout<<"Ya existe el paciente "<<X.nombre+" "+X.apellidos<<"... Regresando al menú..."<<endl;
					return main();
				}

			}


			for(i=0;i<N.size();i++){

					if(N[i].fechaC==X.fechaC && N[i].hora==X.hora){
					cout<<"Ya existe una cita a fecha de "<<X.fechaC+" a las "+X.hora<<"... Regresando al menú..."<<endl;
					return main();
				}

			}

			if(X.nombre.length()<3){
					cout<<"El nombre debe contener al menos 3 caracteres"<<endl;
					return main();
			}

			if(X.apellidos.length()<7){
					cout<<"Los apellidos deben contener al menos 7 caracteres"<<endl;
					return main();
			}
			if(X.DNI.length()<9){
					cout<<"El DNI debe contener al menos 9 caracteres... EJ: 01234567J o 80963575-L"<<endl;
					return main();
			}

			if(X.fechaC.length()<3){
					cout<<"La fecha demasiado corta... EJ: 10/10/2015"<<endl;
					return main();
			}

			if(X.hora.length()<1){
					cout<<"No has introducido la hora..."<<endl;
					return main();
			}

			if(X.motivo.length()<1){
					cout<<"No has introducido el motivo..."<<endl;
					return main();
			}

			//Funcion insertar
			x.insertarPacientes(X);
			cout<<"\n\n¡¡El paciente ha sido insertado con EXITO!!\n\n";

		break;

		case 2:	// modificar

			cout<<"Introduce el DNI del paciente a modificar: "<<endl;
			getchar();
			getline(cin,DNI,'\n');
			N=x.Vector();



			for(i=0;i<N.size();i++){

				if(N[i].DNI==DNI){
				cout<<"\nDNI introducido correctamente...\n";


				cout<<"**************Introduce los nuevos datos del paciente***************"<<"\n";
				cout<<"-------------------------------------------------------------\n"<<endl;



					cout<<"Introduce el nombre del paciente: ";
					getline(cin,X.nombre,'\n');

					cout<<"Introduce los apellidos del paciente: ";
					getline(cin,X.apellidos,'\n');

					cout<<"Introduce el DNI del paciente: ";
					getline(cin,X.DNI,'\n');

					cout<<"Introduce la fecha de nacimiento del paciente: ";
					getline(cin,X.fechaN,'\n');

					cout<<"Introduce el teléfono del paciente: ";
					cin>>X.telefono;

					cout<<"Introduce la fecha de la cita: ";
					getchar();
					getline(cin,X.fechaC,'\n');

					cout<<"Introduce la hora de la cita: ";
					getline(cin,X.hora,'\n');

					cout<<"Introduce el motivo de la cita: ";
					getline(cin,X.motivo,'\n');


				}
			}

			//FUNCION MODIFICAR
			x.modificarPacientes(DNI,X);

			for(i=0;i<N.size();i++){

				if(N[i].DNI==DNI){
					cout<<"\n       ¡El paciente ha sido modificado con EXITO!\n\n";
					flag2=1;
					}

				}
				if(flag2==0){
							cout<<"\n\nEl DNI: '"<<DNI<<"' es inexistente, no se puede modificar\n\n";
				}

		break;

		case 3://eliminar


			cout<<"Introduce el DNI del paciente a borrar: "<<endl;
			getchar();
			getline(cin,DNI,'\n');
			cout<<"\nDNI introducido correctamente...\n";
			N=x.Vector();
			//FUNCION ELIMINAR
			x.eliminarPacientes(DNI);

			for(i=0;i<N.size();i++){

					if(N[i].DNI==DNI){
						cout<<"\n       ¡El paciente ha sido borrado con EXITO!\n\n";
						flag3=1;
					}

			}
			if(flag3==0){
				cout<<"\n\nEl DNI: '"<<DNI<<"' es inexistente, no se puede borrar\n\n";
			}


		break;

		case 4://buscar

			cout<<"Introduce el nombre del paciente/s a buscar: "<<endl;
			getchar();
			getline(cin,nombre,'\n');
			cout<<"========== Datos pacientes con nombre '"<<nombre<<"' ==========="<<"\n\n";
			//FUNCIONBUSCAR
			j=x.buscarPaciente(nombre);
			if(j==0){
				cout <<"No se encontraron coincidencias para este nombre"<<endl;

			}





		break;

		case 5://listar
			//FUNCIONLISTAR
			x.listarPacientes();

		break;


		case 6://SALIR
			cout<<"Saliendo del programa..."<<"\n";
		break;

		default:
		cout<<"\n\n¡¡LA OPCION ELEGIDA NO ES VÁLIDA!!"<<"\n\n";

		}

	}while(opc!=6);

}
