// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2017 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "bijective_composite_harmonic_mapping.h"

#include "doublearea.h"
#include "harmonic.h"
//#include "matlab/MatlabWorkspace.h"
#include <iostream>

template <typename DerivedV, typename DerivedF, typename Derivedb,
          typename Derivedbc, typename DerivedU>
IGL_INLINE bool igl::bijective_composite_harmonic_mapping(
    const Eigen::MatrixBase<DerivedV> &V, const Eigen::MatrixBase<DerivedF> &F,
    const Eigen::MatrixBase<Derivedb> &b,
    const Eigen::MatrixBase<Derivedbc> &bc, Eigen::PlainObjectBase<DerivedU> &U)
{
    return bijective_composite_harmonic_mapping(V, F, b, bc, 1, 200, 20, true,
                                                U);
}

template <typename DerivedV, typename DerivedF, typename Derivedb,
          typename Derivedbc, typename DerivedU>
IGL_INLINE bool igl::bijective_composite_harmonic_mapping(
    const Eigen::MatrixBase<DerivedV> &V, const Eigen::MatrixBase<DerivedF> &F,
    const Eigen::MatrixBase<Derivedb> &b,
    const Eigen::MatrixBase<Derivedbc> &bc, const int min_steps,
    const int max_steps, const int num_inner_iters, const bool test_for_flips,
    Eigen::PlainObjectBase<DerivedU> &U)
{
    typedef typename Derivedbc::Scalar Scalar;
    assert(V.cols() == 2 && bc.cols() == 2 && "Input should be 2D");
    assert(F.cols() == 3 && "F should contain triangles");
    int nsteps = min_steps;
    Eigen::Matrix<typename Derivedbc::Scalar, Eigen::Dynamic, Eigen::Dynamic>
        bc0 = V(b.col(0), Eigen::all);

    // It's difficult to check for flips "robustly" in the sense that the input
    // mesh might not have positive/consistent sign to begin with.

    while (nsteps <= max_steps) {
        U = V;
        int flipped = 0;
        int nans = 0;
        int step = 0;
        for (; step <= nsteps; step++) {
            const Scalar t = ((Scalar)step) / ((Scalar)nsteps);
            // linearly interpolate boundary conditions
            // TODO: replace this with something that guarantees a homotopic
            // "morph" of the boundary conditions. Something like "Homotopic
            // Morphing of Planar Curves" [Dym et al. 2015] but also handling
            // multiple connected components.
            Eigen::Matrix<typename Derivedbc::Scalar, Eigen::Dynamic,
                          Eigen::Dynamic>
                bct = bc0 + t * (bc - bc0);
            // Compute dsicrete harmonic map using metric of previous step
            for (int iter = 0; iter < num_inner_iters; iter++) {
                // std::cout<<nsteps<<" t: "<<t<<" iter: "<<iter;
                // igl::matlab::MatlabWorkspace mw;
                // mw.save(U,"U");
                // mw.save_index(F,"F");
                // mw.save_index(b,"b");
                // mw.save(bct,"bct");
                // mw.write("numerical.mat");
                harmonic(Eigen::Matrix<typename DerivedU::Scalar,
                                       Eigen::Dynamic, Eigen::Dynamic>(U),
                         F, b, bct, 1, U);
                bct = U(b.col(0), Eigen::all);
                nans = (U.array() != U.array()).count();
                if (test_for_flips) {
                    Eigen::Matrix<Scalar, Eigen::Dynamic, 1> A;
                    doublearea(U, F, A);
                    flipped = (A.array() < 0).count();
                    // std::cout<<"  "<<flipped<<"  nan? "<<(U.array() !=
                    // U.array()).any()<<std::endl;
                    if (flipped == 0 && nans == 0)
                        break;
                }
            }
            if (flipped > 0 || nans > 0)
                break;
        }
        if (flipped == 0 && nans == 0) {
            return step == nsteps + 1;
        }
        nsteps *= 2;
    }
    // std::cout<<"failed to finish in "<<nsteps<<"..."<<std::endl;
    return false;
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template bool igl::bijective_composite_harmonic_mapping<
    Eigen::Matrix<double, -1, -1, 1, -1, -1>,
    Eigen::Matrix<int, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>,
    Eigen::Matrix<double, -1, -1, 0, -1, -1>,
    Eigen::Matrix<double, -1, -1, 1, -1, -1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> &);
// generated by autoexplicit.sh
template bool igl::bijective_composite_harmonic_mapping<
    Eigen::Matrix<double, -1, -1, 1, -1, -1>,
    Eigen::Matrix<int, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>,
    Eigen::Matrix<double, -1, -1, 0, -1, -1>,
    Eigen::Matrix<double, -1, -1, 1, -1, -1>>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &, int,
    int, int, bool,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> &);
#endif
