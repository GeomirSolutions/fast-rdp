// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_FIT_PLANE_H
#define IGL_FIT_PLANE_H

#include "igl_inline.h"
#include <Eigen/Dense>

namespace igl
{
/// Fit a plane to a point cloud.
///
/// @param[in] V #Vx3 matrix. The 3D point cloud, one row for each vertex.
/// @param[out] N 1x3 Vector. The normal of the fitted plane.
/// @param[out] C 1x3 Vector. A point that lies in the fitted plane.
///
/// From
/// http://missingbytes.blogspot.com/2012/06/fitting-plane-to-point-cloud.html
IGL_INLINE void fit_plane(const Eigen::MatrixXd &V, Eigen::RowVector3d &N,
                          Eigen::RowVector3d &C);
} // namespace igl

#ifndef IGL_STATIC_LIBRARY
#include "fit_plane.cpp"
#endif

#endif
