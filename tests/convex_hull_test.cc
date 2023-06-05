/*
* Filename: convex_hull_test.cc
* Created on: June  8, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "doctest.h"
#include "convex_hull.h"

TEST_CASE("Fecho convexo: Graham Scan com bucket sort") {
    // Considera pontos colineares
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> checker;
    Vector<geom::Point2D> convex;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);
    geom::Point2D h(17, 6);
    geom::Point2D i(8, 1);
    geom::Point2D j(10, 10);
    geom::Point2D k(10, 8);
    geom::Point2D l(10, 6);
    geom::Point2D m(10, 4);
    geom::Point2D n(14, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);
    points.PushBack(h);
    points.PushBack(i);
    points.PushBack(j);
    points.PushBack(k);
    points.PushBack(l);
    points.PushBack(m);
    points.PushBack(n);

    checker.PushBack(g);
    checker.PushBack(n);
    checker.PushBack(b);
    checker.PushBack(c);
    checker.PushBack(e);
    checker.PushBack(j);
    checker.PushBack(a);
    checker.PushBack(i);
    checker.PushBack(g);

    geom::ConvexHull::GrahamScan(points, convex, geom::Utils::BucketSort);

    bool pass = checker == convex;

    CHECK(pass);

    if (!pass) {
        std::cout << " BUCKET " << " CHECKER " << std::endl;
        for (unsigned int i = 0; i < unsigned(utils::Max(convex.Size(), checker.Size())); i++) {
            if (i < convex.Size()) {
                std::cout << convex[i];
            }
            if (i < checker.Size()) {
                std::cout << " ~ " << checker[i];
            }
            std::cout << std::endl;
        }
    }
}

TEST_CASE("Fecho convexo: Graham Scan com Insertion Sort") {
    // Considera pontos colineares
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> checker;
    Vector<geom::Point2D> convex;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);
    geom::Point2D h(17, 6);
    geom::Point2D i(8, 1);
    geom::Point2D j(10, 10);
    geom::Point2D k(10, 8);
    geom::Point2D l(10, 6);
    geom::Point2D m(10, 4);
    geom::Point2D n(14, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);
    points.PushBack(h);
    points.PushBack(i);
    points.PushBack(j);
    points.PushBack(k);
    points.PushBack(l);
    points.PushBack(m);
    points.PushBack(n);

    checker.PushBack(g);
    checker.PushBack(n);
    checker.PushBack(b);
    checker.PushBack(c);
    checker.PushBack(e);
    checker.PushBack(j);
    checker.PushBack(a);
    checker.PushBack(i);
    checker.PushBack(g);

    geom::ConvexHull::GrahamScan(points, convex, geom::Utils::InsertionSort);

    bool pass = checker == convex;

    CHECK(pass);

    if (!pass) {
        std::cout << " INSERTION " << " CHECKER " << std::endl;
        for (unsigned int i = 0; i < unsigned(utils::Max(convex.Size(), checker.Size())); i++) {
            if (i < convex.Size()) {
                std::cout << convex[i];
            }
            if (i < checker.Size()) {
                std::cout << " ~ " << checker[i];
            }
            std::cout << std::endl;
        }
    }
}

TEST_CASE("Fecho convexo: Graham Scan com Merge Sort") {
    // Considera pontos colineares
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> checker;
    Vector<geom::Point2D> convex;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);
    geom::Point2D h(17, 6);
    geom::Point2D i(8, 1);
    geom::Point2D j(10, 10);
    geom::Point2D k(10, 8);
    geom::Point2D l(10, 6);
    geom::Point2D m(10, 4);
    geom::Point2D n(14, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);
    points.PushBack(h);
    points.PushBack(i);
    points.PushBack(j);
    points.PushBack(k);
    points.PushBack(l);
    points.PushBack(m);
    points.PushBack(n);

    checker.PushBack(g);
    checker.PushBack(n);
    checker.PushBack(b);
    checker.PushBack(c);
    checker.PushBack(e);
    checker.PushBack(j);
    checker.PushBack(a);
    checker.PushBack(i);
    checker.PushBack(g);

    geom::ConvexHull::GrahamScan(points, convex, geom::Utils::MergeSort);

    bool pass = checker == convex;

    CHECK(pass);

    if (!pass) {
        std::cout << " MERGE " << " CHECKER " << std::endl;
        for (unsigned int i = 0; i < unsigned(utils::Max(convex.Size(), checker.Size())); i++) {
            if (i < convex.Size()) {
                std::cout << convex[i];
            }
            if (i < checker.Size()) {
                std::cout << " ~ " << checker[i];
            }
            std::cout << std::endl;
        }
    }
}

TEST_CASE("Fecho convexo: Jarvis March") {
    // Não considera pontos colineares
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> checker;
    Vector<geom::Point2D> convex;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);
    geom::Point2D h(17, 6);
    geom::Point2D i(8, 1);
    geom::Point2D j(10, 10);
    geom::Point2D k(10, 8);
    geom::Point2D l(10, 6);
    geom::Point2D m(10, 4);
    geom::Point2D n(14, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);
    points.PushBack(h);
    points.PushBack(i);
    points.PushBack(j);
    points.PushBack(k);
    points.PushBack(l);
    points.PushBack(m);
    points.PushBack(n);

    checker.PushBack(g);
    checker.PushBack(b);
    checker.PushBack(c);
    checker.PushBack(e);
    checker.PushBack(j);
    checker.PushBack(a);
    checker.PushBack(g);

    geom::ConvexHull::JarvisMarch(points, convex);

    bool pass = checker == convex;

    CHECK(pass);

    if (!pass) {
        std::cout << " JARVIS " << " CHECKER " << std::endl;
        for (unsigned int i = 0; i < unsigned(utils::Max(convex.Size(), checker.Size())); i++) {
            if (i < convex.Size()) {
                std::cout << convex[i];
            }
            if (i < checker.Size()) {
                std::cout << " ~ " << checker[i];
            }
            std::cout << std::endl;
        }
    }
}
