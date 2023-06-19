/*
* Filename: geometry_utils.cc
* Created on: June  8, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include <iostream>

#include "doctest.h"
#include "convex_hull.h"
#include "point_2d.h"
#include "utils.h"
#include "vector.h"

#define ERROR_ACCURACY 0.0001

TEST_CASE("Bucket Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 1") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);

    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(a);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)] == b);

    geom::Utils::BucketSort(points);

    CHECK((points == sorted));
}

TEST_CASE("Bucket Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 2") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);

    sorted.PushBack(g);
    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(a);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)]  == g);

    geom::Utils::BucketSort(points);

    CHECK((points == sorted));
}

TEST_CASE("Bucket Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 3") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

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

    sorted.PushBack(g);
    sorted.PushBack(n);
    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(h);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(m);
    sorted.PushBack(l);
    sorted.PushBack(k);
    sorted.PushBack(j);
    sorted.PushBack(a);
    sorted.PushBack(i);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)] == g);

    geom::Utils::BucketSort(points);

    CHECK((points == sorted));
}

TEST_CASE("Merge Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 1") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);

    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(a);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)] == b);

    geom::Utils::MergeSort(points);

    CHECK((points == sorted));
}

TEST_CASE("Merge Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 2") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);

    sorted.PushBack(g);
    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(a);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)] == g);

    geom::Utils::MergeSort(points);

    CHECK((points == sorted));
}

TEST_CASE("Merge Sort: Ordenar os pontos de acordo com o ângulo polar: Caso 3") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> sorted;

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

    sorted.PushBack(g);
    sorted.PushBack(n);
    sorted.PushBack(b);
    sorted.PushBack(c);
    sorted.PushBack(h);
    sorted.PushBack(e);
    sorted.PushBack(d);
    sorted.PushBack(f);
    sorted.PushBack(m);
    sorted.PushBack(l);
    sorted.PushBack(k);
    sorted.PushBack(j);
    sorted.PushBack(a);
    sorted.PushBack(i);

    REQUIRE(points[geom::Utils::FindLowestPoint(points)] == g);

    geom::Utils::MergeSort(points);

    CHECK((points == sorted));
}

// Jarvis considera pontos colineares no eixo Y, o Graham não considera, então não é possível comparar o fecho resultante dos dois algoritmos
TEST_CASE("Comparação ordenação pontos aleatórios: Graham") {
    Vector<geom::Point2D> points;
    Vector<geom::Point2D> gmerge, ginsertion, gbucket; // Vectores que armazenaram o fecho convexo

    unsigned int pointsAmount = 90;
    unsigned int rounds = 10;

    bool pass = true;

    for (unsigned int i = 0; i < rounds; i++) {
        // Limpa os vectores para o próximo round de testes
        gmerge.Clear();
        ginsertion.Clear();
        gbucket.Clear();

        geom::Utils::CreateRandomPoints(pointsAmount, 0, pointsAmount, points);

        geom::ConvexHull::GrahamScan(points, gmerge, geom::Utils::MergeSort);
        geom::ConvexHull::GrahamScan(points, ginsertion, geom::Utils::InsertionSort);
        geom::ConvexHull::GrahamScan(points, gbucket, geom::Utils::BucketSort);

        if(!(gmerge == ginsertion and ginsertion == gbucket)) {
            pass = false;
            std::cout << "---- POINTS SET ----" << std::endl;
            for (unsigned int i = 0; i < points.Size(); i++) {
                std::cout << points[i] << std::endl;
            }
            std::cout << "---------" << std::endl;
            break;
        }
    }

    CHECK(pass);

    if (!pass) {
        std::cout << " MERGE " << " BUCKET " << " INSERTION " << std::endl;
        for (unsigned int i = 0; i < unsigned(utils::Max(gmerge.Size(), gbucket.Size(), ginsertion.Size())); i++) {
            if (i < gmerge.Size()) {
                std::cout << " ~ " << gmerge[i];
            }
            if (i < gbucket.Size()) {
                std::cout << " ~ " << gbucket[i];
            }
            if (i < ginsertion.Size()) {
                std::cout << " ~ " << ginsertion[i];
            }
            std::cout << std::endl;
        }
    }
}

TEST_CASE("Encontrar o ponto mais 'baixo'") {
    Vector<geom::Point2D> points;
    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(24, 6);
    geom::Point2D d(16, 10);
    geom::Point2D e(24, 12);
    geom::Point2D f(12, 8);
    geom::Point2D g(10, 0);

    points.PushBack(a);
    points.PushBack(b);
    points.PushBack(c);
    points.PushBack(d);
    points.PushBack(e);
    points.PushBack(f);
    points.PushBack(g);

    CHECK(points[geom::Utils::FindLowestPoint(points)] == g);
}

TEST_CASE("Encontrar o sentido no qual um vetor se encontra") {
    geom::Point2D ref(12, 2);
    geom::Point2D a(16, 6);
    geom::Point2D b(16, -2);
    geom::Point2D c(22, 2);
    geom::Point2D d(30, 2);

    SUBCASE("Sentido horário") {
        CHECK(ANTICLOCKWISE == geom::Utils::Clockwise(ref, b, c));
    }

    SUBCASE("Sentido anti-horário") {
        CHECK(CLOCKWISE == geom::Utils::Clockwise(ref, a, c));
    }

    SUBCASE("Pontos colineares") {
        CHECK(COLLINEAR == geom::Utils::Clockwise(ref, d, c));
    }
}

TEST_CASE("Distância entre dois pontos") {
    geom::Point2D a(6, 2);
    geom::Point2D b(16, 0);
    geom::Point2D c(-2, -4);
    geom::Point2D d(-2, 8);

    CHECK(geom::Utils::Distance(a, b) - 10.2 < 0.0001);
    CHECK(geom::Utils::Distance(a, c) - 10 < 0.0001);
    CHECK(geom::Utils::Distance(a, d) - 10 < 0.0001);
}

TEST_CASE("Ângulo polar de um ponto") {
    // primeiro e segundo quadrante
    geom::Point2D a(18, 0);
    geom::Point2D b(28, 0);
    geom::Point2D c(28, 6);
    geom::Point2D d(18 ,10);
    geom::Point2D e(8, 6);
    geom::Point2D f(8, 0);

    // terceiro e quarto quadrante
    geom::Point2D g(8, -6);
    geom::Point2D h(18, -10);
    geom::Point2D i(28, -6);

    SUBCASE("Pontos no primeiro e segundo quadrante") {
        CHECK(geom::Utils::PolarAngle(a, b) == 0); // 0°
        CHECK((geom::Utils::PolarAngle(a, c) - (30.96 * PI / 180)) < ERROR_ACCURACY); // 30.96°
        CHECK((geom::Utils::PolarAngle(a, d) - PI / 2) < ERROR_ACCURACY); // 90°
        CHECK((geom::Utils::PolarAngle(a, e) - (149.04 * PI / 180)) < ERROR_ACCURACY); // 149.04°
        CHECK(geom::Utils::PolarAngle(a, f) == PI); // 180°
    }

    SUBCASE("Pontos no terceiro e quarto quadrante") {
        CHECK((geom::Utils::PolarAngle(a, g) - (210.96 * PI / 180)) < ERROR_ACCURACY); // 210.96°
        CHECK((geom::Utils::PolarAngle(a, h) - (3 * PI / 2)) < ERROR_ACCURACY); // 270°
        CHECK((geom::Utils::PolarAngle(a, i) - (329.04 * PI / 180)) < ERROR_ACCURACY); // 329.04°
    }
}

TEST_CASE("Conjunto de pontos é um polígono válido") {
    Vector<geom::Point2D> points;

    points.PushBack(geom::Point2D(5, 2));
    points.PushBack(geom::Point2D(4, 1));
    SUBCASE("Uma reta") {
        CHECK(!geom::Utils::IsPolygon(points));
    }

    points.PushBack(geom::Point2D(6, 3));
    SUBCASE("Três pontos colineares") {
        CHECK(!geom::Utils::IsPolygon(points));
    }

    points.PushBack(geom::Point2D(3, 0));
    SUBCASE("Quatro pontos colineares") {
        CHECK(!geom::Utils::IsPolygon(points));
    }

    points.PushBack(geom::Point2D(2, 1));
    SUBCASE("Um polígono") {
        CHECK(geom::Utils::IsPolygon(points));
    }
}
