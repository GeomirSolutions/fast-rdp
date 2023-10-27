// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2016 Michael Rabinovich
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_LINE_SEARCH_H
#define IGL_LINE_SEARCH_H
#include "igl_inline.h"

#include <Eigen/Dense>

namespace igl
{
/// Implement a bisection linesearch to minimize a mesh-based energy on vertices
/// given at 'x' at a search direction 'd', with initial step size. Stops when a
/// point with lower energy is found, or after maximal iterations have been
/// reached.
///
/// @param[in] x  #X by dim list of variables
/// @param[in] d  #X by dim list of a given search direction
/// @param[in] i_step_size  initial step size
/// @param[in] energy  A function to compute the mesh-based energy (return an
/// energy that is bigger than 0)
/// @param[out] x  #X by dim list of variables at the new location
/// @param[in] cur_energy(OPTIONAL)     The energy at the given point. Helps
/// save redundant computations.
///              This is optional. If not specified, the function will compute
///              it.
/// @return the energy at the new point 'x'
IGL_INLINE double line_search(Eigen::MatrixXd &x, const Eigen::MatrixXd &d,
                              double i_step_size,
                              std::function<double(Eigen::MatrixXd &)> energy,
                              double cur_energy = -1);

} // namespace igl

#ifndef IGL_STATIC_LIBRARY
#include "line_search.cpp"
#endif

#endif
