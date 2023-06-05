/*
* Filename: line_2d.h
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef LINE_2D_H_
#define LINE_2D_H_

#include <SFML/Graphics.hpp>

#include "point_2d.h"

namespace geom {
    class Line2D {
        private:
            Point2D m_a, m_b;

        public:
            /**
            @brief Construtor padrão da classe
            */
            Line2D();

            /**
            @brief Overload do construtor da classe
            @param a, b Os dois pontos que definem a reta
            */
            Line2D(Point2D a, Point2D b);

            /**
            @brief Overload do construtor da classe
            @param ax, ay Coordenadas do ponto A
            @param bx, by Coordenadas do ponto B
            */
            Line2D(int ax, int ay, int bx, int by);

            /**
            @brief Overload do operador ==
            @param line Reta que será usado na comparação
            @return True se as retas forem a mesma, False caso contrário
            */
            bool operator==(const Line2D &line) const;

            /**
            @brief Define um valor para o ponto A
            @param a Novo valor do ponto
            */
            void SetA(Point2D a);

            /**
            @brief Define um valor para o ponto B
            @param b Novo valor do ponto
            */
            void SetB(Point2D b);

            /**
            @brief Pega o valor do ponto A
            @return O ponto A
            */
            Point2D GetA();

            /**
            @brief Pega o valor do ponto B
            @return O ponto B
            */
            Point2D GetB();

            /**
            @brief Renderiza a linha na tela
            @param window Tela na qual a linha será renderizado
            @param color Cor que será utilizada na renderização da linha
            */
            void Draw(sf::RenderWindow &window, sf::Color color);
    };
}

#endif // LINE_H_
