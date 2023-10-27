// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "list_to_matrix.h"

#include <cassert>
#include <cstdio>

#include <Eigen/Dense>

#include "max_size.h"
#include "min_size.h"

template <typename T, typename Derived>
IGL_INLINE bool igl::list_to_matrix(const std::vector<std::vector<T>> &V,
                                    Eigen::PlainObjectBase<Derived> &M)
{
    // number of rows
    int m = V.size();
    if (m == 0) {
        M.resize(
            Derived::RowsAtCompileTime >= 0 ? Derived::RowsAtCompileTime : 0,
            Derived::ColsAtCompileTime >= 0 ? Derived::ColsAtCompileTime : 0);
        return true;
    }
    // number of columns
    int n = igl::min_size(V);
    if (n != igl::max_size(V)) {
        return false;
    }
    assert(n != -1);
    // Resize output
    M.resize(m, n);

    // Loop over rows
    for (int i = 0; i < m; i++) {
        // Loop over cols
        for (int j = 0; j < n; j++) {
            M(i, j) = V[i][j];
        }
    }

    return true;
}

template <typename T, size_t N, typename Derived>
IGL_INLINE bool igl::list_to_matrix(const std::vector<std::array<T, N>> &V,
                                    Eigen::PlainObjectBase<Derived> &M)
{
    // number of rows
    int m = V.size();
    if (m == 0) {
        M.resize(
            Derived::RowsAtCompileTime >= 0 ? Derived::RowsAtCompileTime : 0,
            Derived::ColsAtCompileTime >= 0 ? Derived::ColsAtCompileTime : 0);
        return true;
    }
    // number of columns
    int n = static_cast<int>(N);
    assert(n != -1);
    // Resize output
    M.resize(m, n);

    // Loop over rows
    for (int i = 0; i < m; i++) {
        // Loop over cols
        for (int j = 0; j < n; j++) {
            M(i, j) = V[i][j];
        }
    }

    return true;
}

template <typename T, typename Derived>
IGL_INLINE bool igl::list_to_matrix(const std::vector<std::vector<T>> &V,
                                    const int n, const T &padding,
                                    Eigen::PlainObjectBase<Derived> &M)
{
    const int m = V.size();
    M.resize(m, n);
    for (int i = 0; i < m; i++) {
        const auto &row = V[i];
        if (row.size() > n) {
            return false;
        }
        int j = 0;
        for (; j < row.size(); j++) {
            M(i, j) = row[j];
        }
        for (; j < n; j++) {
            M(i, j) = padding;
        }
    }
    return true;
}

template <typename T, typename Derived>
IGL_INLINE bool igl::list_to_matrix(const std::vector<T> &V,
                                    Eigen::PlainObjectBase<Derived> &M)
{
    // number of rows
    int m = V.size();
    if (m == 0) {
        // fprintf(stderr,"Error: list_to_matrix() list is empty()\n");
        // return false;
        if (Derived::ColsAtCompileTime == 1) {
            M.resize(0, 1);
        } else if (Derived::RowsAtCompileTime == 1) {
            M.resize(1, 0);
        } else {
            M.resize(0, 0);
        }
        return true;
    }
    // Resize output
    if (Derived::RowsAtCompileTime == 1) {
        M.resize(1, m);
    } else {
        M.resize(m, 1);
    }

    // Loop over rows
    for (int i = 0; i < m; i++) {
        M(i) = V[i];
    }

    return true;
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<int, Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>> &);
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<double, Eigen::Matrix<float, -1, -1, 0, -1, -1>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, -1, 0, -1, -1>> &);
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<double, Eigen::Matrix<float, -1, 2, 1, -1, 2>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 2, 1, -1, 2>> &);
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<double, Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
// generated by autoexplicit.sh
// generated by autoexplicit.sh
template bool igl::list_to_matrix<long, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<std::vector<long, std::allocator<long>>,
                std::allocator<std::vector<long, std::allocator<long>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<bool, Eigen::Array<bool, -1, 3, 0, -1, 3>>(
    std::vector<std::vector<bool, std::allocator<bool>>,
                std::allocator<std::vector<bool, std::allocator<bool>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Array<bool, -1, 3, 0, -1, 3>> &);
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 1, -1, -1>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> &);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, 2, 0, -1, 2>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 2, 0, -1, 2>> &);
// generated by autoexplicit.sh
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, 2, 0, -1, 2>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 2, 0, -1, 2>> &);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::Matrix<double, 4, 1, 0, 4, 1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, 4, 1, 0, 4, 1>> &);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::Matrix<double, 3, 1, 0, 3, 1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, 3, 1, 0, 3, 1>> &);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::Matrix<double, 2, 1, 0, 2, 1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, 2, 1, 0, 2, 1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, 3, 1, -1, 3>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, 3, 0, -1, 3>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> &);
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<int, Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, -1, 1, -1, -1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<float, -1, 3, 1, -1, 3>>(
    std::vector<
        std::vector<double, std::allocator<double>>,
        std::allocator<std::vector<double, std::allocator<double>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> &);
template bool igl::list_to_matrix<float, Eigen::Matrix<float, -1, 3, 1, -1, 3>>(
    std::vector<std::vector<float, std::allocator<float>>,
                std::allocator<std::vector<float, std::allocator<float>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> &);
