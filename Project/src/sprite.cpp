#include "sprite.h"

Sprite::Sprite() {
  m_scale.x = 1.0f;
  m_scale.y = 1.0f;
  m_scale.z = 1.0f;

  m_color = Color(255, 255, 255, 255);

  m_texture_width = 1024;
  m_texture_height = 1024;
  m_texture = (uint8_t*)malloc(m_texture_width * m_texture_height * 4);

  glGenTextures(1, &m_opengl_data.m_texture_id);
  glBindTexture(GL_TEXTURE_2D, m_opengl_data.m_texture_id);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_texture_width, m_texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_texture);
  glBindTexture(GL_TEXTURE_2D, 0);
}

Sprite::~Sprite() {
  if (m_texture != nullptr) {
    free(m_texture);
  }
}

Color Sprite::getColor() const {
  return m_color;
}

Vec3 Sprite::getPosition() const {
  return m_position;
}

Vec3 Sprite::getScale() const {
  return m_scale;
}

uint32_t Sprite::getTextureHandler() const {
  return m_opengl_data.m_texture_id;
}

void Sprite::setColor(const Color &color) {
  m_color = color;
}

void Sprite::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  m_color.r = r;
  m_color.g = g;
  m_color.b = b;
  m_color.a = a;
}

void Sprite::setPosition(const Vec3 &position) {
  m_position = position;
}

void Sprite::setPosition(float x, float y, float z) {
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
}

void Sprite::setPositionX(float x) {
  m_position.x = x;
}

void Sprite::setPositionY(float y) {
  m_position.y = y;
}

void Sprite::setPositionZ(float z) {
  m_position.z = z;
};

void Sprite::setScale(const Vec3 &scale) {
  m_scale = scale;
}

void Sprite::setScale(float x, float y, float z) {
  m_scale.x = x;
  m_scale.y = y;
  m_scale.z = z;
}

void Sprite::setScaleX(float x) {
  m_scale.x = x;
}

void Sprite::setScaleY(float y) {
  m_scale.y = y;
}

void Sprite::setScaleZ(float z) {
  m_scale.z = z;
}

void Sprite::setTextureData(uint8_t* data) {
  m_texture = data;
  glBindTexture(GL_TEXTURE_2D, m_opengl_data.m_texture_id);
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0,
    m_texture_width, m_texture_height, GL_RGBA, GL_UNSIGNED_BYTE, m_texture);
  glBindTexture(GL_TEXTURE_2D, 0);
}

uint8_t* Sprite::getTextureData() {
  return m_texture;
}

uint32_t Sprite::getTextureWidth() const {
  return m_texture_width;
}

uint32_t Sprite::getTextureHeight() const {
  return m_texture_height;
}

void Sprite::update(float dt) {
    
}