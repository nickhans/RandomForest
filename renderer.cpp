#include "renderer.hpp"

Renderer::Renderer() {
  std::uniform_real_distribution<float> x_dist(-20, 20);
  std::uniform_real_distribution<float> z_dist(-20, 20);
  std::uniform_real_distribution<float> h_dist(5.0, 8.0);
  std::uniform_real_distribution<float> w_dist(0.5, 1.0);
  std::uniform_real_distribution<int> l_dist(8, 15);
  // for (int i = 0; i < 20; i++) {
  //   trees.push_back(new Tree(x_dist(rng), 0, z_dist(rng), h_dist(rng),
  //                            w_dist(rng), 15, l_dist(rng)));
  // }
  trees.push_back(new Tree(0, 0, 0, h_dist(rng), w_dist(rng), 15, l_dist(rng)));
  std::cout << "Tree Count: " << trees.size() << std::endl;
}

Renderer::~Renderer() {
  for (Tree* tree : trees) {
    delete tree;
  }
  std::cout << "RENDERER DESTRUCTOR" << std::endl;
}

void Renderer::render_scene() {
  // do something

  // std::cout << "RENDER: " << tree.limbs.length << std::endl;
  for (Tree* tree : trees) {
    tree->render();
  }
  render_axis();
}

void Renderer::render_axis() {
  glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(20.0, 0.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(0.0, 20.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(0.0, 0.0, 20.0);
  glEnd();
}
