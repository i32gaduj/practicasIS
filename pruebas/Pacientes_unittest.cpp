/*
 * pacientes_unittest.cpp
 *
 *  Created on: 13/08/2015
 *      Author: juanma
 */

#include <string>
#include "Pacientes.h"
#include "gtest/gtest.h"

using namespace std;


TEST(Pacientes, setNombreygetNombre) {
  Pacientes c;
  c.setNombre("Pepe");
  EXPECT_EQ("Pepe", c.getNombre());
  c.setNombre("Juan");
  EXPECT_EQ("Juan", c.getNombre());
}

TEST(Pacientes, setApellidosygetApellidos) {
  Pacientes c;
  c.setApellidos("Garcia Dueñas");
  EXPECT_EQ("Garcia Dueñas", c.getApellidos());
}

TEST(Pacientes, setDNIygetDNI) {
  Pacientes c;
  c.setDNI("86786780-J");
  EXPECT_EQ("86786780-J", c.getDNI());
}

TEST(Pacientes, setFechaNacimientoygetFechaNacimiento) {
  Pacientes c;
  c.setFechaNacimiento("20/04/2000");
  EXPECT_EQ("20/04/2000", c.getFechaNacimiento());
}


TEST(Pacientes, setTelefonoygetTelefono) {
  Pacientes c;
  c.setTelefono(678234948);
  EXPECT_EQ(678234948, c.getTelefono());
}
