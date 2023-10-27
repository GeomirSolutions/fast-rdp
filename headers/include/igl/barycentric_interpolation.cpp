// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2020 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "barycentric_interpolation.h"
#include "parallel_for.h"

template <typename DerivedD, typename DerivedF, typename DerivedB,
          typename DerivedI, typename DerivedX>
IGL_INLINE void igl::barycentric_interpolation(
    const Eigen::MatrixBase<DerivedD> &D, const Eigen::MatrixBase<DerivedF> &F,
    const Eigen::MatrixBase<DerivedB> &B, const Eigen::MatrixBase<DerivedI> &I,
    Eigen::PlainObjectBase<DerivedX> &X)
{
    assert(B.rows() == I.size());
    assert(F.cols() == B.cols());
    X.setZero(B.rows(), D.cols());
    // should use parallel_for
    // for(int i = 0;i<X.rows();i++)
    parallel_for(
        X.rows(),
        [&X, &B, &D, &F, &I](const int i) {
            for (int j = 0; j < F.cols(); j++) {
                X.row(i) += B(i, j) * D.row(F(I(i), j));
            }
        },
        1000);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void
igl::barycentric_interpolation<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<int, -1, 1, 0, -1, 1>,
                               Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
#endif
