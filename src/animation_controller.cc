/*
* Filename: animation_controller.cc
* Created on: June 10, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "animation_controller.h"
#include "convex_hull.h" // Adicionado aqui devido ao problema de dependência circular

AnimationController::AnimationController() {
    this->m_screen = sf::Vector2i(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    this->m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Fecho Convexo");
}

AnimationController::~AnimationController() {
    delete this->m_window;
}

void AnimationController::RenderCartesianPlane() {
    double originX = WINDOW_SIZE_Y / 2.f;
    double originY = WINDOW_SIZE_X / 2.f;
    double axisThickness = 1.2;

    sf::RectangleShape xAxis(sf::Vector2f(WINDOW_SIZE_X, axisThickness));
    xAxis.setPosition(0, originX);
    xAxis.setFillColor(CARTESIAN_AXIS_COLOR);
    this->m_window->draw(xAxis);

    sf::RectangleShape yAxis(sf::Vector2f(axisThickness, WINDOW_SIZE_Y));
    yAxis.setPosition(originY, 0);
    yAxis.setFillColor(CARTESIAN_AXIS_COLOR);
    this->m_window->draw(yAxis);
}

void AnimationController::Refresh(Vector<geom::Point2D> &points) {
    this->m_window->clear(BACKGROUND_COLOR);
    this->RenderCartesianPlane();

    for (unsigned int i = 0; i < points.Size(); i++) {
        points[i].Draw(*this->m_window, POINT_COLOR);
    }

    this->m_window->display();
}

void AnimationController::Refresh(Vector<geom::Point2D> &points, Vector<geom::Point2D> &convex) {
    this->m_window->clear(BACKGROUND_COLOR);

    for (unsigned int i = 0; i < points.Size(); i++) {
        points[i].Draw(*this->m_window, POINT_COLOR);
    }

    if (convex.Size() > 2) {
        for (unsigned int i = 0; i < convex.Size() - 1; i++) {
            geom::Line2D line(convex[i], convex[i + 1]);
            line.Draw(*this->m_window, LINE_COLOR);
        }
    }

    this->m_window->display();
    sf::sleep(sf::seconds(1.f / points.Size()));

    // Quando o fecho estiver completo, a animação permanece por alguns segundos a mais
    if (convex[0] == convex[convex.Size() - 1]) {
        sf::sleep(sf::seconds(1.5));
    }
}

void AnimationController::Refresh(Vector<geom::Point2D> &points, Vector<geom::Point2D> &convex, geom::Point2D &currentPoint) {
    this->m_window->clear(BACKGROUND_COLOR);

    for (unsigned int i = 0; i < points.Size(); i++) {
        points[i].Draw(*this->m_window, POINT_COLOR);
    }

    if (convex.Size() > 2) {
        for (unsigned int i = 0; i < convex.Size() - 1; i++) {
            geom::Line2D line(convex[i], convex[i + 1]);
            line.Draw(*this->m_window, LINE_COLOR);
        }
    }
    geom::Line2D line(convex[convex.Size() - 1], currentPoint);
    line.Draw(*this->m_window, LINE_COLOR_TMP);

    this->m_window->display();
    sf::sleep(sf::seconds(1.f / points.Size()));
}

void AnimationController::Start(Vector<geom::Point2D> &points) {
    Vector<geom::Point2D> convex;

    this->m_window->create(sf::VideoMode(this->m_screen.x, this->m_screen.y), "Fecho Convexo", sf::Style::Close);
    this->m_window->setFramerateLimit(60);

    sf::View view(sf::Vector2f(this->m_screen.x / 2.0f, this->m_screen.y / 2.0f), sf::Vector2f(this->m_screen.x, this->m_screen.y));
    const float zoomAmount = 1.2f;

    bool mouseIsDragging = false;
    sf::Vector2f lastMousePos;

    while (this->m_window->isOpen()) {
        sf::Event event;

        while (this->m_window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    this->m_window->close();
                    break;

                case sf::Event::MouseWheelScrolled:
                    if (event.mouseWheelScroll.delta >= 1)
                        view.zoom(1.f / zoomAmount);

                    if (event.mouseWheelScroll.delta <= -1)
                        view.zoom(zoomAmount);
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (mouseIsDragging)
                            mouseIsDragging = false;
                        else
                            mouseIsDragging = true;

                        lastMousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    }

                    break;

                case sf::Event::MouseMoved:
                    if (mouseIsDragging) {
                        sf::Vector2f currentMousePos(event.mouseMove.x, event.mouseMove.y);
                        sf::Vector2f delta = currentMousePos - lastMousePos;

                        view.move(-delta);
                        this->m_window->setView(view);

                        lastMousePos = currentMousePos;
                    }
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::J) {
                        geom::ConvexHull::JarvisMarch(points, convex, *this);
                    }
                    if (event.key.code == sf::Keyboard::G) {
                        geom::ConvexHull::GrahamScan(points, convex, geom::Utils::MergeSort, *this);
                    }
                    if (event.key.code == sf::Keyboard::Q) {
                        this->m_window->close();
                    }

                case sf::Event::Resized:
                case sf::Event::LostFocus:
                case sf::Event::GainedFocus:
                case sf::Event::TextEntered:
                case sf::Event::KeyReleased:
                case sf::Event::MouseWheelMoved:
                case sf::Event::MouseButtonReleased:
                case sf::Event::MouseEntered:
                case sf::Event::MouseLeft:
                case sf::Event::JoystickButtonPressed:
                case sf::Event::JoystickButtonReleased:
                case sf::Event::JoystickMoved:
                case sf::Event::JoystickConnected:
                case sf::Event::JoystickDisconnected:
                case sf::Event::TouchBegan:
                case sf::Event::TouchMoved:
                case sf::Event::TouchEnded:
                case sf::Event::SensorChanged:
                case sf::Event::Count:
                    break;
            }
        }
        this->m_window->setView(view);
        this->Refresh(points);
    }
}
