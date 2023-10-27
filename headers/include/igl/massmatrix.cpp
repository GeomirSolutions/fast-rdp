// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "massmatrix.h"
#include "massmatrix_intrinsic.h"
#include "edge_lengths.h"
#include "sparse.h"
#include "doublearea.h"
#include "volume.h"
#include "repmat.h"
#include <Eigen/Geometry>
#include <iostream>

template <typename DerivedV, typename DerivedF, typename Scalar>
IGL_INLINE void igl::massmatrix(const Eigen::MatrixBase<DerivedV> &V,
                                const Eigen::MatrixBase<DerivedF> &F,
                                const MassMatrixType type,
                                Eigen::SparseMatrix<Scalar> &M)
{
    using namespace Eigen;
    using namespace std;

    const int n = V.rows();
    const int m = F.rows();
    const int simplex_size = F.cols();

    MassMatrixType eff_type = type;
    // Use voronoi of for triangles by default, otherwise barycentric
    if (type == MASSMATRIX_TYPE_DEFAULT) {
        eff_type = (simplex_size == 3 ? MASSMATRIX_TYPE_VORONOI
                                      : MASSMATRIX_TYPE_BARYCENTRIC);
    }

    if (simplex_size == 3) {
        // Triangles
        // edge lengths numbered same as opposite vertices
        Matrix<Scalar, Dynamic, 3> l;
        igl::edge_lengths(V, F, l);
        return massmatrix_intrinsic(l, F, type, M);
    } else if (simplex_size == 4) {
        // tetrahedra
        assert(V.cols() == 3 &&
               "vertices must be defined in 3D for tetrahedra");

        Matrix<Scalar, Dynamic, 1> vol;
        volume(V, F, vol);
        vol = vol.array().abs();

        Matrix<typename DerivedF::Scalar, Dynamic, 1> MI;
        Matrix<typename DerivedF::Scalar, Dynamic, 1> MJ;
        Matrix<Scalar, Dynamic, 1> MV;

        switch (eff_type) {
        case MASSMATRIX_TYPE_BARYCENTRIC:
            MI.resize(m * 4, 1);
            MJ.resize(m * 4, 1);
            MV.resize(m * 4, 1);
            MI.block(0 * m, 0, m, 1) = F.col(0);
            MI.block(1 * m, 0, m, 1) = F.col(1);
            MI.block(2 * m, 0, m, 1) = F.col(2);
            MI.block(3 * m, 0, m, 1) = F.col(3);
            MJ = MI;
            repmat(vol, 4, 1, MV);
            assert(MV.rows() == m * 4 && MV.cols() == 1);
            MV.array() /= 4.;
            break;
        case MASSMATRIX_TYPE_VORONOI: {
            assert(false && "Implementation incomplete");
            break;
        }
        case MASSMATRIX_TYPE_FULL:
            MI.resize(m * 16, 1);
            MJ.resize(m * 16, 1);
            MV.resize(m * 16, 1);
            // indicies and values of the element mass matrix entries in the
            // order
            // (1,0),(2,0),(3,0),(2,1),(3,1),(0,1),(3,2),(0,2),(1,2),(0,3),(1,3),(2,3),(0,0),(1,1),(2,2),(3,3);
            MI << F.col(1), F.col(2), F.col(3), F.col(2), F.col(3), F.col(0),
                F.col(3), F.col(0), F.col(1), F.col(0), F.col(1), F.col(2),
                F.col(0), F.col(1), F.col(2), F.col(3);
            MJ << F.col(0), F.col(0), F.col(0), F.col(1), F.col(1), F.col(1),
                F.col(2), F.col(2), F.col(2), F.col(3), F.col(3), F.col(3),
                F.col(0), F.col(1), F.col(2), F.col(3);
            repmat(vol, 16, 1, MV);
            assert(MV.rows() == m * 16 && MV.cols() == 1);
            MV.block(0 * m, 0, 12 * m, 1) /= 20.;
            MV.block(12 * m, 0, 4 * m, 1) /= 10.;
            break;
        default:
            assert(false && "Unknown Mass matrix eff_type");
        }
        sparse(MI, MJ, MV, n, n, M);
    } else {
        // Unsupported simplex size
        assert(false && "Unsupported simplex size");
    }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::massmatrix<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                              Eigen::Matrix<int, -1, -1, 0, -1, -1>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
// generated by autoexplicit.sh
template void igl::massmatrix<Eigen::Matrix<double, -1, -1, 1, -1, -1>,
                              Eigen::Matrix<int, -1, -1, 0, -1, -1>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
// generated by autoexplicit.sh
template void igl::massmatrix<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                              Eigen::Matrix<int, -1, 4, 0, -1, 4>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 4, 0, -1, 4>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
// generated by autoexplicit.sh
template void igl::massmatrix<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                              Eigen::Matrix<int, -1, 3, 0, -1, 3>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
template void igl::massmatrix<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                              Eigen::Matrix<int, -1, 3, 1, -1, 3>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
template void igl::massmatrix<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                              Eigen::Matrix<int, -1, -1, 0, -1, -1>, double>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    igl::MassMatrixType, Eigen::SparseMatrix<double, 0, int> &);
#endif
