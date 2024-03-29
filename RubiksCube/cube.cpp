// Copyright 2019 Alan Victor Baumgartner

#include "common.h"
#include "cube.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Cube::Cube() {
	SetupPieces();

	srand(time(nullptr));

	func_ptr funcs[36] = {
	  &Cube::U,  &Cube::D,  &Cube::L , &Cube::R,  &Cube::F,  &Cube::B,
	  &Cube::UI, &Cube::DI, &Cube::LI, &Cube::RI, &Cube::FI, &Cube::BI,
	  &Cube::u,  &Cube::d,  &Cube::l,  &Cube::r,  &Cube::f,  &Cube::b,
	  &Cube::ui, &Cube::di, &Cube::li, &Cube::ri, &Cube::fi, &Cube::bi,
	  &Cube::M,  &Cube::MI, &Cube::E,  &Cube::EI, &Cube::S,  &Cube::SI,
	  &Cube::X,  &Cube::XI, &Cube::Y,  &Cube::YI, &Cube::Z,  &Cube::ZI,
	};

	for (int i = 0; i < 36; i++) {
		func_list_[i] = funcs[i];
	}
}

Cube::~Cube() {
	for (int i = 0; i < 26; i++) {
		pieces_[i].reset();
	}
}

void Cube::U() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&UP)) {
			pieces_[i]->rotate(&ROTATE_Y_CW, &ROTATE_COLOR_Y);
		}
	}
}

void Cube::D() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&DOWN)) {
			pieces_[i]->rotate(&ROTATE_Y_CC, &ROTATE_COLOR_Y);
		}
	}
}

void Cube::L() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&LEFT)) {
			pieces_[i]->rotate(&ROTATE_X_CW, &ROTATE_COLOR_X);
		}
	}
}

void Cube::R() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&RIGHT)) {
			pieces_[i]->rotate(&ROTATE_X_CC, &ROTATE_COLOR_X);
		}
	}
}

void Cube::F() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&FRONT)) {
			pieces_[i]->rotate(&ROTATE_Z_CW, &ROTATE_COLOR_Z);
		}
	}
}

void Cube::B() {
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(&BACK)) {
			pieces_[i]->rotate(&ROTATE_Z_CC, &ROTATE_COLOR_Z);
		}
	}
}

void Cube::U2() {
	U();
	U();
}

void Cube::D2() {
	D();
	D();
}

void Cube::L2() {
	L();
	L();
}

void Cube::R2() {
	R();
	R();
}

void Cube::F2() {
	F();
	F();
}

void Cube::B2() {
	B();
	B();
}

void Cube::UI() {
	U();
	U();
	U();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(UP)) {
	//     pieces_[i]->Rotate(ROTATE_Y_CC);
	//   }
	// }
}

void Cube::DI() {
	D();
	D();
	D();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(DOWN)) {
	//     pieces_[i]->Rotate(ROTATE_Y_CW);
	//   }
	// }
}

void Cube::LI() {
	L();
	L();
	L();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(LEFT)) {
	//     pieces_[i]->Rotate(ROTATE_X_CC);
	//   }
	// }
}

void Cube::RI() {
	R();
	R();
	R();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(RIGHT)) {
	//     pieces_[i]->Rotate(ROTATE_X_CW);
	//   }
	// }
}

void Cube::FI() {
	F();
	F();
	F();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(FRONT)) {
	//     pieces_[i]->Rotate(ROTATE_Z_CC);
	//   }
	// }
}

void Cube::BI() {
	B();
	B();
	B();
	// for (int i = 0; i < 26; i++) {
	//   if (pieces_[i]->InPlane(BACK)) {
	//     pieces_[i]->Rotate(ROTATE_Z_CW);
	//   }
	// }
}

void Cube::u() {
	U();
	EI();
}

void Cube::d() {
	D();
	E();
}

void Cube::l() {
	L();
	M();
}

void Cube::r() {
	R();
	MI();
}

void Cube::f() {
	F();
	S();
}

void Cube::b() {
	B();
	SI();
}

void Cube::u2() {
	U2();
	EI();
	EI();
}

void Cube::d2() {
	D2();
	E();
	E();
}

void Cube::l2() {
	L2();
	M();
	M();
}

void Cube::r2() {
	R2();
	MI();
	MI();
}

void Cube::f2() {
	F2();
	S();
	S();
}

void Cube::b2() {
	B2();
	SI();
	SI();
}

void Cube::ui() {
	UI();
	E();
}

void Cube::di() {
	D();
	EI();
}

void Cube::li() {
	LI();
	MI();
}

void Cube::ri() {
	RI();
	M();
}

void Cube::fi() {
	FI();
	SI();
}

void Cube::bi() {
	BI();
	S();
}

void Cube::M() {
	LI();
	R();
	XI();
}

void Cube::MI() {
	M();
	M();
	M();
	// L();
	// RI();
	// X();
}

void Cube::E() {
	DI();
	U();
	YI();
}

void Cube::EI() {
	E();
	E();
	E();
	// D();
	// UI();
	// Y();
}

