#include <iostream>
#include <vector>
#include <sys/time.h>
#include <unistd.h>
#include <Polynomial/Polynomial.hpp>

using polynomial::Polynomial;

long gettime()
{
struct timespec time1 = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time1);
    long nows = time1.tv_nsec+ time1.tv_sec *1000000000;
    return nows;
}



int main( int argc, char **argv )
{
    Eigen::Matrix<double,6,1> acoeffs;
    acoeffs << 1,2,3,4,5,6;
    Polynomial<5> a( acoeffs );

    Eigen::Matrix<double,5,1> bcoeffs;
    bcoeffs << 1,2,3,4,5;
    Polynomial<4> b( bcoeffs );

    std::cout << "*** Polynomial algebra test ***\n";
    
    std::cout << "a: [" << a.coefficients().transpose() << "]\n";
    std::cout << "b: [" << b.coefficients().transpose() << "]\n";
    
    std::cout << "a+b: [" << (a+b).coefficients().transpose() << "]\n";
    std::cout << "a-b: [" << (a-b).coefficients().transpose() << "]\n";
    
    std::cout << "a*b: [" << (a*b).coefficients().transpose() << "]\n";

    std::cout << "a(5): " << a.eval(5.f) << "\n";
    
    std::cout << "\n";

    std::cout << "*** Dynamically-sized polynomial algebra test ***\n";

    Eigen::VectorXd adcoeffs(6);
    adcoeffs << 1,2,3,4,5,6;
    Polynomial<Eigen::Dynamic> ad( adcoeffs );
    Eigen::VectorXd bdcoeffs(5);
    bdcoeffs << 1,2,3,4,5;
    Polynomial<Eigen::Dynamic> bd( bdcoeffs );
    
    std::cout << "a: [" << ad.coefficients().transpose() << "]\n";
    std::cout << "b: [" << bd.coefficients().transpose() << "]\n";

    std::cout << "a+b: [" << (ad+bd).coefficients().transpose() << "]\n";
    std::cout << "a-b: [" << (ad-bd).coefficients().transpose() << "]\n";
    
    std::cout << "a*b: [" << (ad*bd).coefficients().transpose() << "]\n";
    
    std::cout << "a(5): " << ad.eval(5.f) << "\n";
    
    std::cout << "\n";
    
    std::cout << "*** Polynomial roots test ***\n";
    
    Eigen::Matrix<double,5,1> ccoeffs;
    ccoeffs <<    -0.8049,    -0.4430,    0.0938,    0.9150,    0.9298;
    Polynomial<4> c(ccoeffs);
    
    std::cout << "c: [" << c.coefficients().transpose() << "]\n";
    
    double lb,ub;
    c.rootBounds(lb,ub);
    std::cout << "bounds on roots: " << lb << "  " << ub << "\n";
    
    std::vector<double> roots;
    
    long t1 = 0;
    long t2 = 0;

    t1 = gettime();
    c.realRoots(roots);
    std::cout << "roots using companion matrix:\n";
    for ( int i = 0; i < roots.size(); i++ ) std::cout << "c(" << roots[i] << "): " << c.eval(roots[i]) << "\n";
    t2 = gettime();
    std::cout << "time:" << t1 - t2 << std::endl;
    
    
    roots.clear();
    t1 = gettime();
    c.realRootsSturm(lb,ub,roots);
    std::cout << "roots using sturm sequences:\n";
    for ( int i = 0; i < roots.size(); i++ ) std::cout << "c(" << roots[i] << "): " << c.eval(roots[i]) << "\n";
    t2 = gettime();
    std::cout << "time:" << t1 - t2 << std::endl;



    std::cout << "\n";

    std::cout << "*** Dynamically-sized polynomial roots test ***\n";
    
    Eigen::VectorXd cdcoeffs(5);
    cdcoeffs <<    -0.8049,    -0.4430,    0.0938,    0.9150,    0.9298;
    Polynomial<Eigen::Dynamic> cd(ccoeffs);
    
    std::cout << "c: [" << cd.coefficients().transpose() << "]\n";
    
    cd.rootBounds(lb,ub);
    std::cout << "bounds on roots: " << lb << "  " << ub << "\n";
    
    roots.clear();

    t1 = gettime();
    cd.realRoots(roots);
    std::cout << "roots using companion matrix:\n";
    for ( int i = 0; i < roots.size(); i++ ) std::cout << "c(" << roots[i] << "): " << c.eval(roots[i]) << "\n";
    t2 = gettime();
    std::cout << "time:" << t1 - t2 << std::endl;


    roots.clear();

    t1 = gettime();
    cd.realRootsSturm(lb,ub,roots);
    std::cout << "roots using sturm sequences:\n";
    for ( int i = 0; i < roots.size(); i++ ) std::cout << "c(" << roots[i] << "): " << c.eval(roots[i]) << "\n";
    t2 = gettime();
    std::cout << "time:" << t1 - t2 << std::endl;


    return 0;
}
