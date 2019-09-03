// Copyright 2019 Alan Victor Baumgartner

#include "rubikscube.h"
#include <QtWidgets/QApplication>
#include "cube.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RubiksCube w;
	w.resize(567, 198);
	w.setWindowTitle("Rubiks Cube");
	w.show();
	return a.exec();
}
