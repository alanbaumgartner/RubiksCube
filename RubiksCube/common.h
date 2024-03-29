// Copyright 2019 Alan Victor Baumgartner

#pragma once

#include <Eigen/Eigen>
#include <cmath>

template<typename T1, typename T2>
constexpr auto CCTURN(T1 a, T2  b) { return ((2 - ((a + b) / 3)) + (((a + b) % 3) * 3)); }

template<typename T1, typename T2>
constexpr auto CWTURN(T1 a, T2  b) { return ((6 + ((a + b) / 3)) - (((a + b) % 3) * 3)); }

template<typename T>
constexpr auto SIN(T a) { return (static_cast<int>(sin(a))); }

template<typename T>
constexpr auto COS(T a) { return (static_cast<int>(cos(a))); }

const double PI = atan(1.0) * 4;
const double TWO_RAD = PI / 2;

const Eigen::Vector3i UP = Eigen::Vector3i(0, 1, 0);
const Eigen::Vector3i DOWN = Eigen::Vector3i(0, -1, 0);
const Eigen::Vector3i LEFT = Eigen::Vector3i(-1, 0, 0);
const Eigen::Vector3i RIGHT = Eigen::Vector3i(1, 0, 0);
const Eigen::Vector3i FRONT = Eigen::Vector3i(0, 0, 1);
const Eigen::Vector3i BACK = Eigen::Vector3i(0, 0, -1);

const Eigen::Vector3i WHITE = Eigen::Vector3i(0, 1, 0);
const Eigen::Vector3i YELLOW = Eigen::Vector3i(0, 2, 0);
const Eigen::Vector3i ORANGE = Eigen::Vector3i(3, 0, 0);
const Eigen::Vector3i RED = Eigen::Vector3i(4, 0, 0);
const Eigen::Vector3i GREEN = Eigen::Vector3i(0, 0, 5);
const Eigen::Vector3i BLUE = Eigen::Vector3i(0, 0, 6);

const Eigen::Matrix3i ROTATE_X_CW((Eigen::Matrix3i() << 1, 0, 0, 0, COS(TWO_RAD), -SIN(TWO_RAD), 0, SIN(TWO_RAD), COS(TWO_RAD)).finished());
const Eigen::Matrix3i ROTATE_X_CC((Eigen::Matrix3i() << 1, 0, 0, 0, COS(-TWO_RAD), -SIN(-TWO_RAD), 0, SIN(-TWO_RAD), COS(-TWO_RAD)).finished());
const Eigen::Matrix3i ROTATE_Y_CW((Eigen::Matrix3i() << COS(-TWO_RAD), 0, SIN(-TWO_RAD), 0, 1, 0, -SIN(-TWO_RAD), 0, COS(-TWO_RAD)).finished());
const Eigen::Matrix3i ROTATE_Y_CC((Eigen::Matrix3i() << COS(TWO_RAD), 0, SIN(TWO_RAD), 0, 1, 0, -SIN(TWO_RAD), 0, COS(TWO_RAD)).finished());
const Eigen::Matrix3i ROTATE_Z_CW((Eigen::Matrix3i() << COS(-TWO_RAD), -SIN(-TWO_RAD), 0, SIN(-TWO_RAD), COS(-TWO_RAD), 0, 0, 0, 1).finished());
const Eigen::Matrix3i ROTATE_Z_CC((Eigen::Matrix3i() << COS(TWO_RAD), -SIN(TWO_RAD), 0, SIN(TWO_RAD), COS(TWO_RAD), 0, 0, 0, 1).finished());

const Eigen::Matrix3i ROTATE_COLOR_X((Eigen::Matrix3i() <<
	1, 0, 0,
	0, 0, 1,
	0, 1, 0).finished());

const Eigen::Matrix3i ROTATE_COLOR_Y((Eigen::Matrix3i() <<
	0, 0, 1,
	0, 1, 0,
	1, 0, 0).finished());

const Eigen::Matrix3i ROTATE_COLOR_Z((Eigen::Matrix3i() <<
	0, 1, 0,
	1, 0, 0,
	0, 0, 1).finished());
