#include "renderer.hpp"

Renderer::Renderer() {
  std::uniform_real_distribution<float> x_dist(-28.0f, 28.0f);
  std::uniform_real_distribution<float> z_dist(-28.0f, 28.0f);
  std::uniform_real_distribution<float> h_dist(5.0f, 8.0f);
  std::uniform_real_distribution<float> w_dist(0.5f, 1.0f);
  std::uniform_int_distribution<int> l_dist(8, 15);

  terrain = new Terrain();

  for (int i = 0; i < 100; i++) {
    trees.push_back(new Tree(x_dist(rng), 0.0f, z_dist(rng), h_dist(rng),
                             w_dist(rng), 15, l_dist(rng)));
  }
  // trees.push_back(new Tree(0, 0, 0, h_dist(rng), w_dist(rng), 15,
  // l_dist(rng)));
  std::cout << "Tree Count: " << trees.size() << std::endl;
}

Renderer::~Renderer() {
  delete terrain;

  for (Tree* tree : trees) {
    delete tree;
  }
  std::cout << "RENDERER DESTRUCTOR" << std::endl;
}

void Renderer::render_scene() {
  // do something
  terrain->render();

  for (Tree* tree : trees) {
    tree->render();
  }
  // render_axis();
}

void Renderer::render_axis() {
  glBegin(GL_LINES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(20.0, 0.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(0.0, 20.0, 0.0);
  glVertex3d(0.0, 0.0, 0.0);
  glVertex3d(0.0, 0.0, 20.0);
  glEnd();
}