void Cube::S() {
	FI();
	B();
	Z();
}

void Cube::SI() {
	S();
	S();
	S();
	// F();
	// BI();
	// ZI();
}

void Cube::X() {
	for (int i = 0; i < 26; i++) {
		pieces_[i]->rotate(&ROTATE_X_CC, &ROTATE_COLOR_X);
	}
}

void Cube::XI() {
	X();
	X();
	X();
	// for (int i = 0; i < 26; i++) {
	//     pieces_[i]->Rotate(ROTATE_X_CW);
	// }
}

void Cube::Y() {
	for (int i = 0; i < 26; i++) {
		pieces_[i]->rotate(&ROTATE_Y_CW, &ROTATE_COLOR_Y);
	}
}

void Cube::YI() {
	Y();
	Y();
	Y();
	// for (int i = 0; i < 26; i++) {
	//     pieces_[i]->Rotate(ROTATE_Y_CC);
	// }
}

void Cube::Z() {
	for (int i = 0; i < 26; i++) {
		pieces_[i]->rotate(&ROTATE_Z_CW, &ROTATE_COLOR_Z);
	}
}

void Cube::ZI() {
	Z();
	Z();
	Z();
	// for (int i = 0; i < 26; i++) {
	//     pieces_[i]->Rotate(ROTATE_Z_CC);
	// }
}

std::string Cube::translateInt(int i) {
	switch (i) {
	case 0:
		return "U";
	case 1:
		return "D";
	case 2:
		return "L";
	case 3:
		return "R";
	case 4:
		return "F";
	case 5:
		return "B";
	case 6:
		return "UI";
	case 7:
		return "DI";
	case 8:
		return "LI";
	case 9:
		return "RI";
	case 10:
		return "FI";
	case 11:
		return "BI";
	case 12:
		return "u";
	case 13:
		return "d";
	case 14:
		return "l";
	case 15:
		return "r";
	case 16:
		return "f";
	case 17:
		return "b";
	case 18:
		return "ui";
	case 19:
		return "di";
	case 20:
		return "li";
	case 21:
		return "ri";
	case 22:
		return "fi";
	case 23:
		return "bi";
	case 24:
		return "M";
	case 25:
		return "MI";
	case 26:
		return "E";
	case 27:
		return "EI";
	case 28:
		return "S";
	case 29:
		return "SI";
	case 30:
		return "X";
	case 31:
		return "XI";
	case 32:
		return "Y";
	case 33:
		return "YI";
	case 34:
		return "Z";
	case 35:
		return "ZI";
	}
}

int Cube::translateChar(char c) {
	switch (c) {
	case 'U':
		return 0;
	case 'D':
		return 1;
	case 'L':
		return 2;
	case 'R':
		return 3;
	case 'F':
		return 4;
	case 'B':
		return 5;
	case 'UI':
		return 6;
	case 'DI':
		return 7;
	case 'LI':
		return 8;
	case 'RI':
		return 9;
	case 'FI':
		return 10;
	case 'BI':
		return 11;
	case 'u':
		return 12;
	case 'd':
		return 13;
	case 'l':
		return 14;
	case 'r':
		return 15;
	case 'f':
		return 16;
	case 'b':
		return 17;
	case 'ui':
		return 18;
	case 'di':
		return 19;
	case 'li':
		return 20;
	case 'ri':
		return 21;
	case 'fi':
		return 22;
	case 'bi':
		return 24;
	case 'M':
		return 23;
	case 'MI':
		return 25;
	case 'E':
		return 26;
	case 'EI':
		return 27;
	case 'S':
		return 28;
	case 'SI':
		return 30;
	case 'X':
		return 29;
	case 'XI':
		return 31;
	case 'Y':
		return 32;
	case 'YI':
		return 33;
	case 'Z':
		return 34;
	case 'ZI':
		return 35;
	}
}

std::string Cube::get_colors() {
	sort();
	std::string up = SideString(&UP, 1);
	std::string down = SideString(&DOWN, 1);
	std::string left = SideString(&LEFT, 0);
	std::string right = SideString(&RIGHT, 0);
	std::string front = SideString(&FRONT, 2);
	std::string back = SideString(&BACK, 2);

	std::string colors = "";

	for (int i = 0; i < 9; i += 3) {
		colors += back.at(CWTURN(i % 9, 2));
		colors += back.at(CWTURN(i % 9, 1));
		colors += back.at(CWTURN(i % 9, 0));
	}

	for (int i = 9; i < 45; i += 12) {
		colors += left.at(CWTURN(i % 9, 2));
		colors += left.at(CWTURN(i % 9, 1));
		colors += left.at(CWTURN(i % 9, 0));

		colors += up.at(CWTURN(i % 9, 2));
		colors += up.at(CWTURN(i % 9, 1));
		colors += up.at(CWTURN(i % 9, 0));

		colors += right.at(CWTURN(i % 9, 0));
		colors += right.at(CWTURN(i % 9, 1));
		colors += right.at(CWTURN(i % 9, 2));

		colors += down.at(CWTURN(i % 9, 2));
		colors += down.at(CWTURN(i % 9, 1));
		colors += down.at(CWTURN(i % 9, 0));
	}

	for (int i = 45; i < 54; i += 3) {
		colors += front.at(CCTURN(i % 9, 0));
		colors += front.at(CCTURN(i % 9, 1));
		colors += front.at(CCTURN(i % 9, 2));
	}
	return colors;
}

