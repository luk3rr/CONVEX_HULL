/*
* Filename: point_2d.h
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef POINT_2D_H_
#define POINT_2D_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <ostream>

namespace geom {
    class Point2D {
        private:
            int m_x, m_y;
            sf::CircleShape m_circle;

        public:
            /**
            @brief Construtor padrão da classe
            */
            Point2D();

            /**
            @brief Overload do construtor da classe
            @param x, y Coordenadas do ponto
            */
            Point2D(int x, int y);

            /**
            @brief Overload do operador ==
            @param point Ponto que será usado na comparação
            @return True se as coordenadas dos dois pontos forem iguais uma a uma, False caso contrário
            */
            bool operator==(const Point2D &point) const;

            /**
            @brief Overload do operador <
            Um ponto A é considerado menor que B quando Ay < By.
            Em caso de empate, A será menor se Ax < Bx.
            @param point Ponto que será usado na comparação
            @return True se o ponto for menor, false caso contrário
            */
            bool operator<(const Point2D &point) const;

            /**
            @brief Overload do operador <=
            @param point Ponto que será usado na comparação
            @return True se o ponto for menor ou igual, false caso contrário
            */
            bool operator<=(const Point2D &point) const;

            /**
            @brief Overload do operador <<
            @param os Stream de saída
            @point point Ponto que será impresso
            */
            friend std::ostream &operator<<(std::ostream &os, const Point2D &point);

            /**
            @brief Define um novo valor para a coordenada X
            @param x Novo valor da coordenada X
            */
            void SetX(int x);

            /**
            @brief Define um novo valor para a coordenada Y
            @param y Novo valor da coordenada Y
            */
            void SetY(int y);

            /**
            @brief Pega o valor da coordenada X
            @return Valor da coordenada X
            */
            int GetX();

            /**
            @brief Pega o valor da coordenada Y
            @return Valor da coordenada Y
            */
            int GetY();

            /**
            @brief Pega a posição vetorial do ponto
            @return Posição vetorial do ponto
            */
            sf::Vector2f GetPosition();

            /**
            @brief Renderiza o ponto na tela
            @param window Tela na qual o ponto será renderizado
            @param color Cor que será utilizada na renderização do ponto
            */
            void Draw(sf::RenderWindow &window, sf::Color color);
    };
}

#endif // POINT_2D_H_
