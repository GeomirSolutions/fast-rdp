#include "setxor.h"
#include "setdiff.h"
#include "setunion.h"

template <typename DerivedA, typename DerivedB, typename DerivedC,
          typename DerivedIA, typename DerivedIB>
IGL_INLINE void igl::setxor(const Eigen::MatrixBase<DerivedA> &A,
                            const Eigen::MatrixBase<DerivedB> &B,
                            Eigen::PlainObjectBase<DerivedC> &C,
                            Eigen::PlainObjectBase<DerivedIA> &IA,
                            Eigen::PlainObjectBase<DerivedIB> &IB)
{
    DerivedC AB, BA;
    DerivedIA IAB, IBA;
    setdiff(A, B, AB, IAB);
    setdiff(B, A, BA, IBA);
    setunion(AB, BA, C, IA, IB);
    IA = IAB(IA.derived()).eval();
    IB = IBA(IB.derived()).eval();
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template void igl::setxor<
    Eigen::Matrix<int, -1, 2, 0, -1, 2>, Eigen::Matrix<int, -1, 2, 0, -1, 2>,
    Eigen::Matrix<int, -1, 1, 0, -1, 1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>,
    Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 2, 0, -1, 2>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, 2, 0, -1, 2>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
template void igl::setxor<
    Eigen::Matrix<int, -1, -1, 0, -1, -1>,
    Eigen::Matrix<int, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>,
    Eigen::Matrix<int, -1, 1, 0, -1, 1>, Eigen::Matrix<int, -1, 1, 0, -1, 1>>(
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1>> const &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &,
    Eigen::PlainObjectBase<Eigen::Matrix<int, -1, 1, 0, -1, 1>> &);
#endif