void Cube::Randomize() {
	for (int i = 0; i < 999; i++) {
		call_func_index(rand() % 36);
	}
	std::sort(std::begin(pieces_), std::end(pieces_), Piece::compare);
}

double Cube::Score() {
	double score = SideScore(&UP, 1) + SideScore(&DOWN, 1) + SideScore(&LEFT, 0) + SideScore(&RIGHT, 0) + SideScore(&FRONT, 2) + SideScore(&BACK, 2);
	score = score / 6;
	return score;
}

double Cube::SideScore(const Eigen::Vector3i* side, int pos) {
	int max = populate_map(side, pos);
	return log(max) / log(9);
}

bool Cube::Solved() {
	return Score() == 1;
}

void Cube::sort() {
	std::sort(std::begin(pieces_), std::end(pieces_), Piece::compare);
}


void Cube::call_func_index(int index) {
	(this->*func_list_[index])();
}

int Cube::populate_map(const Eigen::Vector3i* plane, int position) {
	std::map<int, int> vals;
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(plane)) {
			int color = pieces_[i]->get_color()(position);
			if (vals.find(color) == vals.end()) {
				vals[color] = 1;
			}
			else {
				int temp = ++vals[color];
				if (max < temp) {
					max = temp;
				}
			}
		}
	}
	return max;
}

void Cube::ResetPieces() {
	for (int i = 0; i < 26; i++) {
		pieces_[i].reset();
	}
	SetupPieces();
}

std::string Cube::SideString(const Eigen::Vector3i* side, int pos) {
	std::string list = "";
	for (int i = 0; i < 26; i++) {
		if (pieces_[i]->inPlane(side)) {
			list += std::to_string(pieces_[i]->get_color()(pos));
		}
	}
	return list;
}

void Cube::SetupPieces() {
	pieces_[0] = std::make_shared<Piece>(UP, WHITE);
	pieces_[1] = std::make_shared<Piece>(UP + LEFT, WHITE + ORANGE);
	pieces_[2] = std::make_shared<Piece>(UP + RIGHT, WHITE + RED);
	pieces_[3] = std::make_shared<Piece>(UP + FRONT, WHITE + GREEN);
	pieces_[4] = std::make_shared<Piece>(UP + BACK, WHITE + BLUE);
	pieces_[5] = std::make_shared<Piece>(UP + LEFT + FRONT, WHITE + ORANGE + GREEN);
	pieces_[6] = std::make_shared<Piece>(UP + LEFT + BACK, WHITE + ORANGE + BLUE);
	pieces_[7] = std::make_shared<Piece>(UP + RIGHT + FRONT, WHITE + RED + GREEN);
	pieces_[8] = std::make_shared<Piece>(UP + RIGHT + BACK, WHITE + RED + BLUE);
	pieces_[9] = std::make_shared<Piece>(DOWN, YELLOW);
	pieces_[10] = std::make_shared<Piece>(DOWN + LEFT, YELLOW + ORANGE);
	pieces_[11] = std::make_shared<Piece>(DOWN + RIGHT, YELLOW + RED);
	pieces_[12] = std::make_shared<Piece>(DOWN + FRONT, YELLOW + GREEN);
	pieces_[13] = std::make_shared<Piece>(DOWN + BACK, YELLOW + BLUE);
	pieces_[14] = std::make_shared<Piece>(DOWN + LEFT + FRONT, YELLOW + ORANGE + GREEN);
	pieces_[15] = std::make_shared<Piece>(DOWN + LEFT + BACK, YELLOW + ORANGE + BLUE);
	pieces_[16] = std::make_shared<Piece>(DOWN + RIGHT + FRONT, YELLOW + RED + GREEN);
	pieces_[17] = std::make_shared<Piece>(DOWN + RIGHT + BACK, YELLOW + RED + BLUE);
	pieces_[18] = std::make_shared<Piece>(LEFT, ORANGE);
	pieces_[19] = std::make_shared<Piece>(RIGHT, RED);
	pieces_[20] = std::make_shared<Piece>(FRONT, GREEN);
	pieces_[21] = std::make_shared<Piece>(BACK, BLUE);
	pieces_[22] = std::make_shared<Piece>(LEFT + FRONT, ORANGE + GREEN);
	pieces_[23] = std::make_shared<Piece>(RIGHT + FRONT, RED + GREEN);
	pieces_[24] = std::make_shared<Piece>(LEFT + BACK, ORANGE + BLUE);
	pieces_[25] = std::make_shared<Piece>(RIGHT + BACK, RED + BLUE);
}
