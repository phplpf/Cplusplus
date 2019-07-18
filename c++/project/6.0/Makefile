a.out:Employee.o main.o Technician.o Manager.o
	g++ -g $^ -o a.out
Employee.o:Employee.cpp
	g++ -g -c Employee.cpp
main.o:main.cpp
	g++ -g -c main.cpp
Technician.o:Technician.cpp
	g++ -g -c Technician.cpp
Manager.o:Manager.cpp
	g++ -g -c Manager.cpp
clean:
	rm *.o a.out
distclean:
	rm *.o a.out 100* id.txt count.txt




