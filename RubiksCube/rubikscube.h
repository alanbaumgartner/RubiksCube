// Copyright 2019 Alan Victor Baumgartner

#pragma once

#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <string>
#include <unordered_map>
#include "common.h"
#include "cube.h"
#include "ui_rubikscube.h"

class RubiksCube : public QMainWindow
{
	Q_OBJECT

public:
	RubiksCube(QWidget *parent = Q_NULLPTR);

private:
	Ui::RubiksCubeClass ui;

	Cube* cube;
	QPushButton* buttons[50];
	QLabel* sides[54];

	void rotate_cube(int index);
	void reset_cube();
	void randomize_cube();
	void update_cube();
	void set_color(int index, char color);
};
