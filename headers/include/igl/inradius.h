// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2016 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_INRADIUS_H
#define IGL_INRADIUS_H
#include "igl_inline.h"
#include <Eigen/Core>
namespace igl
{
/// Compute the inradius of each triangle in a mesh (V,F)
///
/// @param[in] V  #V by dim list of mesh vertex positions
/// @param[in] F  #F by 3 list of triangle indices into V
/// @param[out] R  #F list of inradii
///
template <typename DerivedV, typename DerivedF, typename DerivedR>
IGL_INLINE void inradius(const Eigen::MatrixBase<DerivedV> &V,
                         const Eigen::MatrixBase<DerivedF> &F,
                         Eigen::PlainObjectBase<DerivedR> &R);
} // namespace igl
#ifndef IGL_STATIC_LIBRARY
#include "inradius.cpp"
#endif
#endif
