// Copyright 2019 Alan Victor Baumgartner

#pragma once

#include <string>
#include "piece.h"

class Cube {
public:
	Cube();
	~Cube();

	void Solve() = delete;

	void U();
	void D();
	void L();
	void R();
	void F();
	void B();

	void U2();
	void D2();
	void L2();
	void R2();
	void F2();
	void B2();

	void UI();
	void DI();
	void LI();
	void RI();
	void FI();
	void BI();

	void u();
	void d();
	void l();
	void r();
	void f();
	void b();

	void u2();
	void d2();
	void l2();
	void r2();
	void f2();
	void b2();

	void ui();
	void di();
	void li();
	void ri();
	void fi();
	void bi();

	void M();
	void MI();
	void E();
	void EI();
	void S();
	void SI();

	void X();
	void XI();
	void Y();
	void YI();
	void Z();
	void ZI();

	std::string translateInt(int i);
	int translateChar(char c);

	std::string get_colors();

	void ResetPieces();
	void Randomize();
	double Score();
	bool Solved();

	std::shared_ptr<Piece>* get_pieces() {
		return pieces_;
	}

	void sort();

	void call_func_index(int index);

private:
	using func_ptr = void (Cube::*)();
	func_ptr func_list_[36];

	std::shared_ptr<Piece> pieces_[26];

	int populate_map(const Eigen::Vector3i* plane, int position);

	double SideScore(const Eigen::Vector3i* side, int pos);
	std::string SideString(const Eigen::Vector3i* side, int pos);

	void SetupPieces();
};
