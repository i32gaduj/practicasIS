/*
 * Citas.h
 *
 *  Created on: 14/08/2015
 *      Author: juanma
 */

#ifndef CITAS_H_
#define CITAS_H_
#include <iostream>
#include <string>

using namespace std;

class Citas {
public:
	Citas();
	virtual ~Citas();

	void setFecha(string fecha);
	string getFecha();

	void setHora(string hora);
	string getHora();

	void setMotivo(string motivo);
	string getMotivo();


private:

	string fecha_;
	string hora_;
	string motivo_;
};

#endif /* CITAS_H_ */
