// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2014 Daniele Panozzo <daniele.panozzo@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "vertex_triangle_adjacency.h"
#include "cumsum.h"

template <typename DerivedF, typename VFType, typename VFiType>
IGL_INLINE void
igl::vertex_triangle_adjacency(const typename DerivedF::Scalar n,
                               const Eigen::MatrixBase<DerivedF> &F,
                               std::vector<std::vector<VFType>> &VF,
                               std::vector<std::vector<VFiType>> &VFi)
{
    VF.clear();
    VFi.clear();

    VF.resize(n);
    VFi.resize(n);

    typedef typename DerivedF::Index Index;
    for (Index fi = 0; fi < F.rows(); ++fi) {
        for (Index i = 0; i < F.cols(); ++i) {
            VF[F(fi, i)].push_back(fi);
            VFi[F(fi, i)].push_back(i);
        }
    }
}

template <typename DerivedV, typename DerivedF, typename IndexType>
IGL_INLINE void
igl::vertex_triangle_adjacency(const Eigen::MatrixBase<DerivedV> &V,
                               const Eigen::MatrixBase<DerivedF> &F,
                               std::vector<std::vector<IndexType>> &VF,
                               std::vector<std::vector<IndexType>> &VFi)
{
    return vertex_triangle_adjacency(V.rows(), F, VF, VFi);
}

template <typename DerivedF, typename DerivedVF, typename DerivedNI>
IGL_INLINE void
igl::vertex_triangle_adjacency(const Eigen::MatrixBase<DerivedF> &F,
                               const int n,
                               Eigen::PlainObjectBase<DerivedVF> &VF,
                               Eigen::PlainObjectBase<DerivedNI> &NI)
{
    typedef Eigen::Matrix<typename DerivedVF::Scalar, Eigen::Dynamic, 1>
        VectorXI;
    // vfd  #V list so that vfd(i) contains the vertex-face degree (number of
    // faces incident on vertex i)
    VectorXI vfd = VectorXI::Zero(n);
    for (int i = 0; i < F.rows(); i++) {
        for (int j = 0; j < 3; j++) {
            vfd[F(i, j)]++;
        }
    }
    igl::cumsum(vfd, 1, NI);
    // Prepend a zero
    NI = (DerivedNI(n + 1) << 0, NI).finished();
    // vfd now acts as a counter
    vfd = NI;

    VF.derived() = Eigen::Matrix<typename DerivedVF::Scalar, Eigen::Dynamic, 1>(
        3 * F.rows(), 1);
    for (int i = 0; i < F.rows(); i++) {
        for (int j = 0; j < 3; j++) {
            VF[vfd[F(i, j)]] = i;
            vfd[F(i, j)]++;
        }
    }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<long, -1, 1, 0, -1, 1>,
                               Eigen::Matrix<long, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &, int,
    Eigen::PlainObjectBase<Eigen::Matrix<long, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<long, -1, 1, 0, -1, 1>> &);
// generated by autoexplicit.sh
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, 3, 1, -1, 3>,
                               unsigned long, unsigned long>(
    Eigen::Matrix<int, -1, 3, 1, -1, 3>::Scalar,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> const &,
    std::vector<std::vector<unsigned long, std::allocator<unsigned long>>,
                std::allocator<std::vector<unsigned long,
                                           std::allocator<unsigned long>>>> &,
    std::vector<std::vector<unsigned long, std::allocator<unsigned long>>,
                std::allocator<std::vector<unsigned long,
                                           std::allocator<unsigned long>>>> &);
