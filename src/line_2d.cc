/*
* Filename: line_2d.cc
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "line_2d.h"

namespace geom {
    Line2D::Line2D(Point2D a, Point2D b) {
        this->m_a = a;
        this->m_b = b;
    }

    Line2D::Line2D(int ax, int ay, int bx, int by) {
        this->m_a = Point2D(ax, ay);
        this->m_b = Point2D(bx, by);
    }

    bool Line2D::operator==(const Line2D &line) const {
        return (this->m_a == line.m_a and this->m_b == line.m_b);
    }

    void Line2D::SetA(Point2D a) {
        this->m_a = a;
    }

    void Line2D::SetB(Point2D b) {
        this->m_b = b;
    }

    Point2D Line2D::GetA() {
        return this->m_a;
    }

    Point2D Line2D::GetB() {
        return this->m_b;
    }

    void Line2D::Draw(sf::RenderWindow &window, sf::Color color) {
        sf::Vertex line[] = {
            sf::Vertex(this->GetA().GetPosition(), color),
            sf::Vertex(this->GetB().GetPosition(), color)
        };

        window.draw(line, 2, sf::Lines);
    }
}
