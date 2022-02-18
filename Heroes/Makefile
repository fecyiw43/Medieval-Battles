# Course: Object Oriented Programming
# Group Project #x
# Author: Frank
# Student ID: A1803982
# Description: makefile for the game


# runs the entire program
# default running target
box: All

# main is made by using all object files previously created
All: Main.o Functions.o Character.o Wizard.o Warrior.o Dragon.o Sphynx.o item.o Consumables.o
	g++ -o test Main.o Functions.o Character.o Wizard.o Warrior.o Dragon.o Sphynx.o item.o Consumables.o
	bash TESTING_OBJECT
	bash TESTING_MAIN
	bash TESTING_BOUNDARY

# The main file needs to be recompiled if Action_box.cpp changes
Main.o: Action_box.cpp Functions.cpp Character.h Wizard.h Warrior.h Dragon.h Sphynx.h item.h Consumables.h
	g++ -c Action_box.cpp -o Main.o


# The function file needs to be recompiled if function.cpp changes
Functions.o: Functions.cpp
	g++ -c Functions.cpp -o Functions.o


# The Character object file needs to be recompiled if Character.cpp or Character.h changes
Character.o: Character.cpp Wizard.o Warrior.o Dragon.o Sphynx.o
	g++ -c Character.cpp -o Character.o


# The Wizard object file needs to be recompiled if Wizard.cpp or Wizard.h changes
Wizard.o: Wizard.cpp Wizard.h
	g++ -c Wizard.cpp -o Wizard.o


# The Warrior object file needs to be recompiled if Warrior.cpp or Warrior.h changes
Warrior.o: Warrior.cpp Warrior.h
	g++ -c Warrior.cpp -o Warrior.o


# The Dragon object file needs to be recompiled if Dragon.cpp or Dragon.h changes
Dragon.o: Dragon.cpp Dragon.h
	g++ -c Dragon.cpp -o Dragon.o


# The Sphynx object file needs to be recompiled if Sphynx.cpp or Sphynx.h changes
Sphynx.o: Sphynx.cpp Sphynx.h
	g++ -c Sphynx.cpp -o Sphynx.o


# The item object file needs to be recompiled if item.cpp or item.h changes
item.o: item.cpp item.h
	g++ -c item.cpp -o item.o


# The Consumables object file needs to be recompiled if Consumables.cpp or Consumables.h changes
Consumables.o: Consumables.cpp Consumables.h
	g++ -c Consumables.cpp -o Consumables.o


# clean removes all object files along with the compiled executable
clean:
	rm -f *.o test
