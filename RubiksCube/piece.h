// Copyright 2019 Alan Victor Baumgartner

#pragma once

#include <iostream>
#include <memory>
#include <mutex>
#include <Eigen/Eigen>

class Piece {
public:
	Piece(Eigen::Vector3i pos, Eigen::Vector3i color) : pos_(pos), color_(color) {}

	void rotate(const Eigen::Matrix3i* pos_dir, const Eigen::Matrix3i* color_dir);

	bool inPlane(const Eigen::Vector3i* plane);

	static bool compare(std::shared_ptr<Piece> lhs, std::shared_ptr<Piece> rhs);

	Eigen::Vector3i get_pos() const {
		return pos_;
	}

	Eigen::Vector3i get_color() const {
		return color_;
	}

private:
	std::mutex lock_;
	Eigen::Vector3i pos_;
	Eigen::Vector3i color_;
};