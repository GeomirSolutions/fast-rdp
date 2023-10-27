// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2015 Olga Diamanti, Alec Jacobson
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef IGL_NCHOOSEK
#define IGL_NCHOOSEK
#include "igl_inline.h"
#include <vector>

#include <Eigen/Core>

namespace igl
{
/// Binomial coefficient. Like matlab's nchoosek.
///
/// @param[in] n  total number elements
/// @param[in] k  size of sub-set to consider
/// @return number of k-size combinations out of the set [1,...,n]
IGL_INLINE double nchoosek(const int n, const int k);
/// All combinations . Like matlab's nchoosek.
///
/// @param[in] V  n-long vector of elements
/// @param[in] k  size of sub-set to consider
/// @param[out] U  nchoosek by k long matrix where each row is a unique k-size
///   combination
template <typename DerivedV, typename DerivedU>
IGL_INLINE void nchoosek(const Eigen::MatrixBase<DerivedV> &V, const int k,
                         Eigen::PlainObjectBase<DerivedU> &U);
} // namespace igl

#ifndef IGL_STATIC_LIBRARY
#include "nchoosek.cpp"
#endif

#endif /* defined(IGL_NCHOOSEK) */
