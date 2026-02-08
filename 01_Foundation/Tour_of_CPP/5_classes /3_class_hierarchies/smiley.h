#ifndef HIERARCHY_SMILEY_H_
#define HIERARCHY_SMILEY_H_

#include "circle.h"
#include "shape.h"
#include <memory>
#include <vector>

namespace hierarchy {

class Smiley : public Circle {
public:
  Smiley(const Point &point, double radius) : Circle(point, radius) {
    // Calculate relative positions for eyes
    double offset_x = radius * 0.4;
    double offset_y = radius * 0.3;
    double eye_radius = radius * 0.1;

    // Left eye
    Point left_pos({center()[0] - offset_x, center()[1] + offset_y});
    eyes_.push_back(std::make_unique<Circle>(left_pos, eye_radius));

    // Right eye
    Point right_pos({center()[0] + offset_x, center()[1] + offset_y});
    eyes_.push_back(std::make_unique<Circle>(right_pos, eye_radius));

    // Mouth
    Point mouth_pos({center()[0], center()[1] - offset_y});
    mouth_ = std::make_unique<Circle>(mouth_pos, radius * 0.25);
  }

  ~Smiley() = default;

  void draw() const override {
    // Face
    Circle::draw();

    // Eyes
    for (const auto &eye : eyes_) {
      eye->draw();
    }

    // Mouth
    if (mouth_) {
      mouth_->draw();
    }
  }

  void move(const Point &to) override {
    Point old_center = this->center();

    // Calculate delta
    double dx = to[0] - old_center[0];
    double dy = to[1] - old_center[1];

    // Move face
    Circle::move(to);

    // Move eyes
    for (auto &eye : eyes_) {
      Point old_center = eye->center();
      Point new_center({old_center[0] + dx, old_center[1] + dy});

      eye->move(new_center);
    }

    // Move mouth
    if (mouth_) {
      Point old_center = mouth_->center();
      Point new_center({old_center[0] + dx, old_center[1] + dy});

      mouth_->move(new_center);
    }
  }

  void rotate(int angle) override;

private:
  std::vector<std::unique_ptr<Shape>> eyes_;
  std::unique_ptr<Shape> mouth_;
};

} // namespace hierarchy

#endif