template bool
igl::list_to_matrix<unsigned int, Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>>(
    std::vector<std::vector<unsigned int, std::allocator<unsigned int>>,
                std::allocator<std::vector<
                    unsigned int, std::allocator<unsigned int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>> &);
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    std::vector<int, std::allocator<int>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template bool
igl::list_to_matrix<unsigned long, Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    std::vector<unsigned long, std::allocator<unsigned long>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template bool
igl::list_to_matrix<float, Eigen::Matrix<float, -1, -1, 0, -1, -1>>(
    std::vector<std::vector<float, std::allocator<float>>,
                std::allocator<std::vector<float, std::allocator<float>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<bool, Eigen::Array<bool, -1, 1, 0, -1, 1>>(
    std::vector<bool, std::allocator<bool>> const &,
    Eigen::PlainObjectBase<Eigen::Array<bool, -1, 1, 0, -1, 1>> &);
template bool igl::list_to_matrix<bool, Eigen::Array<bool, -1, -1, 0, -1, -1>>(
    std::vector<std::vector<bool, std::allocator<bool>>,
                std::allocator<std::vector<bool, std::allocator<bool>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Array<bool, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<bool, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<bool, std::allocator<bool>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<bool, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<std::vector<bool, std::allocator<bool>>,
                std::allocator<std::vector<bool, std::allocator<bool>>>> const
        &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, 1, 0, -1, 1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 1, 0, -1, 1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<int, std::allocator<int>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<unsigned long, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<unsigned long, std::allocator<unsigned long>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, 3, 1, -1, 3>>(
    std::vector<std::vector<int, std::allocator<int>>,
                std::allocator<std::vector<int, std::allocator<int>>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> &);
template bool
igl::list_to_matrix<unsigned long, Eigen::Matrix<long, -1, 1, 0, -1, 1>>(
    std::vector<unsigned long, std::allocator<unsigned long>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<long, -1, 1, 0, -1, 1>> &);
template bool igl::list_to_matrix<bool, Eigen::Matrix<bool, -1, 1, 0, -1, 1>>(
    std::vector<bool, std::allocator<bool>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<bool, -1, 1, 0, -1, 1>> &);

template bool
igl::list_to_matrix<double, 3ul, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<std::array<double, 3ul>,
                std::allocator<std::array<double, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<double, 3ul, Eigen::Matrix<double, -1, -1, 1, -1, -1>>(
    std::vector<std::array<double, 3ul>,
                std::allocator<std::array<double, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 1, -1, -1>> &);
template bool
igl::list_to_matrix<double, 3ul, Eigen::Matrix<double, -1, 3, 0, -1, 3>>(
    std::vector<std::array<double, 3ul>,
                std::allocator<std::array<double, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 0, -1, 3>> &);
template bool
igl::list_to_matrix<double, 3ul, Eigen::Matrix<double, -1, 3, 1, -1, 3>>(
    std::vector<std::array<double, 3ul>,
                std::allocator<std::array<double, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 3, 1, -1, 3>> &);
template bool
igl::list_to_matrix<float, 3ul, Eigen::Matrix<float, -1, -1, 0, -1, -1>>(
    std::vector<std::array<float, 3ul>,
                std::allocator<std::array<float, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<float, 3ul, Eigen::Matrix<float, -1, 3, 0, -1, 3>>(
    std::vector<std::array<float, 3ul>,
                std::allocator<std::array<float, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 0, -1, 3>> &);
template bool
igl::list_to_matrix<float, 3ul, Eigen::Matrix<float, -1, 3, 1, -1, 3>>(
    std::vector<std::array<float, 3ul>,
                std::allocator<std::array<float, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<float, -1, 3, 1, -1, 3>> &);
template bool
igl::list_to_matrix<int, 3ul, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<std::array<int, 3ul>,
                std::allocator<std::array<int, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<int, 3ul, Eigen::Matrix<int, -1, 3, 0, -1, 3>>(
    std::vector<std::array<int, 3ul>,
                std::allocator<std::array<int, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 0, -1, 3>> &);
template bool
igl::list_to_matrix<int, 3ul, Eigen::Matrix<int, -1, 3, 1, -1, 3>>(
    std::vector<std::array<int, 3ul>,
                std::allocator<std::array<int, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 3, 1, -1, 3>> &);
template bool igl::list_to_matrix<unsigned int, 3ul,
                                  Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>>(
    std::vector<std::array<unsigned int, 3ul>,
                std::allocator<std::array<unsigned int, 3ul>>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3>> &);

#ifdef WIN32
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1>>(
    std::vector<double, std::allocator<double>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);
template bool igl::list_to_matrix<unsigned __int64,
                                  class Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    class std::vector<unsigned __int64,
                      class std::allocator<unsigned __int64>> const &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<int, -1, -1, 0, -1, -1>>
        &);
template bool
igl::list_to_matrix<unsigned __int64,
                    class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>>(
    class std::vector<unsigned __int64,
                      class std::allocator<unsigned __int64>> const &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<__int64, -1, 1, 0, -1, 1>>
        &);
template bool igl::list_to_matrix<unsigned __int64,
                                  class Eigen::Matrix<long, -1, 1, 0, -1, 1>>(
    class std::vector<unsigned __int64,
                      class std::allocator<unsigned __int64>> const &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<long, -1, 1, 0, -1, 1>> &);
template bool igl::list_to_matrix<unsigned long long,
                                  class Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    class std::vector<unsigned long long,
                      class std::allocator<unsigned long long>> const &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template bool
igl::list_to_matrix<unsigned long, Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    std::vector<unsigned long, std::allocator<unsigned long>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> &);
template bool
igl::list_to_matrix<__int64, class Eigen::Matrix<int, -1, -1, 0, -1, -1>>(
    class std::vector<class std::vector<__int64, class std::allocator<__int64>>,
                      class std::allocator<class std::vector<
                          __int64, class std::allocator<__int64>>>> const &,
    class Eigen::PlainObjectBase<class Eigen::Matrix<int, -1, -1, 0, -1, -1>>
        &);
#endif
#endif