// generated by autoexplicit.sh
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<double, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<int, -1, -1, 0, -1, -1>, int>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<double, -1, 3, 1, -1, 3>,
                               Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>,
                               unsigned int>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> const &,
    std::vector<
        std::vector<unsigned int, std::allocator<unsigned int>>,
        std::allocator<std::vector<unsigned int, std::allocator<unsigned int>>>>
        &,
    std::vector<
        std::vector<unsigned int, std::allocator<unsigned int>>,
        std::allocator<std::vector<unsigned int, std::allocator<unsigned int>>>>
        &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<double, -1, 3, 0, -1, 3>,
                               Eigen::Matrix<int, -1, 3, 0, -1, 3>, int>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<double, -1, -1, 0, -1, -1>, long,
                               long>(
    Eigen::Matrix<double, -1, -1, 0, -1, -1>::Scalar,
    Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> const &,
    std::vector<std::vector<long, std::allocator<long>>,
                std::allocator<std::vector<long, std::allocator<long>>>> &,
    std::vector<std::vector<long, std::allocator<long>>,
                std::allocator<std::vector<long, std::allocator<long>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, -1, 0, -1, -1>, long,
                               long>(
    Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    std::vector<std::vector<long, std::allocator<long>>,
                std::allocator<std::vector<long, std::allocator<long>>>> &,
    std::vector<std::vector<long, std::allocator<long>>,
                std::allocator<std::vector<long, std::allocator<long>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               unsigned long, unsigned long>(
    Eigen::Matrix<int, -1, -1, 0, -1, -1>::Scalar,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    std::vector<std::vector<unsigned long, std::allocator<unsigned long>>,
                std::allocator<std::vector<unsigned long,
                                           std::allocator<unsigned long>>>> &,
    std::vector<std::vector<unsigned long, std::allocator<unsigned long>>,
                std::allocator<std::vector<unsigned long,
                                           std::allocator<unsigned long>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<double, -1, 1, 0, -1, 1>,
                               Eigen::Matrix<int, -1, -1, 0, -1, -1>, int>(
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, 3, 0, -1, 3>,
                               Eigen::Matrix<int, -1, 1, 0, -1, 1>,
                               Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &, int,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               Eigen::Matrix<int, -1, 1, 0, -1, 1>,
                               Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &, int,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template void
igl::vertex_triangle_adjacency<Eigen::Matrix<int, -1, 3, 0, -1, 3>, int, int>(
    Eigen::Matrix<int, -1, 3, 0, -1, 3>::Scalar,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> const &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &,
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> &);
#ifdef WIN32
template void
igl::vertex_triangle_adjacency<class Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               unsigned __int64, unsigned __int64>(
    int,
    class Eigen::MatrixBase<class Eigen::Matrix<int, -1, -1, 0, -1, -1>> const
        &,
    class std::vector<
        class std::vector<unsigned __int64,
                          class std::allocator<unsigned __int64>>,
        class std::allocator<class std::vector<
            unsigned __int64, class std::allocator<unsigned __int64>>>> &,
    class std::vector<
        class std::vector<unsigned __int64,
                          class std::allocator<unsigned __int64>>,
        class std::allocator<class std::vector<
            unsigned __int64, class std::allocator<unsigned __int64>>>> &);
template void
igl::vertex_triangle_adjacency<class Eigen::Matrix<int, -1, 3, 1, -1, 3>,
                               unsigned __int64, unsigned __int64>(
    int,
    class Eigen::MatrixBase<class Eigen::Matrix<int, -1, 3, 1, -1, 3>> const &,
    class std::vector<
        class std::vector<unsigned __int64,
                          class std::allocator<unsigned __int64>>,
        class std::allocator<class std::vector<
            unsigned __int64, class std::allocator<unsigned __int64>>>> &,
    class std::vector<
        class std::vector<unsigned __int64,
                          class std::allocator<unsigned __int64>>,
        class std::allocator<class std::vector<
            unsigned __int64, class std::allocator<unsigned __int64>>>> &);
template void
igl::vertex_triangle_adjacency<class Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               __int64, __int64>(
    int,
    class Eigen::MatrixBase<class Eigen::Matrix<int, -1, -1, 0, -1, -1>> const
        &,
    class std::vector<class std::vector<__int64, class std::allocator<__int64>>,
                      class std::allocator<class std::vector<
                          __int64, class std::allocator<__int64>>>> &,
    class std::vector<class std::vector<__int64, class std::allocator<__int64>>,
                      class std::allocator<class std::vector<
                          __int64, class std::allocator<__int64>>>> &);
template void
igl::vertex_triangle_adjacency<class Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                               class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>,
                               class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>>(
    class Eigen::MatrixBase<class Eigen::Matrix<int, -1, -1, 0, -1, -1>> const
        &,
    int,
    class Eigen::PlainObjectBase<class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>>
        &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>>
        &);
#endif
#endif
