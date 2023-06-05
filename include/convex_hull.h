/*
* Filename: convex_hull.h
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef CONVEX_HULL_H_
#define CONVEX_HULL_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>

#include "animation_controller.h"
#include "point_2d.h"
#include "vector.h"
#include "geometry_utils.h"
#include "line_2d.h"

namespace geom {
    class ConvexHull {
        public:
            /**
            @brief Utiliza o algoritmo Graham Scan para encontrar o fecho convexo de um conjunto de pontos
            @param points Conjunto de pontos no qual se buscará o fecho convexo
            @param convex Conjunto ordenado de pontos que forma o fecho convexo
            @param SortFunc Função de ordenação que será utilizada
            */
            static void GrahamScan(Vector<Point2D> &points, Vector<Point2D> &convex, void (*SortFunc)(Vector<Point2D> &));

            /**
            @brief Utiliza o algoritmo Graham Scan para encontrar o fecho convexo de um conjunto de pontos e renderiza a animação na tela
            @param points Conjunto de pontos no qual se buscará o fecho convexo
            @param convex Conjunto ordenado de pontos que forma o fecho convexo
            @param SortFunc Função de ordenação que será utilizada
            @param anim Instância da classe AnimationController que será utilizada para controlar a animação
            */
            static void GrahamScan(Vector<Point2D> &points, Vector<Point2D> &convex, void (*SortFunc)(Vector<Point2D> &), AnimationController &anim);

            /**
            @brief Utiliza o algoritmo Marcha de Jarvis para encontrar o fecho convexo de um conjunto de pontos
            @param points Conjunto de pontos no qual se buscará o fecho convexo
            @param convex Conjunto ordenado de pontos que forma o fecho convexo
            */
            static void JarvisMarch(Vector<Point2D> &points, Vector<Point2D> &convex);

            /**
            @brief Utiliza o algoritmo Marcha de Jarvis para encontrar o fecho convexo de um conjunto de pontos
            @param points Conjunto de pontos no qual se buscará o fecho convexo
            @param convex Conjunto ordenado de pontos que forma o fecho convexo
            @param anim Instância da classe AnimationController que será utilizada para controlar a animação
            */
            static void JarvisMarch(Vector<Point2D> &points, Vector<Point2D> &convex, AnimationController &anim);
    };
} // geometry namespace

#endif // CONVEX_HULL_H_
