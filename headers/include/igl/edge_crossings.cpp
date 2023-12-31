#include "edge_crossings.h"
#include "list_to_matrix.h"

template <typename DeriveduE, typename DerivedS, typename DerivedT>
void igl::edge_crossings(const Eigen::MatrixBase<DeriveduE> &uE,
                         const Eigen::MatrixBase<DerivedS> &S,
                         const typename DerivedS::Scalar val,
                         std::unordered_map<int, int> &uE2I,
                         Eigen::PlainObjectBase<DerivedT> &T)
{
    using Scalar = typename DerivedS::Scalar;
    {
        std::vector<Scalar> vT;
        for (int u = 0; u < uE.rows(); u++) {
            // Does edge cross isovalue?
            const int i = uE(u, 0);
            const int j = uE(u, 1);
            const Scalar Si = S(i);
            const Scalar Sj = S(j);
            // Specifically do not include endpoints
            if ((Si - val) * (Sj - val) >= 0) {
                continue;
            }
            // find crossing point
            const Scalar t = (val - Si) / (Sj - Si);
            uE2I[u] = vT.size();
            vT.emplace_back(t);
        }
        igl::list_to_matrix(vT, T);
    }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::edge_crossings<Eigen::Matrix<int, -1, -1, 0, -1, -1>,
                                  Eigen::Matrix<double, -1, 1, 0, -1, 1>,
                                  Eigen::Matrix<double, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<double, -1, 1, 0, -1, 1>> const &,
    Eigen::Matrix<double, -1, 1, 0, -1, 1>::Scalar,
    std::unordered_map<int, int, std::hash<int>, std::equal_to<int>,
                       std::allocator<std::pair<int const, int>>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<double, -1, 1, 0, -1, 1>> &);
#endif
