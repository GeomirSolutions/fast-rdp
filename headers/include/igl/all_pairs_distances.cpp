// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "all_pairs_distances.h"
#include <Eigen/Dense>

template <typename Mat>
IGL_INLINE void igl::all_pairs_distances(const Mat &V, const Mat &U,
                                         const bool squared, Mat &D)
{
    // dimension should be the same
    assert(V.cols() == U.cols());
    // resize output
    D.resize(V.rows(), U.rows());
    for (int i = 0; i < V.rows(); i++) {
        for (int j = 0; j < U.rows(); j++) {
            D(i, j) = (V.row(i) - U.row(j)).squaredNorm();
            if (!squared) {
                D(i, j) = sqrt(D(i, j));
            }
        }
    }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void
igl::all_pairs_distances<Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    Eigen::Matrix<double, -1, -1, 0, -1, -1> const &,
    Eigen::Matrix<double, -1, -1, 0, -1, -1> const &, bool,
    Eigen::Matrix<double, -1, -1, 0, -1, -1> &);
#endif
