// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "edge_lengths.h"
#include "squared_edge_lengths.h"

template <typename DerivedV, typename DerivedF, typename DerivedL>
IGL_INLINE void igl::edge_lengths(const Eigen::MatrixBase<DerivedV> &V,
                                  const Eigen::MatrixBase<DerivedF> &F,
                                  Eigen::PlainObjectBase<DerivedL> &L)
{
    igl::squared_edge_lengths(V, F, L);
    L = L.array().sqrt().eval();
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 6, 0, -1, 6>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 6, 0, -1, 6>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<float, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<double, -1, 2, 0, -1, 2>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 6, 0, -1, 6>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 6, 0, -1, 6>> &);
// generated by autoexplicit.sh
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 2, 0, -1, 2>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<float, -1, 2, 0, -1, 2>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 2, 0, -1, 2>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 2, 0, -1, 2>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 2, 0, -1, 2>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 2, 0, -1, 2>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 2, 0, -1, 2>,
                                Eigen::Matrix<int, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<double, -1, 2, 0, -1, 2>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 6, 0, -1, 6>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 6, 0, -1, 6>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 1, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, 4, 0, -1, 4>,
                                Eigen::Matrix<double, -1, 6, 0, -1, 6>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 4, 0, -1, 4>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 6, 0, -1, 6>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 1, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 1, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 1, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<double, -1, 6, 0, -1, 6>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 6, 0, -1, 6>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                                Eigen::Matrix<int, -1, 4, 0, -1, 4>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 4, 0, -1, 4>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<float, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<int, -1, 3, 1, -1, 3>,
                                Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template void igl::edge_lengths<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                Eigen::Matrix<double, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 1, 0, -1, 1>> &);
#endif
