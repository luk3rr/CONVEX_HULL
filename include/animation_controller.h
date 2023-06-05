/*
* Filename: animation_controller.h
* Created on: June 10, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef ANIMATION_CONTROLLER_H_
#define ANIMATION_CONTROLLER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "vector.h"
#include "point_2d.h"
#include "line_2d.h"

const int WINDOW_SIZE_X = 1200;
const int WINDOW_SIZE_Y = 1000;
const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const sf::Color POINT_COLOR = sf::Color::Magenta;
const sf::Color LINE_COLOR = sf::Color::White;
const sf::Color LINE_COLOR_TMP = sf::Color::Red;
const sf::Color CARTESIAN_AXIS_COLOR = sf::Color::White;

class AnimationController {
    private:
        sf::Vector2i m_screen;
        sf::RenderWindow *m_window;

    public:
        AnimationController();

        ~AnimationController();

        /**
        @brief Renderiza o plano cartesiano na tela
        */
        void RenderCartesianPlane();

        /**
        @brief Renderiza os pontos no vetor na tela
        @param points Vector de pontos que serão renderizados
        */
        void Refresh(Vector<geom::Point2D> &points);

        /**
        @brief Renderiza os pontos no vetor na tela e as linhas formadas pelo conjunto de pontos em convex
        @param points Vector de pontos que serão renderizados
        @param convex Vector de pontos que formam as linhas do fecho convexo
        */
        void Refresh(Vector<geom::Point2D> &points, Vector<geom::Point2D> &convex);

        /**
        @brief Renderiza os pontos no vetor na tela e as linhas formadas pelo conjunto de pontos em convex
        @param points Vector de pontos que serão renderizados
        @param convex Vector de pontos que formam as linhas do fecho convexo
        @param currentPoint Ponto adicional que formará a linha convex[last element]-currentPoint
        */
        void Refresh(Vector<geom::Point2D> &points, Vector<geom::Point2D> &convex, geom::Point2D &currentPoint);

        /**
        @brief Inicia a execução da animação
        @param points Vector de pontos que serão renderizados e utilizados nas demais etapas da animação
        */
        void Start(Vector<geom::Point2D> &points);
};

#endif // ANIMATION_CONTROLLER_H_
