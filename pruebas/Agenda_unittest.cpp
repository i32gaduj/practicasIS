/*
 * Agenda_unittest.cpp
 *
 *  Created on: 18/08/2015
 *      Author: juanma
 */

#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"
#include "Agenda.h"
#include "Pacientes.h"
#include "Citas.h"



TEST(Agenda, HerenciaPacientes) {

Agenda x;

  x.Pacientes::setNombre("Pedro");
  EXPECT_EQ("Pedro", x.Pacientes::getNombre());
  x.Pacientes::setNombre("Juan");
  EXPECT_EQ("Juan", x.Pacientes::getNombre());
  x.Pacientes::setApellidos("Garcia Dueñas");
  EXPECT_EQ("Garcia Dueñas", x.Pacientes::getApellidos());
  x.Pacientes::setDNI("86786780-J");
  EXPECT_EQ("86786780-J", x.Pacientes::getDNI());
  x.Pacientes::setFechaNacimiento("20/04/2000");
  EXPECT_EQ("20/04/2000", x.Pacientes::getFechaNacimiento());
  x.Pacientes::setTelefono(678234948);
  EXPECT_EQ(678234948, x.Pacientes::getTelefono());

};

TEST(Agenda, HerenciaCitas){

Agenda x;

  x.Citas::setFecha("5/4/2015");
  EXPECT_EQ("5/4/2015", x.Citas::getFecha());
  
  x.Citas::setHora("20:40");
  EXPECT_EQ("20:40", x.Citas::getHora());
  
  x.Citas::setMotivo("Dolor");
  EXPECT_EQ("Dolor", x.Citas::getMotivo());

};



TEST(Agenda, insertarPacientes) {
  
  Agenda x;
  vector<datos>N;
  
  struct datos a,b;
  x.insertarPacientes(a);
  x.insertarPacientes(b);
  
  N=x.Vector();
  EXPECT_EQ(2,N.size());
 
  
}



TEST(Agenda, eliminarPacientes) {
 
  Agenda x;
  vector<datos>N;
  
  struct datos a,b;
  a.DNI="1234567-J";
  
  x.insertarPacientes(a);
  x.insertarPacientes(b);
  
  N=x.Vector();
  EXPECT_EQ(2,N.size());
  
  x.eliminarPacientes("1234567-J");
 
  N=x.Vector();
  EXPECT_EQ(1,N.size());
 
 
}

TEST(Agenda, modificarPacientes) {
  Agenda x;
  vector<datos>N;
  
  struct datos a,b;
  a.DNI="1234567-J";
  
  b.DNI="NUEVO DNI";
  
  x.insertarPacientes(a);

  x.modificarPacientes("1234567-J",b);

  N=x.Vector();
  EXPECT_EQ("NUEVO DNI",N[0].DNI);
}


TEST(Agenda, buscarPaciente){
Agenda x;
struct datos a;

a.nombre="Jose";

x.insertarPacientes(a);

EXPECT_FALSE(x.buscarPaciente("Andres"));  
//EXPECT_TRUE(x.buscarPaciente("Jose"));    Funciona pero imprimiria por pantalla

}

