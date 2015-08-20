CXX = g++
CXXFLAGS = --std=c++11
DEBUG = -g

Agenda: Agenda.o Citas.o Pacientes.o
	
	$(CXX) $^ main.cpp -o $@ $(CXXFLAGS)
	chmod +x Agenda
	rm *.o
	

Agenda.o: Agenda.cpp
	$(CXX) $^ -c $(CXXFLAGS)

Pacientes.o: Pacientes.cpp
	$(CXX) $^ -c $(CXXFLAGS)

Citas.o: Citas.cpp
	$(CXX) $^ -c $(CXXFLAGS)

	


clean:
	rm *.o
	@echo "Borrados todos los ficheros objeto (*.o)"
