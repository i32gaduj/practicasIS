/*
 * Citas_unittest.cpp
 *
 *  Created on: 14/08/2015
 *      Author: juanma
 */

#include <string>
#include "Citas.h"
#include "gtest/gtest.h"
using namespace std;


TEST(Citas, setFechaygetFecha) {
  Citas c;
  c.setFecha("20/6/2000");
  EXPECT_EQ("20/6/2000", c.getFecha());
  c.setFecha("7/7/7");
  EXPECT_EQ("7/7/7", c.getFecha());
}

TEST(Citas, setHoraygetHora) {
  Citas c;
  c.setHora("20:40");
  EXPECT_EQ("20:40", c.getHora());
}

TEST(Citas, setMotivoygetMotivo) {
  Citas c;
  c.setMotivo("Dolores y fiebre");
  EXPECT_EQ("Dolores y fiebre", c.getMotivo());
}


